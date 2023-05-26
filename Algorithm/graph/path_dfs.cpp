
#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
vector<int> v[maxN];
bool check[maxN];
int parent[maxN];

void dfs(int u){
    check[u] = 1;
    for (auto x:v[u]){
        if (!check[x]){
            dfs(x);
            check[x] = 1;
            parent[x] = u;
        }
    }
}

void find_path(int s, int e){
    dfs(s);
    parent[s] = s;
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
