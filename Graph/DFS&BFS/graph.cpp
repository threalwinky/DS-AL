#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> adj[100001];
vector<int> parent(100001);
bool check[100001];
void bfs(int u, bool write){
	queue<int> q;
	check[u] = 1;
	q.push(u);
	while (!q.empty()){
		int tmp = q.front();
		if (write)cout<<tmp<<" ";
		q.pop();
		for (auto it : adj[tmp])
			if (!check[it]){
				check[it] = 1;
				q.push(it);
				parent[it] = tmp;
			}
	}
}
void dfs(int u, bool write){
	stack<int> st;
	check[u] = 1;
	st.push(u);
	while (!st.empty()){
		int tmp = st.top();
		if (write) cout<<tmp<<" ";
		st.pop();
		for (auto it : adj[tmp])
			if (!check[it]){
				check[it] = 1;
				st.push(it);
				parent[it] = tmp;
			}
	}
}
int main(){
	freopen("graph.inp", "r", stdin);
	freopen("graph.out", "w", stdout);
	int n, m, s, e, t, a;
	cin>>n>>m>>s>>e>>t;
	a = e;
	int x, y;
	for (int i = 1; i<=m; i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<"Use BFS : \n";
	cout<<"From "<<t<<" you can visit : ";
	bfs(t, 1);
	
	memset(check, 0, 100001);
	bfs(s, 0);
	if (parent[e] == 0) cout<<"\nNO WAY";
	else {
		cout<<"\nPath from "<<s<<" to "<<e<<" : ";
		cout<<s<<" ";
		stack<int> st;
		while (e != s){
			st.push(e);
			e = parent[e];
		}
		while (!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
	}
	
	cout<<"\nUse DFS : ";
	
	memset(check, 0, 100001);
	fill_n(parent.begin(), 100001, 0);
	cout<<"\nFrom "<<t<<" you can visit : ";
	dfs(t, 1);
	
	memset(check, 0, 100001);
	dfs(s, 0);
	e = a;
	if (parent[e] == 0) cout<<"\nNO WAY";
	else {
		cout<<"\nPath from "<<s<<" to "<<e<<" : ";
		cout<<s<<" ";
		stack<int> st;
		while (e != s){
			st.push(e);
			e = parent[e];
		}
		while (!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
	}
}