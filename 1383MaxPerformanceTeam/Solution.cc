#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
 
 For each member, consider if it were the least efficient member of a team

 
 
 */

int max_perf(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    const int MOD = (int)1e9 + 7;
    
    // Initialize vector of choices
    // Sort by efficiency DESCENDING
    vector<tuple<int, int>> engineers;
    for(int i = 0; i < n; i++) engineers.push_back({efficiency[i], speed[i]});
    sort(engineers.begin(), engineers.end(), [](const auto& e1, const auto& e2) {
        return get<0>(e1) > get<0>(e2);
    });
    
    // Initialize priority queue of speeds
    // Should kick out the smallest speed if need be ... this is a max queue
    //
    auto cmp = [](int s1, int s2) {
        return s1 > s2;
    };
    priority_queue<int, vector<int>, decltype(cmp)> speeds(cmp);
    
    long speedsum = 0L; // Sum of the current speeds in the current group
    long res = 0L;
    
    for(const auto& e: engineers) {
        int eff = get<0>(e), spe = get<1>(e);
        
        speeds.push(spe);
        speedsum += spe;
        
        if(speeds.size() > k) {speedsum -= speeds.top(); speeds.pop(); }
        
        res = max(res, eff * speedsum);
    }
    
    return res % MOD;
    
    
}



int main(int argc, char* argv[]) {

}
