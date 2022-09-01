#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Sum{
	int sum, fi, se;
	Sum(){}
	Sum(int a, int b, int c){
		sum = a;
		fi = b;
		se = c;
	}
};
bool operator < (const Sum a, const Sum b){
	return a.sum < b.sum;
}
int BinarySearch(vector<Sum> v, int l, int r, int k){
	while (l <= r){
		int m = l + (r - l)/2;
		if (v[m].sum == k) return m;
		if (v[m].sum < k) l = m+1;
		else r = m-1;
	}
	return -1;
}
vector<Sum> v;
vector<int> a;
int main(){
	freopen("fenwick_tree_test.inp", "r", stdin);
	int n, k;
	cin>>n>>k;
	for (int i = 0; i<n; i++){
		int x; cin>>x;
		a.push_back(x);
	}
	for (int i = 0;i < n; i++){
		for (int j = i+1; j < n; j++){
			v.emplace_back(a[i] + a[j], i, j);
		}
	}
	sort(v.begin(), v.end());
	const int vsize = v.size() - 1;
	bool flag = 0;
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n;j++){
			int tmp1 = k - a[i] - a[j];
			int tmp2 = BinarySearch(v, 0, vsize, tmp1);
			int tmp3 = tmp2;
			if (tmp2 != -1){
				while (v[tmp2].sum == tmp1 && tmp2 >=0 && tmp2 <= vsize){
					if (flag) break;
					if ((v[tmp2].fi != i)&&(v[tmp2].fi != j)&&(v[tmp2].se != i)&&(v[tmp2].se != j)){
						flag = 1;
						cout<<i + 1<<" "<<j + 1<<" "<<v[tmp2].fi + 1<<" "<<v[tmp2].se + 1;
						break;
					}
					tmp2--;
				}
				while (v[tmp3].sum == tmp1 && tmp3 >=0 && tmp3 <= vsize){
					if (flag) break;
					if ((v[tmp3].fi != i)&&(v[tmp3].fi != j)&&(v[tmp3].se != i)&&(v[tmp3].se != j)){
						flag =1;
						cout<<i + 1<<" "<<j + 1<<" "<<v[tmp2].fi + 1<<" "<<v[tmp2].se + 1;
						break;
					}
					tmp3++;
				}
				if (flag) break;
			}
		}
		if (flag) break;
	}
	if (!flag) cout<<"IMPOSSIBLE";
}