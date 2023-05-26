#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001];
bool check[10001];
void dfs(int u){
    check[u] = 1;
    cout<<u<<" ";
    for (auto x:v[u]){
        if (!check[x]){
            check[x] = 1;
            dfs(x);
        }
    }
}
int main(){
    freopen("sample.inp", "r", stdin);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1; i<=n; i++){
        if(!check[i]){
            dfs(i);
            cout<<"\n";
        }
    }
}
