#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
private:
    vector<int> group;
    vector<int> rank;
public:
    UnionFind(int sz): group(vector<int>(sz)), rank(vector<int>(sz)) {
        for(int e = 0; e < sz; e++)
            group[e] = e;
    }
    
    int find(int cur) {
        return (group[cur] == cur) ? cur : find(group[cur]);
    }
    
    // Returns whether a divide was eliminated
    bool unite(int a, int b) {
        int gra = find(a), grb = find(b);
        
        if(gra == grb) return false;
        
        // Merge smaller group into larger. Set 'gra' as the larger group
        if(rank[gra] < rank[grb]) swap(gra, grb);
        group[grb] = gra;
        if(rank[gra] == rank[grb]) rank[gra]++;
        
        return true;
    }
};


int earliest(vector<vector<int>>& logs, int n) {
    sort(logs.begin(), logs.end(), [](const auto& v1, const auto& v2) {
        return v1[0] < v2[0];
    });

    UnionFind uf(n);
    
    for(const auto& log: logs) {
        int ts = log[0], a = log[1], b = log[2];
        
        if(uf.unite(a, b)) n--;
        
        if(n == 1) return ts;
    }
    
    return -1;
}




int main(int argc, char* argv[]) {
    vector<vector<int>> logs = {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
    int n = 6;
    
    cout << earliest(logs, n) << endl;
}
