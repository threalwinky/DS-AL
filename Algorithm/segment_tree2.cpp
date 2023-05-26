#include <bits/stdc++.h>
using namespace std;
const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;

int n = 10, q;
int a[] = {0, 3, 2, 1, 4, 5, 6, 3, 5, 6, 2};
long long st[4 * maxN], lazy[4 * maxN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id]+ st[2 * id + 1];
}

void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    st[id] += lazy[id]*(r - l + 1);
    if (l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
        cout<<l<<" "<<r<<"\n";
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = st[2 * id] + st[2 * id + 1];
}

long long get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l >  v || r <  u) return 0;
    if (l >= u && r <= v) return st[id];
    int mid  = l + r >> 1;
    long long get1 = get(2 * id, l, mid, u, v);
    long long get2 = get(2 * id + 1, mid + 1, r, u, v);
    return get1 + get2;
}

int main() {

}
