#include<bits/stdc++.h>
using namespace std;
ifstream file("bai1.inp");
int m,n,ans = 0;
vector<int> adj[1001];
bool check[1001] = {0};
void nhap(){
    file>>m>>n;
    for (int i = 1; i<=n;i++){
        int x,y;
        file>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u){
    check[u] = 1;
    for (auto v : adj[u]){
        if (!check[v]) dfs(v);
    }
}
void xuly(){
    for (int i = 1; i<=m;i++){
        if (!check[i]){
            dfs(i);
            ans++;
        }
    }
}
void xuat(){
    cout<<ans;
}
int main(){
    nhap();
    xuly();
    xuat();
}