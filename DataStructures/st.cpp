#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+9;
int a[maxN], st[maxN * 4], lazy[maxN * 4];
void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int m = l + (r - l)/2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id] = st[id*2] + st[id*2+1];
}
void fix(int id, int l, int r){
    if (!lazy[id]) return;
    st[id] += lazy[id]*(r - l + 1);
    if (l!=r){
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}
void updatePoint(int id, int l, int r, int pos, int val){
    fix(id, l, r);
    if (l > pos || r < pos) return;
    if (l >= pos && r <= pos){
        st[id] += val;
        return;
    }
    int m = l + (r - l)/2;
    updatePoint(id*2, l, m, pos, val);
    updatePoint(id*2+1, m+1, r, pos, val);
    st[id] = st[id*2] + st[id*2+1];
}
void updateRange(int id, int l, int r, int u, int v, int val){
    fix(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v){
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int m = l + (r - l)/2;
    updateRange(id*2, l, m, u, v, val);
    updateRange(id*2+1, m+1, r, u, v, val);
    st[id] = st[id*2] + st[id*2+1];
}
int get(int id, int l, int r, int u, int v){
    fix(id, l, r);
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    int m = l + (r - l)/2;
    int get1 = get(id*2, l, m, u, v);
    int get2 = get(id*2+1, m+1, r, u, v);
    return get1 + get2;
}
int main(){
    int n;
    cin>>n;
    for (int i = 1; i<=n; i++){
        cin>>a[i];
    }
    build(1, 1, n);
    cout<<get(1, 1, n, 1, n)<<"\n";
    for (int i = 1; i<=n; i++){ cout << get(1, 1, n, i, i) << " "; }
    cout<<"\n";
    updateRange(1, 1, n, 2, 4, 5);
    for (int i = 1; i<=n; i++){ cout << get(1, 1, n, i, i) << " "; }
    cout<<"\n";
    cout<<get(1, 1, n, 1, n)<<"\n";
    updatePoint(1, 1, n, 2, 6);
    for (int i = 1; i<=n; i++){ cout << get(1, 1, n, i, i) << " "; }
    cout<<"\n";
    cout<<get(1, 1, n, 1, n)<<"\n";
}
