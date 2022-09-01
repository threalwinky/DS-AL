#include<iostream>
using namespace std;
const int MAX = 1e5, inf = 1e9;
int sl[4*MAX], dem = 0;
void build(int a[], int st[], int id, int l, int r){
	dem++;
	if (l == r){
		sl[id] = 1;
		st[id] = a[l];
		return;
	}
	int m = l + (r - l)/2;
	build(a, st, id*2, l, m);
	build(a, st, id*2+1, m+1, r);
	sl[id] = sl[id*2] + sl[id*2+1];
	st[id] = st[id*2] + st[id*2+1];
}
void print_tree(int st[], int id, int l, int r){
	int tmp = 1, np = 1;
	for (int i = 1; i<=dem; i++){
		for (int j = 0; j<sl[i];j++)
			cout<<" ";
		cout<<st[i];
		if (i == tmp){
			cout<<endl<<endl;
			np*=2;
			tmp = tmp+np;
		}
	}
}
int a[MAX], st[4*MAX];
int main(){
	int n; cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	build(a, st, 1, 1, n);
	print_tree(st, 1, 1, n);
	cout<<endl;
	print_tree(sl, 1, 1, n);
}