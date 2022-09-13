#include <thread>
#include <future>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


// Sum of squares of n natural numbers  [n(n+1)(2n+1)] / 6
long sum_squares_constant_time(int n) {
    long l = long(n);
    return l * (l + 1) * (2*l + 1) / 6;
}


// returns 1^2 + 2^2 + 3^2 + ... + n^2
long sum_squares(int n) {
    const auto processor_count = thread::hardware_concurrency();

    vector<future<long>> results;

    const int work_per_thread = n / processor_count;

    const auto accum = [](int start, int ct) -> long {
        long res = 0L;
        int i = start;
        while(ct) {
            res += i * i;
            i++; ct--;
        }
        return res;
    };

    for(int i = 0; i < processor_count; i++) {
        
        auto f = async(accum, i * work_per_thread + 1, work_per_thread);

        results.push_back(move(f));

    }

    long result = 0L;

    if(n % processor_count) {
        
        // Probably not worth it to generate an extra future for the remainder since expected core counts are not too high
        result += accum(processor_count * work_per_thread + 1, n % processor_count);

    }


    for(auto& f: results) result += f.get();

    return result;
}




int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);

    cout << sum_squares(n) << endl;

}