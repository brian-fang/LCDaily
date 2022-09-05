#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};
    
    queue<Node*> qu;
    vector<vector<int>> result;
    
    qu.push(root);
    
    int sz;
    while(sz = qu.size()) {
        vector<int> lvl; lvl.reserve(sz);
        
        for(int i = 0; i < sz; i++) {
            Node* n = qu.front(); qu.pop();
            lvl.push_back(n->val);
            for(Node* ch: n->children) qu.push(ch);
        }
        
        result.push_back(lvl);
    }
    
    return result;
}

int main(int argc, char* argv[]) {
}
