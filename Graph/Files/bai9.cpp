#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int>> path;
pair<int, int> parent[1001][1001], s,t;
int m,n,dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};
char a[1001][1001];
bool visited[1001] = {0};
ifstream file("bai9.inp");
void nhap(){
	file>>m>>n;
	for (int i = 0; i<m;i++)
		for (int j = 0 ;j<n;j++){
			file>>a[i][j];
			if (a[i][j] == 'A'){
				s.first = i;
				s.second = j;
				a[i][j] = '.';
			}
			if (a[i][j] == 'B'){
				t.first = i;
				t.second = j;
				a[i][j] = '.';
			}
		}
}
void bfs(int i, int j){
	a[i][j] = '#';
	queue<pair<int, int>> q;
	q.push({i,j});
	while (!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		for (int x = 0; x<4 ;x++){
			int i1,j1;
			i1 = v.first+dx[x];
			j1 = v.second+dy[x];
			if (i1>=0&&i1<m&&j1>0&&j1<n&&a[i1][j1] == '.'){
				q.push({i1,j1});
				a[i1][j1] = '#';
				parent[i1][j1] = {v.first,v.second};
			}
		}
	}
}
void xuly(){
	int cnt = 0;
	bfs(s.first,s.second);
	path.push({t.first, t.second});
	if (a[t.first][t.second] == '.') cout<<"NO";else{
	cout<<"YES"<<endl;
	while (t!=s){
		t = parent[t.first][t.second];
		path.push({t.first, t.second});
		cnt++;
		}
	cout<<cnt<<endl;
	}
}
void xuat(){
	/*pair<int, int> temp;
	for (int i = 0;i<9;i++){
		temp = path.top();
		path.pop();
		if ((path.top().first-temp.first == 1) &&(path.top().second-temp.second == 0)) cout<<"D";
		if ((path.top().first-temp.first == 0) &&(path.top().second-temp.second == 0)) cout<<"R";
		if ((path.top().first-temp.first == 0) &&(path.top().second-temp.second == -1)) cout<<"L";
		if ((path.top().first-temp.first == -1) &&(path.top().second-temp.second == 0)) cout<<"D";
	}*/
	pair<int, int> temp;
	while (true){
		temp = path.top();path.pop();
		if (path.empty()) break;
		if ((path.top().first-temp.first == 0) &&(path.top().second-temp.second == -1)) cout<<"L";
		if ((path.top().first-temp.first == 1) &&(path.top().second-temp.second == 0)) cout<<"D";
		if ((path.top().first-temp.first == 0) &&(path.top().second-temp.second == 1)) cout<<"R";
		if ((path.top().first-temp.first == -1) &&(path.top().second-temp.second == 0)) cout<<"U";

	}
}
int main(){
	nhap();
	xuly();
	xuat();
}