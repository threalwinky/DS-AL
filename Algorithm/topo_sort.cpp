#include<bits/stdc++.h>

int n, m;
std::vector<int> v[100001], topo;
bool visited[100001];
void dfs(int u){
    visited[u] = 1;
    for (int x : v[u]){
        if (!visited[x]){
            dfs(x);
        }
    }
    topo.push_back(u);
}


int main(){
    std::cin>>n>>m;
    for (int i = 1; i<= m; i++){
        int x, y;
        std::cin>>x>>y;
        v[x].push_back(y);
    }
    for (int i = 1; i<=n; i++){
        if (!visited[i]) dfs(i);
    }
    for (int i = n - 1; i>=0; i--){
        std::cout<<topo[i]<<" ";
    }
}
