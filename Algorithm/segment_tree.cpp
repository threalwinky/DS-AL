#include<bits/stdc++.h>
#define maxN 100001
#define inf 1e9+7
inline int min(int a, int b){return (a < b) ? a : b;}
void st_build(std::vector<int> a, std::vector<int> &st, int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int m = l + (r - l)/2;
    st_build(a, st, id*2, l, m);
    st_build(a, st, id*2+1, m+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

void st_update(std::vector<int> &st, int id, int l, int r, int pos, int val){
    if (pos < l || pos > r) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int m = l + (r - l)/2;
    st_update(st, id*2, l, m, pos, val);
    st_update(st, id*2+1, m+1, r, pos, val);
    st[id] = st[id*2] + st[id*2+1];
}

void fix(std::vector<int> &st, std::vector<int> &lazy, int id, int l, int r){
    if (!lazy[id]) return;
    st[id] += lazy[id];
    if (l!=r){
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void st_updategr(std::vector<int> &st, std::vector<int> &lazy, int id, int l, int r, int u, int v, int val){
     fix(st, lazy, id, l, r);
     if (l > v || r < u) return;
     if (l >= u || r <= v){
         lazy[id] += val;
         fix(st, lazy, id, l, r);
         return;
     }
     int m = l + (r - l)/2;
     st_updategr(st, lazy, id*2, l, m, u, v, val);
     st_updategr(st, lazy, id*2+1, m+1, r, u, v, val);
     st[id] = st[id*2] + st[id*2+1];
}

int st_get(std::vector<int> &st, std::vector<int> &lazy, int id, int l, int r, int u, int v){
    fix(st, lazy, id, l, r);
    if (l > v || r < u) return 0;
    if (l >= u && r <= v){
        return st[id];
    }
    int m = l + (r - l)/2;
    int get1 = st_get(st,lazy, id*2, l, m, u, v);
    int get2 = st_get(st,lazy, id*2+1, m+1, r, u, v);
    return get1 + get2;
}
std::vector<int> st(maxN);
std::vector<int> lazy(maxN);
int main(){
    int n = 10;
    std::vector<int> a {0, 3, 2, 1, 4, 5, 6, 3, 5, 6, 2};
    st_build(a, st, 1, 1, n);
    for (int i = 1; i<=20; i++) std::cout<<a[i]<<" ";
    std::cout<<"\n";
    for (int i = 1; i<=20; i++) std::cout<<st[i]<<" ";
    std::cout<<"\n";
    std::cout<<st_get(st, lazy, 1, 1, n, 4, 7);//1
    std::cout<<"\n";
    //st_update(st, 1, 1, n, 5, 2);
    std::cout<<"\n";
    for (int i = 1; i<=20; i++) std::cout<<st[i]<<" ";
    std::cout<<"\n";
    std::cout<<st_get(st,lazy, 1, 1, n, 4, 7);//1
    std::cout<<"\n";
    st_updategr(st, lazy, 1, 1, n, 2, 7, -3);
    for (int i = 1; i<=20; i++) std::cout<<st[i]<<" ";
    std::cout<<"\n";
    std::cout<<st_get(st, lazy, 1, 1, n, 4, 7);//1
}
