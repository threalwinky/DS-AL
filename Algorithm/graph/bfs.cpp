#include<bits/stdc++.h>
using namespace std;
vector<int> v[100001];
bool check[100001];
void bfs(int u){
    check[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        cout<<tmp<<" ";
        for (auto x:v[tmp]){
            if (!check[x]){
                q.push(x);
                check[x] = 1;
            }
        }
    }
}
int main(){
    freopen("sample.cpp", "r", stdin);
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
}
