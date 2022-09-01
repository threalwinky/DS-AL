#include<bits/stdc++.h>
using namespace std;
int bt,m,n,path,s,t;
ifstream file("bai7.inp");
vector<int> adj[1001], check;
bool visited[1001] = {0},check1 = 0;
void nhap(){
	file>>m>>n;
	for (int i = 1; i<=n ;i++){
	int x,y;
	file>>x>>y;
	adj[x].push_back(y);
	adj[y].push_back(x);
	}
}
void dfs(int u){
	visited[u] = 1;
	for (auto v : adj[u]){
		if (!visited[v]){
		dfs(v);
		check.push_back(v);
		}
	}	
}
void bfs(int u){
	visited[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty()){
		int v = q.front();q.pop();
		for (auto x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x] = true;
				check.push_back(x);
			}
		}
		
	}
}
void xuly(int a, int b){
	check.clear();
	check1 = 0;
	memset(visited, 0, 1000);
	bfs(a);
	for (auto c : check){
		if (c==b) check1 = true;
	}
	if (check1) cout<<"YES";
	else cout<<"NO";
	cout<<"\n";
}
void ct(){
	file>>bt;
	for (int i = 1; i<=bt;i++){
		nhap();
		file>>path;
		for (int j = 1; j<=path;j++){
			file>>s>>t;
			xuly(s,t);
		}
	}
}
int main(){
	ct();
}