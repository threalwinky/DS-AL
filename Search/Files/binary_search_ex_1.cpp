#include<iostream>
#define alength(a) sizeof(a)/sizeof(a[0])
using namespace std;

int LowerBound(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] >= x) right = mid - 1;
		else left = mid+1;
	}
	if (left < curl || left > curr) return -1;
	return left;
}
int UpperBound(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] > x) right = mid - 1;
		else left = mid+1;
	}
	if (left < curl || left > curr) return -1;
	return left;
}
int LowerDive(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] < x) left = mid+1;
		else right = mid - 1;
	}
	if (right < curl || right > curr) return -1;
	return right;
}
int UpperDive(int a[], int left, int right, int x){
	int mid, curl = left, curr = right;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] <= x) left = mid+1;
		else right = mid - 1;
	}
	if (right < curl || right > curr) return -1;
	return right;
}

int main(){
	int n,a[10001],k;
	cin>>n>>k;
	for (int i = 0; i<n; i++) cin>>a[i];
	cout<<LowerDive(a, 0, n - 1, k) + 1<<endl;
	cout<<UpperDive(a, 0, n - 1, k) + 1<<endl;
	cout<<UpperBound(a, 0, n - 1, k) + 1<<endl;
	cout<<LowerBound(a, 0, n - 1, k) + 1<<endl;
}
//17 9 
//1 1 2 3 4 4 4 5 6 7 7 8 8 8 9 9 9 


