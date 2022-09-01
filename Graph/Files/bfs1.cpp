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
    while (!q.empty()){
        if (check[q.front()] == 0){
        cout<<q.front()<<" ";
        for (auto v : adj[q.front()])
            q.push(v);
        }
        check[q.front()] = true;
        q.pop();
    }
}
int main(){
    input();
    bfs(1);
}