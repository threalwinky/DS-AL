#include<iostream>
using namespace std;
int a[1001][1001];
int main(){
    int m, n, k;
    cin>>m>>n>>k;
    for (int i = 1; i<=k; i++){
        int x, y;
        cin>>x>>y;
        a[y][x] = 1;
    }
    for (int i = 1; i<=m; i++){
        for (int j = 1; j<=n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
