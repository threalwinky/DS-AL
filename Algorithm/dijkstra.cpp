#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxN = 1e6;
struct Edge{
    int v, w;
    Edge(int _v, int _w){ v = _v; w = _w; }
};

vector<Edge> edges[maxN];
vector<int> D, P;
vector<int> trace;
void dijkstra(int n, int S){
    D.resize(n + 9, inf);
    P.resize(n + 9, 0);
    trace.resize(n + 9, 0);
    D[S] = 0;
    for (int i=1; i<=n; i++){
        int uBest;
        int MAX = inf;
        for (int j=1; j<=n; j++){
            if (D[j] < MAX && P[j] == 0){
                MAX = D[j];
                uBest = j;
            }
        }
        P[uBest] = 1;
        for (auto x : edges[uBest]){
            int v = x.v;
            int w = x.w;
            if (D[v] > D[uBest] + w){
                D[v] = D[uBest] + w;
                trace[v] = uBest;
            }
        }
    }
    //for (auto x : D) cout << x << " ";
    //for (auto x : trace) cout << x << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("sample.inp", "r", stdin);
    //freopen("sample.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    dijkstra(n, 1);
    if (trace[n] == 0){ cout << -1; }
    else{
        stack<int> st;
        int tmp = n;
        while (tmp != 0){
            st.push(tmp);
            tmp = trace[tmp];
        }
        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
}
