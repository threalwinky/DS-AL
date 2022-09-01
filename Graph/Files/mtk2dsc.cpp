#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e,v,m;
    vector<int> adj[199];
    ifstream file("dt.inp");
    file>>n;
    for (int i = 1; i<=n;i++){
        for (int j = 1; j<=n;j++){
            file>>m;
            if (m==1 && i<j) adj[i].push_back(j);
        }
    }
    for (int i = 1; i<=n;i++){
        for (auto j : adj[i])
            cout<<i<<" "<<j<<endl;
    }
}