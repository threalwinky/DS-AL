#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
vector<int> v[maxN];
bool check[maxN];
int parent[maxN];
void bfs(int u){
    check[u] = 1;
    parent[u] = u;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        for (auto x:v[tmp]){
            if (!check[x]){
                q.push(x);
                check[x] = 1;
                parent[x] = tmp;
            }
        }
    }
}
void find_path(int s, int e){
    bfs(s);
    if (!parent[e]){
        cout<<"No way";
        return;
    }
    vector<int> tmp;
    cout<<s<<" ";
    while (e != s){
        tmp.push_back(e);
        e = parent[e];
    }
    for (vector<int>::reverse_iterator it = tmp.rbegin(); it!=tmp.rend(); it++){
        cout<<*(it)<<" ";
    }
}
int main(){
    freopen("sample.inp", "r", stdin);
    int n, m, s, e;
    cin>>n>>m>>s>>e;
    for (int i = 1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        v[y].push_back(x);
        v[x].push_back(y);
    }
    find_path(s, e);
}
