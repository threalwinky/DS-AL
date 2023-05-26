#include<bits/stdc++.h>
using namespace std;
int a[10001];
int ans = 10000;
void bt(int m, int n, int cnt){
    if (m == 0){
        ans = std::min(ans, cnt);
        return;
    }
    for (int i = 1; i<=n; i++){
        if (m - a[i] >= 0)
        bt(m - a[i], n, cnt + 1);
    }
}
int main(){
    freopen("winky.inp", "r", stdin);
    freopen("winky,out", "w", stdout);
    int n, m;
    std::cin>>n>>m;
    for (int i = 1; i<=n; i++){
        std::cin>>a[i];
    }
    for (int i = 1; i<=n; i++){
        bt(m, n, 1);
    }
    std::cout<<ans;
}
