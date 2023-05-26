#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
const int inf = INT_MAX;


struct Edge{
    int v; long long w;
    Edge(int _v, long long _w){ v = _v; w = _w; }
};

vector<Edge> edges[maxN];
vector<int> D(maxN + 9, inf);
vector<bool> P(maxN + 9, 0);
void di(int n, int s){
    D[s] = 0;
    for (int i = 0; i<n; i++){
        int sB;
        int Max = inf;
        for (int i=0; i<n; i++){
            if (D[i] < Max && P[i] == 0){
                sB = i;
                Max = D[i];
            }
        }
        int u = sB;
        P[u] = 1;
        for (auto x:edges[u]){
            int vv = x.v;
            int w = x.w;
            if (D[vv] > D[u] + w){
                D[vv] = D[u] + w;
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
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
    }
    di(n, 1);
    cout<<D[4];
}
