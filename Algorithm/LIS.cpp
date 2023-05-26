#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	int n;
	cin>>n;
	for (int i = 1; i<=n; i++){
		int x;
		cin>>x;
		vector<int>::iterator it;
		it = lower_bound(a.begin(), a.end(), x);
		if (it != a.end()) *it = x;
		else a.push_back(x);
	}
	cout<<a.size();
	cout<<a.end() - a.begin();
}