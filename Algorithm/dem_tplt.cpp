#include<bits/stdc++.h>
int n, m;
std::vector<int> v[1009];
int a[1009];
bool visited[1009], visited1[1009];
int bfs(int u){
    int cnt = 0;
    std::queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        cnt++;
        for (int x : v[tmp]){
            if (!visited[x]){
                q.push(x);
                visited[x] = 1;
            }
        }
    }
    return cnt;
}
void bfs1(int u){
    std::queue<int> q;
    std::set<int> st;
    q.push(u);
    visited1[u] = 1;
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        st.insert(tmp);
        for (int x : v[tmp]){
            if (!visited1[x]){
                q.push(x);
                visited1[x] = 1;
            }
        }
    }
    for (int x : st) {
        std::cout<<" "<<x;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin>>n>>m;
    for (int i = 1; i<=m; i++){
        int x, y;
        std::cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i<=n; i++){
        if (!visited[i]){
            a[i] = bfs(i);
            ans++;
        }
    }
    std::cout<<ans<<"\n";
    for (int i = 1; i<=n; i++){
        if (!visited1[i]){
            std::cout<<a[i];
            bfs1(i);
            std::cout<<"\n";
        }
    }
}
