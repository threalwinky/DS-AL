#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
#define alength(n) sizeof(n)/sizeof(n[0])
int BinarySearch(int a[], int left, int right, int x){
	while (left < right){
		int mid = left + (right - left)/2;
		if (a[mid] == x) return mid;
		if (a[mid] > x) right = mid;
		else left = mid+1;
	}
	if (a[left] == a[right] && a[left] == x)
		return right;
	return -1;
}
int LowerBound(int a[], int left, int right, int x){
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] == x) return a[mid];
		if (a[mid] >= x) right = mid - 1;
		else left = mid+1;
	}
	return a[left];
}
int UpperBound(int a[], int left, int right, int x){
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] > x) right = mid - 1;
		else left = mid+1;
	}
	return a[left];
}
int LowerDive(int a[], int left, int right, int x){
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] < x) left = mid+1;
		else right = mid - 1;
	}
	return a[right];
}
int UpperDive(int a[], int left, int right, int x){
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (a[mid] == x) return a[mid];
		if (a[mid] <= x) left = mid+1;
		else right = mid - 1;
	}
	return a[right];
}
int main(){
	int a[] = {-5,-4,-4,-3,1,3,4,6,7,13,18,23,34,45,46,53,57,64,72,78,83,91};
	vector<int> v(a, a+alength(a));
	for (int i = 0; i<50; i++){
		if (BinarySearch(a, 0, alength(a) - 1, i) != -1) cout<<i<<" ";
	}
	cout<<endl;
	for (int i = 0; i<100; i++){
		cout<<i;
		cout<<"    "<<LowerBound(a, 0, alength(a), i);
		cout<<" "<<*lower_bound(v.begin(), v.end(), i);
		cout<<"    "<<LowerDive(a, 0, alength(a), i);
		cout<<"    "<<UpperDive(a, 0, alength(a), i);
		cout<<"    "<<*upper_bound(v.begin(), v.end(), i);
		cout<<" "<<UpperBound(a, 0, alength(a), i)<<endl;
	}
	for (int i = -100; i<100;i++){
		if (BinarySearch(a, 0, alength(a), i) != -1) cout<<i<<" ";
	}
}