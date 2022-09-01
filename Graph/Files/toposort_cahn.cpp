#include<bits/stdc++.h>
using namespace std;
int m,n,in[1001];
vector<int> adj[1001];
bool visited[1001];
stack<int> topo;
void inp(){
	cin>>m>>n;
	for (int i = 1; i<=n; i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
}
void dfs(int u){
	visited[u] = true;
	for (auto v : adj[u]){
		if (!visited[v]){

			dfs(v);
			
		}
	}
	topo.push(u);
}


void out(){
	while (!topo.empty()){
		cout<<topo.top()<<" ";
		topo.pop();
	}
}
void kahn(int u){
	memset(in, 0 , 1001);
	cin>>m>>n;
	for (int i = 1; i<=n; i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		in[y]++;

	}
	queue<int> q;
	for (int i = 1;i<=n;i++){
		if (in[i] == 0) q.push(i);
	}
	while (!q.empty()){
		int v = q.front();
		q.pop();
		cout<<v<<" ";
		for (auto x : adj[v]){
			in[x]--;
			if (in[x] == 0) {
			q.push(x);
			}
		}
	}
}
int main(){
	freopen("kahn.inp", "r", stdin);
	kahn(1);
}