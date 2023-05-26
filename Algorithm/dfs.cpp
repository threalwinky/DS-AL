#include<bits/stdc++.h>

std::vector<int> v[100001];
bool visit1[100001], visit2[100001], visit3[100001];

void dfs(int u){
	std::cout<<u<<" ";
	visit1[u] = 1;
	for (int x : v[u]){
		if (!visit1[x]){
			dfs(x);
		}
	}
}

void dfs_stack(int u){
	std::stack<int> st;
	st.push(u);
	while (!st.empty()){
		int tmp = st.top();
		std::cout<<tmp<<" ";
		visit2[tmp] = 1;
		st.pop();
		for (int x = v[tmp].size() - 1; x>=0; x--){
			if (!visit2[v[tmp][x]]){
				st.push(v[tmp][x]);
			}
		}
	}
}

void bfs(int u){
	std::queue<int> q;
	q.push(u);
	while (!q.empty()){
		int tmp = q.front();
		std::cout<<tmp<<" ";
		visit3[tmp] = 1;
		q.pop();
		for (int x : v[tmp]){
			if (!visit3[x]){
				q.push(x);
			}
		}
	}
}

int main(){
	int n, m;
	std::cin>>n>>m;
	for (int i = 0; i<m; i++){
		int x,y;
		std::cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	std::cout<<"DFS with recursion : ";
	dfs(1);
	std::cout<<"\n";
	std::cout<<"DFS with stack : ";
	dfs_stack(1);
	std::cout<<"\n";
	std::cout<<"BFS : ";
	bfs(1);
	std::cout<<"\n";
}
