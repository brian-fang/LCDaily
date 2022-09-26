#include <vector>
#include <optional>
#include <iostream>
using namespace std;


typedef optional<int> Integer;

class Solution {
    vector<int> nums;
    vector<int> multipliers;
    vector<vector<Integer>> cache;
    int N, M;


    /*
    l is # elements chosen on left
    i is # of elements chosen in total
    
    we are choosing the lth element from nums this round
    we either choose from the left, i.e. element l 
    or choose from the right i.e. element N - (i - l) - 1


    */
    int dp(int l, int i) {
        if(i == M) return 0;
        if(cache[l][i].has_value()) return cache[l][i].value();

        int left = dp(l + 1, i + 1) + multipliers[i]*nums[l];
        int right = dp(l, i + 1) + multipliers[i]*nums[N - (i - l) - 1];

        int rv = max(left, right);
        cache[l][i] = rv;
        return rv;
    }


public:

    Solution(vector<int>& nums, vector<int>& multipliers):
        nums(nums), multipliers(multipliers), N(nums.size()), M(multipliers.size()) {
            cache = vector<vector<Integer>>(M, vector<Integer>(N));
        } 


    int maximum_score() {   
        return dp(0, 0);
    }
};




int main(int argc, char* argv[]) {

    /*
        nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
    */

    vector<int> nums {-5,-3,-3,-2,7,1};
    vector<int> multipliers {-10,-5,3,4,6};


    Solution s(nums, multipliers);
    cout << s.maximum_score() << endl;

}