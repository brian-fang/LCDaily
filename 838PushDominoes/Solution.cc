#include <vector>
#include <string>
#include <iostream>
using namespace std;

string push_dominoes(string dominoes) {
    vector<char> lean;
    vector<int> idx;
    string result;
    auto push = [&](char l, int i) {
        lean.push_back(l);
        idx.push_back(i);
    };
    
    push('L', -1);
    for(int i = 0; i < dominoes.size(); i++)
        if(dominoes[i] != '.')
            push(dominoes[i], i);
    push('R', dominoes.size());
    
    int sz = idx.size();
    for(int i = 1; i < sz; i++) {
        char cur = lean[i], last = lean[i-1];
        int between = idx[i] - idx[i - 1] - 1;
        
        if(cur == last) result += string(between, cur);
        else if(last == 'R') { // R ... L
            result += string(between / 2, 'R');
            if(between % 2) result += '.';
            result += string(between / 2, 'L');
        }
        else result += string(between, '.');
        
        if(i < sz - 1) result += cur;
    }
    
    return result;
}

int main(int argc, char* argv[]) {
    
    cout << push_dominoes(string(argv[1])) << endl;
    
}
