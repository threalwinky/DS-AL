#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct Edge{
    int v;
    int w;
    Edge(int _v, int _w){ v = _v; w = _w; }
};

vector<Edge> v[10001];
vector<int> D(10001, inf);
vector<bool> P(10001, 0);
int cnt = 0;
void dij(int n, int u){
    D[u] = 0;
    for (int i = 0; i<n; i++){
        int uBest;
        int Max = inf;
        for (int i=0; i<n; i++){
            if (D[i] < Max && P[i] == 0){
                uBest = i;
                Max = D[i];
            }
        }
        int u = uBest;
        P[u] = 1;
        for (auto x:v[u]){
            int vv = x.v;
            int w = x.w;
            if (D[vv] == D[u] + w && vv == n){
                cnt++;
            }
            if (D[vv] > D[u] + w){
                D[vv] = D[u] + w;
                cnt=0;
            }
        }
    }
}

int main(){
    freopen("sample.inp", "r", stdin);
    freopen("sample.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++){
        int t, x, y, z;
        cin >> t >> x >> y >> z;
        if (t == 1) 
        v[x].push_back({y, z});
        else{
            v[x].push_back({y, z});
            v[y].push_back({x, z});
        }
    }
    dij(n, 1);
    cout<<D[n]<<" "<<cnt;
}
