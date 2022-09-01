#include <bits/stdc++.h>
using namespace std;
#define NMAX 1001
int m,n,s,path[NMAX],cnt = 0;
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
	queue<int> q;path[u] = 0;
	visited[u] = 1;
	q.push(u);
	
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (auto x : adj[v]){
			if (!visited[x]){
				path[x] = path[v]+1;
				q.push(x);
				visited[x] = true;
				cnt++;
			}
		}
	}
}
void xuly(){
	memset(visited, 0, NMAX);
	memset(path, 0, NMAX);
	bfs(s);
}
void xuat(){
	for (int i = 1; i<=cnt+1;i++){
		cout<<i<<" "<<path[i]<<endl;
	}
}
int main(){
	freopen("giaothong1.inp", "r", stdin);
	nhap();
	xuly();
	xuat();
}