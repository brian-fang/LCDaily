#include "../_UnionFindDisjointSet/UnionFind.cc"
#include <vector>
#include <iostream>
using namespace std;

bool is_satisfiable(vector<string>& equations) {
    
    const int SZ = 26; // lowercase variable names
    
    UnionFind uf(SZ);

    // Iterate over equalities, building disjoint set
    for(const string& eq: equations) {
        if(eq[1] == '=') {
            int x = eq[0] - 'a', y = eq[3] - 'a';
            uf.unite(x, y);
        }
    }
    
    // Iterate over inequalities
    for(const string& eq: equations) {
        if(eq[1] != '=') {
            int x = eq[0] - 'a', y = eq[3] -  'a';
            if(uf.find(x) == uf.find(y)) return false;
        }
    }
    
    return true;
    
}




int main(int argc, char* argv[]) {
    
    vector<string> equations;
    for(int i = 1; i < argc; i++)
        equations.push_back(string(argv[i]));
    
    cout << is_satisfiable(equations) << endl;
    
}
