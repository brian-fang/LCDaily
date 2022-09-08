#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

// RETURNS the inorder traversal (values) of the tree with root 'node'
vector<int> inorder(TreeNode* node) {
    if(!node) return {};
    
    stack<TreeNode*> stk;
    TreeNode* cur = node;
    vector<int> result;
    
    while(cur || !stk.empty()) {
        // dig left - we will process the furthest left elements first, so
        // we push them last
        while(cur) {
            stk.push(cur);
            cur = cur->left;
        }
        
        // obtain the node to be processed
        cur = stk.top(); stk.pop();
        result.push_back(node->val); // process node
        
        // prepare right subtree to be processed
        cur = cur->right;
    }
    
    return result;
}


int main(int argc, char* argv[]) {
    return 0;
}
