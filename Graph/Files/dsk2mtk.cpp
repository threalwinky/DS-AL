#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("dt.inp");
    int n,a[100][100] = {0};
    file>>n;
    vector<int> adj[100];
    file.ignore();
    for (int i = 1; i<=n ;i++){
        string s, num;
        getline(file ,s);
        stringstream ss(s);
        while (ss>>num){
            a[i][stoi(num)] = 1;
        }
    }
    for (int i = 1; i<=n;i++){
        for (int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}