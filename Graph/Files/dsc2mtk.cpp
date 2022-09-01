#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[200][200], e,v;
    ifstream file("dt.inp");
    file>>n>>m;
    for (int i = 1; i<=m;i++){
        file>>e>>v;
        a[e][v] = 1;
        a[v][e] = 1;
    }
    for (int i = 1; i<=n;i++){
        for (int j = 1;j <= n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}