#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
vector<int> v[maxN];
bool check[maxN];
void dfs(int u){
    check[u] = true;
    stack<int> st;
    st.push(u);
    while (!st.empty()){
        int tmp = st.top();
        check[tmp] = true;
        cout<<tmp<<" ";
        st.pop();
        for (vector<int>::reverse_iterator it = v[tmp].rbegin();it != v[tmp].rend(); it++){
            if (!check[*it]){
                st.push(*it);
                //cout<<tmp<<"--->"<<*it<<"\n";
            }
        }
    }
}
void dfs1(int u){
    check[u] = 1;
    cout<<u<<" ";
    for (auto x:v[u]){
        if (!check[x]){
            dfs(x);
            check[x] = 1;
        }
    }
}

int main(){
    //freopen("sample.cpp", "r", stdin);
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
}
