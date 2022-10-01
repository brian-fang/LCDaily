
#include <string>
#include <iostream>
using namespace std;

int num_decodings(string s) {

    auto verify = [&s](int i, int j) -> bool {
        if(i == j) return s[i] != '0';
        return (s[i] == '1') || (s[i] == '2' && s[j] < '7');
    };
        
    int n = s.length();
    int twoback = verify(0, 0);
    if(n < 2) return twoback;
    int oneback = verify(0, 1) + (verify(1, 1) ? twoback : 0);
    if(n < 3) return oneback;
        
        
    int res = 0;
    for(int i = 2; i < n; i++) {
        res = 0;
            
        if(verify(i-1,i)) res += twoback;
        if(verify(i,i)) res += oneback;
            
        tie(twoback, oneback) = {oneback, res};
    }
        
    return res;   


}


int main(int argc, char* argv[]) {

    cout << num_decodings(argv[1]) << endl;

}