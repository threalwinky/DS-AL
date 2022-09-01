#include<iostream>
using namespace std;
int LowerDive(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] < x) left = mid+1;
		else right = mid - 1;
	}
	if (right < curl) return curl;
	if (right > curr) return curr;
	return right;
}
void quickSort(int a[], int left, int right){
	int m = (left + right)/2;
	int i = left, j = right;
	while (i <= j){
		while (a[i] < a[m]) i++;
		while (a[j] > a[m]) j--;

		if (i <= j) {

			swap(a[i], a[j]);
			i++; j--;

		}
	}
	if (i < right) quickSort(a, i ,right);
	if (left < j) quickSort(a, left, j);
}
int main(){
	int n, a[2001], b[2001], c[2001], ans = 0;
	cin>>n;
	for (int i = 0; i<n; i++) cin>>a[i];
	for (int i = 0; i<n; i++) cin>>b[i];
	for (int i = 0; i<n; i++) cin>>c[i];
	quickSort(c, 0, n - 1);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			for (int k = LowerDive(c, 0, n-1, a[i]+b[j]); k>=0; k--)
				if (c[k] + a[i] > b[j] && c[k] + b[j] > a[i]) {
					cout<<a[i] << " " << b[j] << " " << c[k] << endl;
					ans++;
				}
		}
	}
	cout<<ans;
}