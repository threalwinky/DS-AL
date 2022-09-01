#include<iostream>
using namespace std;
const int MAX = 1e6, inf = 1e9;
inline int min(int a, int b){ return a<b ? a : b; }
void build(int a[], int st[], int id, int l, int r){
	if (l == r){
		st[id] = a[l];
		return;
	}
	int m = l + (r-l)/2;
	build(a, st, id*2, l, m);
	build(a, st, id*2+1,m+1,r);
	st[id] = min(st[id*2], st[id*2 + 1]);
}
void update(int st[], int id, int l, int r, int i, int val){
	if (i < l || i > r) return;
	if (l == r){
		st[id] = val;
		return;
	}
	int m = l + (r - l)/2;
	update(st, id*2, l, m, i, val);
	update(st, id*2+1, m+1, r, i, val);
	st[id] = min(st[id*2], st[id*2+1]);
}
void fix(int st[],int lazy[], int id, int l, int r) {
    if (!lazy[id]) return;
    st[id] = lazy[id];
    if (l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
}
void updategr(int st[],int lazy[], int id, int l, int r, int u, int v, int val){
	fix(st, lazy, id, l, r);
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(st, lazy, id, l, r);
        return;
    }
    int mid = l + r >> 1;
    updategr(st,lazy, 2 * id, l, mid, u, v, val);
    updategr(st,lazy, 2 * id + 1, mid + 1, r, u, v, val);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}
int get(int st[], int id, int l, int r, int u, int v){
	if (l >  v || r <  u) return inf;
	if (l >= u && r <= v) return st[id];
	int m = l + (r - l)/2;
	int get1 = get(st,id*2, l, m, u, v);
	int get2 = get(st,id*2+1, m+1, r, u, v);
	return min(get1, get2);
}
int getwlazy(int st[],int lazy[], int id, int l, int r, int u, int v){
	fix(st, lazy, id, l, r);
	if (l >  v || r <  u) return inf;
	if (l >= u && r <= v) return st[id];
	int m = l + (r - l)/2;
	int get1 = getwlazy(st, lazy,id*2, l, m, u, v);
	int get2 = getwlazy(st, lazy,id*2+1, m+1, r, u, v);
	return min(get1, get2);
}
int a[MAX], st[MAX*4], lazy[4*MAX];
int main(){
	int n;cin>>n;
	for (int i = 1; i<=n;i++){
		cin>>a[i];
	}
	build(a,st,1,1,n);
	update(st, 1, 1, n, 5, 2);
	updategr(st,lazy, 1, 1, n, 3, 6, 4);
	for (int i = 1; i<=n;i++){
		cout<<get(st, 1, 1, n, i, i)<<" ";
	}
	cout<<endl;
	for (int i = 1; i<=n;i++){
		cout<<getwlazy(st,lazy , 1, 1, n, i, i)<<" ";
	}
}