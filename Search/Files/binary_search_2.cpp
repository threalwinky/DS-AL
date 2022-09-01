#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
#define alength(n) sizeof(n)/sizeof(n[0])

int BS1(int a[], int left,int right, int k){
	while (left < right){
		int mid = left + (right - left)/2;
		if (a[mid] >= k) right = mid;
		else left = mid + 1;
	}
	if (a[left] == k) return left;
	return -1;
}

int BS2(int a[], int left,int right, int k){
	while (left <= right){
		int mid = left + (right - left)/2;
		if (a[mid] >= k) right = mid - 1;
		else left = mid + 1;
	}
	if (a[left] == k) return left;
	return -1;
}
int main(){
	int a[] = {1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,6,6,6,7,7,9,9,9,9};
	vector<int> v(a, a+alength(a));
	for (int i = 0; i<alength(a); i++){
		cout<<i;
		cout<<" "<<a[i];
		cout<<" "<<BS1(a, 0, alength(a) - 1, a[i]);
		cout<<" "<<BS2(a, 0, alength(a) - 1, a[i])<<endl;
	}
	cout<<BS1(a, 0, alength(a) - 1, 8);
	cout<<BS2(a, 0, alength(a) - 1, 8);
}