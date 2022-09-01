#include<bits/stdc++.h>
using namespace std;
ifstream file("bai5.inp");
int bt,m,n,s,t,parent[1001],l;
	bool visited[1991] = {0};
	vector<int> adj[1001];
	stack<int> path;
	void nhap(){
		file>>m>>n>>s>>t;
		for (int i = 1; i <= n; i++){
			int x,y;
			file>>x>>y;
			adj[x].push_back(y);
		}
	}
	void dfs(int u){
		visited[u] = true;
		for (auto v : adj[u]){
			if (!visited[v]) {
			dfs(v);
			parent[v] = u;
			}
		}
	}
	void xuly(int s, int t){
		dfs(s);
		if (!visited[t]) cout<<"khong co duong di";
		else{
		while(t!=s){
			path.push(t);
			t = parent[t];
		}
		path.push(s);
		}
	}
	void xuat(){
		while (!path.empty()){
			cout<<path.top()<<" ";
			path.pop();
		}
		cout<<endl;
	}
void ct(){
	file>>bt;
	for (int a = 1;a<=bt;a++){
	bool visited[1991] = {0};
	vector<int> adj[1001];
	nhap();
	xuly(s, t);
	xuat();
	}
}
int main(){
	ct();
}