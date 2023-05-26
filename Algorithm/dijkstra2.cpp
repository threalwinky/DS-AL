#include<bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;
const int maxN = 1e6 + 9;

struct Edge{
    int v, w;
    Edge(int _v, int _w){ v=_v; w=_w; }
};

struct Node{
    int u;
    int D_u;
    bool operator < (const Node b) const {
        return this->D_u > b.D_u;
    }
};

vector<Edge> edges[maxN];
vector<int> D(maxN, inf);
vector<int> P(maxN, 0);
vector<int> trace(maxN, -1);

void dijkstra(int n, int S) {
    D[S] = 0;
    priority_queue<Node> pq;
    pq.push({S, 0});
    while(!pq.empty()) {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if(P[u] == true)
            continue;
        P[u] = true;
        for(auto e : edges[u]) {
            int v = e.v;
            long long w = e.w; 
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pq.push({v, D[v]});
                trace[v] = u;
            }
        }
    }
    for (auto x : D) cout << x << " ";
}


int main(){
    freopen("sample.inp", "r", stdin);
    freopen("sample.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    dijkstra(n, 1);
}
