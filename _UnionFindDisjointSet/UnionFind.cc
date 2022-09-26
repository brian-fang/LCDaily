#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
private:
    vector<int> group;
    vector<int> rank;
public:
    UnionFind(int sz): group(vector<int>(sz)), rank(vector<int>(sz)) {
        iota(group.begin(), group.end(), 0); // group[e] = e
    }
    
    int find(int cur) {
        if(cur != group[cur]) group[cur] = find(group[cur]);
        return group[cur];
    }
    
    bool unite(int a, int b) {
        int gra = find(a), grb = find(b);
        
        if(gra == grb) return false;
        
        // Designate "gra" as larger group:
        if(rank[gra] < rank[grb]) swap(gra, grb);
        group[grb] = gra;
        if(rank[gra] == rank[grb]) rank[gra]++;
        
        return true;
    }
};
