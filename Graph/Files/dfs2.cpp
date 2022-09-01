#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool check[1001] = {false};
void input(){
    ifstream file("test.inp");
    int m,n;
    file>>m>>n;
    for (int i = 0; i<n; i++){
        int x,y;
        file>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u){
    cout<<u;
    check[u] = true;
    for (auto v : adj[u]){
        if (check[v] == false){
            dfs(v);
        }
    }
}
int main(){
    input();
    dfs(3);
}