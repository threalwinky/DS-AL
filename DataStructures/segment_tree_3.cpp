#include<iostream>
using namespace std;
const int MAX = 1e5, inf = 1e9;
int sl[MAX], sl1 = 0;
void build(int a[], int st[], int id, int l, int r){
	sl1++;
	if (l == r){
		sl[id] =1;
		st[id] = a[l];
		return;
	}
	int m = l + (r - l)/2;
	
	build(a, st, id*2, l, m);
	build(a, st, id*2+1, m+1, r);
	st[id] = st[id*2] + st[id*2+1];
	sl[id] = sl[id*2] + sl[id*2+1];
}
void fix(int st[], int lazy[], int id, int l, int r){
	if (!lazy[id]) return;
	if (l == r){
		st[id] += lazy[id];
		lazy[id] = 0;
		return;
	}
    if (l != r){
		st[id] = st[id*2] + st[id*2+1] + lazy[id]*sl[id];
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
}
void update(int st[], int lazy[], int id, int l, int r, int u, int v, int val){
	fix(st, lazy, id, l, r);
	if (l > v || r < u) return;
	if (l >= u && r <= v){
		lazy[id] += val;
		fix(st, lazy, id, l, r);
		return;
	}
	int m = l + (r - l)/2;
	
	update(st, lazy, id*2, l, m, u, v, val);
	update(st, lazy, id*2+1, m+1, r, u, v, val);
	st[id] = st[id*2] + st[id*2+1];
}
int get(int st[], int lazy[], int id, int l, int r, int u, int v){
	fix(st, lazy, id, l, r);
	if (l > v || r < u) return 0;
	if (l >= u && r <= v){
		return st[id];
	}
	int m = l + (r - l)/2;
	int get1 = get(st, lazy, id*2, l, m, u, v);
	int get2 = get(st, lazy, id*2+1, m+1, r, u, v);
	return get1 + get2;
}
int a[MAX], st[MAX*4], lazy[MAX*4];
int main(){
	int n, q; cin>>n>>q;
	for (int i = 1; i<=n; i++){cin>>a[i];}
	build(a, st, 1, 1, n);
	while (q--){
		int l, r, val;
		cin>>l>>r>>val;
		update(st, lazy, 1, 1, n, l, r, val);
	}
	for (int i = 1; i<=sl1; i++)
		cout<<sl[i]<<" ";
	cout<<endl;
	for (int i = 1; i<=sl1; i++)
		cout<<st[i]<<" ";
	cout<<endl;
	cout<<get(st, lazy, 1, 1, n, 4, 5); 
}