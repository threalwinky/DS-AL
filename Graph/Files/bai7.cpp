#include<bits/stdc++.h>
using namespace std;
int botest,m,n,path,s,t;
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
void xuly(int a, int b){
	bool check1 = 0, visited[1001] = {0};
	dfs(a);
	for (auto c : check){
		cout<<c<<" ";
	}
	cout<<endl;
}
void ct(){
	file>>botest;
	for (int i = 1; i<=botest;i++){
		nhap();
		file>>path;
		
			file>>s>>t;
			xuly(s,t);
		
	}
}
int main(){
	ct();
}