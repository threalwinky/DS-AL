#include<bits/stdc++.h>
using namespace std;
#define NMAX 10001
#define FASTINPUT(); ios::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);\
typedef long long ll;
typedef unsigned long long ull;
int arr[NMAX], n,m;
void inp(){
	cin>>n>>m;
	for (int i = 0; i<n; i++){
		cin>>arr[i];
	}
}
void out(){
	bool check = 0;
	for (int i = 0; i < n ; i++){
		if (arr[i] == m){
			check = 1;
		}
	}
	if (check) cout<<"FOUND";
	else cout<<"NOT FOUND";
}
int main(){
    FASTINPUT();
    inp();
    out();
}