#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

//
struct TreeNodeWrapper {
    TreeNode* t;
    int r;
    int c;
    
    TreeNodeWrapper(TreeNode* t, int r, int c): t(t), r(r), c(c) {}
};

// used to sort values within the same column
struct TreeNodeLocationWrapper {
    int val;
    int r;
    
    TreeNodeLocationWrapper(int val, int r): val(val), r(r) {}
    
    bool operator<(const TreeNodeLocationWrapper& tnlw) const {
        if(r == tnlw.r) return val < tnlw.val;
        return r < tnlw.r;
    }
};



void mysort(vector<TreeNodeLocationWrapper*>& v) {
        int sz = v.size();
        if(sz < 2) return;
        else if(sz == 2) {
            if(*v[1] < *v[0]) swap(v[0], v[1]);
        }
        else sort(v.begin(), v.end(), [](TreeNodeLocationWrapper* a, TreeNodeLocationWrapper* b) {
            return *a < *b;
        });
    
}

vector<int> vmap(vector<TreeNodeLocationWrapper*>& v) {
        int sz = v.size();
        vector<int> result;
        result.reserve(sz);
        for(int i = 0; i < sz; i++) result.push_back(v[i]->val);
        return result;
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<TreeNodeLocationWrapper*>> tmap;
        queue<TreeNodeWrapper*> qu;
        
        qu.push(new TreeNodeWrapper(root, 0, 0));
        
        while(!qu.empty()) {
            int sz = qu.size();
            for(int i = 0; i < sz; i++) {
                TreeNodeWrapper* tnw = qu.front(); qu.pop();
                int c = tnw->c;
                int r = tnw->r;
                TreeNode* node = tnw->t;
                
                tmap[c].push_back(new TreeNodeLocationWrapper(node->val, r));
                
                if(node->left) qu.push(new TreeNodeWrapper(node->left, r + 1, c - 1));
                if(node->right) qu.push(new TreeNodeWrapper(node->right, r + 1, c + 1));
            }
        }
        
        vector<vector<int>> result;
        result.reserve(tmap.size());
        for(const auto& me: tmap) {
            vector<TreeNodeLocationWrapper*> v = me.second;
            mysort(v);
            result.push_back(vmap(v));
        }
        
        return result;
}

int main(int argc, char *argv[]) {
    return 0;
}
