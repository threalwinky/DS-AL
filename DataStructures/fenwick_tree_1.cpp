#include<iostream>
using namespace std;
const int MAX = 1e5;
void update(long long bit[], int n, int pos, int val){
	while (pos <= n){
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}
long long get(long long bit[], int n, int pos){
	long long ans = 0;
	while (pos > 0){
		ans += bit[pos];
		pos -= (pos & (-pos));
	}
	return ans;
}
long long bit[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q; cin>>n>>q;
	for (int i = 1; i<=n; i++){
		int x; cin>>x;
		update(bit, n, i, x);
	}
	while (q--){
		long long type, l, r;
		cin>>type>>l>>r;
		if (type == 1) {
			update(bit, n, l, r);
		}
		else cout<<get(bit, n, r) - get(bit, n, l-1)<<"\n";
	}
}