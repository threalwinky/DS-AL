#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("dt.inp");
    int n,m,e,v;
    file>>n>>m;
    vector<int> adj[10];
    for (int i = 0; i<m; i++){
        file>>e>>v;
        adj[e].push_back(v);
        adj[v].push_back(e);   
    }
    for (int i = 1; i<= n;i++){
        cout<<i<<" : ";
        for (int j : adj[i])
            cout<<j<<" ";
        cout<<endl;
    }
}