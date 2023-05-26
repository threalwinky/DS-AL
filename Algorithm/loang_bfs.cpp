#include<bits/stdc++.h>

int n, m, k, ans = 0;
bool a[1001][1001];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1 ,0};

void loang(int i, int j){
    std::queue<std::pair<int, int>> q;
    int dt = 1;
    q.push({i, j});
    a[i][j] = 0;
    while (!q.empty()){
        std::pair<int, int> tmp = q.front();
        q.pop();
        for (int i = 0; i<4; i++){
            int newx = tmp.first + dx[i];
            int newy = tmp.second + dy[i];
            if (a[newx][newy] == 1 && newx >= 1 && newx <= n && newy >=1 && newy <=m){
               // std::cout<<newx<<" "<<newy<<"\n";
                a[newx][newy] = 0;
                q.push({newx, newy});
                dt++;
            }
        }
    }
    ans = std::max(ans, dt);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin>>m>>n>>k;
    for (int i = 1; i<=k; i++){
        int x, y;
        std::cin>>x>>y;
        a[y][x] = 1;
    }
    for (int i = 1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            if (a[i][j] == 1){
                loang(i, j);
            }
        }
    }
    std::cout<<ans;
}

