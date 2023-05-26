
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define maxN 1000005
const int MOD = 1e9+7;
int a[maxN], st[4*maxN], lazy1[4*maxN], lazy2[4*maxN], lazy3[4*maxN];
void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int m = l + (r - l)/2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    st[id] = (st[id*2]%MOD + st[id*2+1]%MOD)%MOD;
}
void fix1(int id, int l, int r){
    if (!lazy1[id]) return;
    st[id] = (st[id]%MOD + 1ll*lazy1[id]*(r - l + 1)%MOD)%MOD;
    if (l!=r){
        lazy1[id*2] = (lazy1[id*2]%MOD +lazy1[id]%MOD)%MOD;
        lazy1[id*2+1] = (lazy1[id*2+1]%MOD +lazy1[id]%MOD)%MOD;
    }
    lazy1[id] = 0;
}
void fix2(int id, int l, int r){
    if (!lazy2[id]) return;
    st[id] = (1ll*st[id] * lazy2[id])%MOD;
    if (l!=r){
        lazy2[id*2] = (lazy2[id*2]%MOD +lazy2[id]%MOD)%MOD;
        lazy2[id*2+1] = (lazy2[id*2+1]%MOD +lazy2[id]%MOD)%MOD;
    }
    lazy2[id] = 0;
}
void fix3(int id, int l, int r){
    if (!lazy3[id]) return;
    st[id] = (1ll*lazy3[id]*(r - l + 1))%MOD;
    if (l!=r){
        lazy3[id*2] = (lazy3[id*2]%MOD +lazy3[id]%MOD)%MOD;
        lazy3[id*2+1] = (lazy3[id*2+1]%MOD +lazy3[id]%MOD)%MOD;
    }
    lazy3[id] = 0;
}
void update1(int id, int l, int r, int u, int v, int val){
    fix1(id, l, r);
    fix2(id, l, r);
    fix3(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v){
        lazy1[id] += 1ll*val;
        fix1(id, l, r);
        fix2(id, l, r);
        fix3(id, l, r);
        return;
    }
    int m = l + (r - l)/2;
    update1(id*2, l, m, u, v, val);
    update1(id*2+1, m+1,r, u, v, val);
    st[id] = (st[id*2]%MOD + st[id*2+1]%MOD)%MOD;
}

void update2(int id, int l, int r, int u, int v, int val){
    fix1(id, l, r);
    fix2(id, l, r);
    fix3(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v){
        lazy2[id] += 1ll*val;
        fix1(id, l, r);
        fix2(id, l, r);
        fix3(id, l, r);
        return;
    }
    int m = l + (r - l)/2;
    update2(id*2, l, m, u, v, val);
    update2(id*2+1, m+1,r, u, v, val);
    st[id] = (st[id*2]%MOD + st[id*2+1]%MOD)%MOD;
}

void update3(int id, int l, int r, int u, int v, int val){
    fix1(id, l, r);
    fix2(id, l, r);
    fix3(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v){
        lazy3[id] += 1ll*val;
        fix1(id, l, r);
        fix2(id, l, r);
        fix3(id, l, r);
        return;
    }
    int m = l + (r - l)/2;
    update3(id*2, l, m, u, v, val);
    update3(id*2+1, m+1,r, u, v, val);
    st[id] = (st[id*2]%MOD + st[id*2+1]%MOD)%MOD;
}

int get(int id, int l, int r, int u, int v){
    fix1(id, l, r);
    fix2(id, l, r);
    fix3(id, l, r);
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id]%MOD;
    int m = l + (r - l)/2;
    int get1 = get(id*2, l, m, u, v);
    int get2 = get(id*2+1, m+1, r, u, v);
    return (get1%MOD + get2%MOD)%MOD;
}

signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("winky.inp", "r", stdin);
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    for (int i = 1; i<=m; i++){
        int x, a, b, c;
        cin>>x>>a>>b;
        if (x == 1){
            cin>>c;
            update1(1, 1, n, a, b, c);
        }
        else if (x == 2){
            cin>>c;
            update2(1, 1, n, a, b, c);
        }
        else if (x == 3){
            cin>>c;
            update3(1, 1, n, a, b, c);
        }
        else{
            cout<<get(1, 1, n, a, b)<<"\n";
        }
    }
}
