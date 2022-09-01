#include <bits/stdc++.h>
using namespace std;
ifstream file("bai2.inp");
int botest,m,n,l,lmax;
vector<int> adj[1001];
bool check[1001];
void nhapbotest(){
	file>>botest;
}
void nhap(){
	file>>m>>n;
	for (int i = 1; i<= n; i++){
		int x,y;
		file>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void dfs(int u){
	check[u] = 1;
	for (auto v : adj[u])
		if (!check[v]){ 
			dfs(v);
			l++;
		}
}
void xuly(){
	for (int i = 1; i<=n;i++){
		l = 1;
		if (!check[i]) dfs(i);
		if (l > lmax) lmax = l;
	}
}
void xuat(){
	cout<<lmax<<endl;
}
void chuongtrinh(){
	nhapbotest();
	for (int i = 1; i<= botest ;i++){
	lmax = -10000;
	check[1001] = {0};
	adj[1001] = {0};
	nhap();
	xuly();
	xuat();
	}
}
int main(){
	chuongtrinh();
}