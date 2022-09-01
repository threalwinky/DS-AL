#include<iostream>
using namespace std;
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
int main(){
	int a[] = {1,3,4};
	int n = LowerDive(a, 0, 2, 5);
	cout<<n;
}