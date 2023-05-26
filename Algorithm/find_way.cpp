#include<bits/stdc++.h>

std::vector<int> v[10001];
bool visited[10001];
int parent[10001];

void dfs(int u){
    visited[u] = true;
    for (auto x : v[u]){
        if (!visited[x]){
            parent[x] = u;
            dfs(x);
        }
    }
}

void find_way(int s, int e){
    parent[s] = -1;
    dfs(s);
    if (parent[e] == 0){
        std::cout<<"Ain't no way";
    }
    else {
        std::stack<int> st;
        while (e != -1){
            st.push(e);
            e = parent[e];
        }
        while (!st.empty()){
            std::cout<<st.top()<<" ";
            st.pop();
        }
    }
}

int main(){
    int n, m;
    int s, e;
    std::cin>>n>>m>>s>>e;
    for (int i = 1; i<=m; i++){
        int x, y;
        std::cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    find_way(s, e);
}
