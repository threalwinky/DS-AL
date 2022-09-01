#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool check[1001] = {false};
queue<int> q;
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
void bfs(int u){
    q.push(u);
    check[u] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for (auto x : adj[v]){
            if (!check[x]){
                q.push(x);
                check[x] = true;
            }
        }
    }
}
int main(){
    input();
    bfs(1);
}