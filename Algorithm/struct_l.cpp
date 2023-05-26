#include<bits/stdc++.h>
using namespace std;
struct Dsu{
    vector<int> par;
    void init(int n){
        par.resize(n + 5, 0);
        for (int i=1; i<=n; i++){
            par[i] = i;
        }
    }
    int find(int u){
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v){
        u = find(u);
        if (u == v) return false;
        par[v]= u;
        return true;
    }
};
int main(){
    Dsu dsu;    
    dsu.init(5);
    dsu.join(2, 3);
    cout<<dsu.find(2)<<dsu.find(3);
}
