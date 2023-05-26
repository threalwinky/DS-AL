#include<bits/stdc++.h>

int n;
int a[1001], b[1001], c[1001];
int main(){

	std::cin>>n;
	for (int i = 1; i<=n; i++){
		std::cin>>a[i];
	}
	b[0] = 1000000001; c[n+1] = 0;
	for (int i = 1; i<=n; i++){
		b[i] = std::min(b[i-1], a[i]);
	}
	for (int i = n; i>=1; i--){
		c[i] = std::max(c[i+1], a[i]);
	}
	int ans = 0;
	for (int i = 1; i<=n; i++){
		ans = std::max(ans, c[i] - b[i]);
	}
	std::cout<<ans;
}
