#include <bitset>
#include "../Templates/TreeNode.hh"
using namespace std;

/*
 
At leaf nodes, need to check if the frequencies ('state') correspond to a palindrome
    at most 1 odd frequency
 
Evolve from array of int (representing frequency on path)
 to array of bool
 to bitset
    
 
 For example: 1 -> 2 -> 2 -> 1
 
 freq[1] goes from even (0) to odd(1), then back to even(2)
 alternatively: just record as boolean
 
 
 */


class Solution {
private:
    bitset<10> odd; // if index i set, it's odd, otherwise even
    int res;
    
    bool ck() {
        return odd.count() < 2;
    }
    
    void dfs(TreeNode* node) {
        if(!node) return;
        
        // increment frequency (even to odd and vice versa)
        odd.flip(node->val);
        
        if(!node->left && !node->right) res += ck();
        else {
            dfs(node->left); dfs(node->right);
        }
        
        // reset frequency (even to odd and vice versa)
        odd.flip(node->val);
    }
public:
    int ppp(TreeNode* root) {
        dfs(root);
        return res;
    }
    
};


int main(int argc, char* argv[]) {
    
    // Solution s;
    
    // s.ppp()
    
}







