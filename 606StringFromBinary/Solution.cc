/*
    root has value v
 
    Case 1:
        root is a child node (left and right children are null)
        => return value itself
 
    Case 2:
        left child is null
        
        still must append empty parentheses to maintain mapping
        i.e. v()(...)
    
    Case 2:
        right child is null
        do not have to append the second empty parentheses
        i.e. INSTEAD OF v(...)(), v(...)
 
    Case 4:
        v(...)(...)
 
 */

#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};


string tree2str(TreeNode* root) {
    if(!root) return "";
    
    // Case 1
    if(!root->left && !root->right) return to_string(root->val);
    
    // In cases 2, 3, 4: we all must append the first set of parentheses
    string res = to_string(root->val) + "(" + tree2str(root->left) + ")";
    
    // We have a choice in whether to append the right pair (see Case 2)
    string rightstr = tree2str(root->right);
    if(!rightstr.empty())
        res += "(" + rightstr + ")";
    
    return res;
}

int main(int argc, char* argv[]) {
    
}
