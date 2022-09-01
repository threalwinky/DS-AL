#include <bits/stdc++.h>
using namespace std;
#define NMAX 1001
int m,n,s,path[NMAX],cnt = 0, parent[NMAX];
bool visited[NMAX];
vector<int> adj[NMAX];
void nhap(){
	cin>>m>>n>>s;
	for (int i = 1;i <= n;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void bfs(int u){
	queue<int> q;
	visited[u] = 1;
	q.push(u);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (auto x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x] = true;
				cnt++;
				parent[x] = v;
			}
		}
	}
}
int tx(int s, int e){
	int count = 0;
	while (e!=s){
		e = parent[e];
		count++;
	}
	return count;
}
void xuly(){
	memset(visited, 0, NMAX);
	bfs(s);
}
void xuat(){
	for (int i = 1; i<=cnt+1;i++){
		cout<<i<<" "<<tx(s, i)<<endl;
	}
}
int main(){
	freopen("giaothong1.inp", "r", stdin);
	nhap();
	xuly();
	xuat();
}