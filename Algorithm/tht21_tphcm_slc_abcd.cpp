#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 1e6+9, mod = 1e9+7;
const int maxNN = 4*maxN;
int a[maxN], b[maxN], c[maxN], d[maxN];
int st1[maxNN], st2[maxNN], st3[maxNN], st4[maxNN];
void build(int o[], int st[], int id, int l, int r){
    if (l == r){
        st[id] = o[l];
        return;
    }
    int m = l + (r - l)/2;
    build(o, st, id*2, l, m);
    build(o, st, id*2+1, m+1, r);
    st[id] = 
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i = 1; i<=n; i++){
        cin>>a[i];
        b[i] = b[i - 1] + a[i];
        c[i] = c[i - 1] + b[i];
        d[i] = d[i - 1] + c[i];
    }
    for (int i = 1; i<=n; i++){
        cout<<d[i]<<" ";
    }
    build(a, st1, 1, 1, n);

}
