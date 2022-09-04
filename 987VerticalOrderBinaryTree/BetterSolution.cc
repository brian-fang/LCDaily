#include <map>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

// the goal is to have a series of buckets, each corresponding to a column and sorted appropriately
// ordered first by column, then by row, then by value (multiset is sorted)
map<int, map<int, multiset<int>>> tmap;

void dfs(TreeNode* node, int c, int r) {
    if(!node) return;
    tmap[c][r].insert(node->val);
    dfs(node->left, c - 1, r + 1);
    dfs(node->right, c + 1, r + 1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    dfs(root, 0, 0);
    vector<vector<int>> result;
    for(const auto& col: tmap) {
        vector<int> v;
        for(const auto& row: col.second) {
            v.insert(v.end(), row.second.begin(), row.second.end());
        }
        result.push_back(v);
    }
    return result;
}

int main(int argc, char* argv[]) {
    return 0;
}
