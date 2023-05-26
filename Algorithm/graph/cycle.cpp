#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];

bool check[10001];
bool dfs(int u, int par){
    check[u] = 1;
    for (auto x: v[u]){
        if (par != x && check[x]) cout<<x<<u<<x<<" ";
        if (!check[x]){
            check[x] = 1;
            dfs(x, u);
        }
    }
}

int main(){
    freopen("sample.inp", "r", stdin);
    freopen("sample.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1; i<=n; i++){
        if (!check[i]){
            dfs(i, 0);
        }
    }
}
