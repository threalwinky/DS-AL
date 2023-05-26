#include<bits/stdc++.h>
using namespace std;
int a[10001];
int ft[10001];
int getSum(int p){
    int ans = 0;
    while (p > 0){
        ans += ft[p];
        p -= p&(-p);
    }
    return ans;
}
void update(int pos, int val, int n){
    while (pos <= n){
        ft[pos]+=val;
        pos += pos&(-pos);
    }
    return;
}
int main(){
    freopen("winky.inp", "r", stdin);
    freopen("winky.out", "w", stdout);
    int n;
    cin>>n;
    for (int i = 1; i<=n; i++){
        cin>>a[i];
        update(i, a[i], n);
    }
    for (int i = 1; i<=n; i++) cout<<ft[i]<<" ";
    cout<<"\n";
    cout<<getSum(7);
}
