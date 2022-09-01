#include<iostream>
using namespace std;
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
int LowerBound(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] >= x) right = mid - 1;
		else left = mid+1;
	}
	if (left < curl ) return a[curl];
	if (left > curr ) return a[curr];
	return a[left];
}
int UpperDive(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] <= x) left = mid+1;
		else right = mid - 1;
	}
	if (right < curl ) return a[curl];
	if (right > curr ) return a[curr];
	return a[right];
}
int main(){
	int n, a[10001], b[10001], ans = 10000000;
	cin>>n;
	for (int i = 0; i<n; i++) cin>>a[i];
	for (int i = 0; i<n; i++) cin>>b[i];
	quickSort(b, 0, n - 1);
	
	for (int i = 0; i<n; i++){
		//cout<<a[i] <<" "<<LowerBound(b, 0 ,n - 1, -a[i]) <<" "<<UpperDive(b, 0, n -1, -a[i])<<endl;
		ans = min(ans, min(abs(a[i] + LowerBound(b, 0, n - 1, -a[i])), abs(a[i] + UpperDive(b, 0, n - 1, -a[i]))));
	}
	cout<<ans;
}
//5 2 3 5 1 2 6 7 3 4 6

