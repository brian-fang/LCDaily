#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
}

int dfs(TreeNode* cur, int maxseen) {
    if(!cur) return 0;
    
    if(cur->val < maxseen) return dfs(cur->left, maxseen) + dfs(cur->right, maxseen);
    
    return 1 + dfs(cur->left, cur->val) + dfs(cur->right, cur->val);
}

int goodNodes(TreeNode* root) {
    // There are no nodes with a value greater than X "above" it == X is greater than the maximum of all nodes seen so far
    return dfs(root, INT_MIN);
}
