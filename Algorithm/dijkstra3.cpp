#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxN = 1e6 + 9;

struct Edge{
    int v, w;
    Edge(int _v, int _w){ v=_v; w=_w; }
};

struct Node{
    int u, D_u;
    Node(int _u, int _D_u){ u=_u;D_u=_D_u; }
    bool operator < (const Node b) const{
        return this->D_u > b.D_u;
    }
};

vector<Edge> edges[maxN];
vector<int> D(maxN, inf);
vector<int> P(maxN, 0);
vector<int> par(maxN, -1);

void dijkstra(int n, int S){
    D[S] = 0;
    priority_queue<Node> pq;
    pq.push({S, 0});
    while (!pq.empty()){
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (P[u] == 1) continue;
        P[u] = 1;
        for (auto x : edges[u]){
            int v = x.v;
            int w = x.w;
            if (D[v] > D[u] + w){
                D[v] = D[u] + w;
                par[v] = u;
                pq.push({v, D[v]});
            }
        }
    }
    //for (auto x : par) cout << x << " ";
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
    if (par[n] == -1){ cout << -1; }
    else{
        stack<int> st;
        int tmp = n;
        while (tmp != -1){
            st.push(tmp);
            tmp = par[tmp];
        }
        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
}
