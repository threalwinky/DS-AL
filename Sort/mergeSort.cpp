#include<bits/stdc++.h>
using namespace std;

int a[1000001];

void mergeSort(int arr[1000001], int l, int r) {
	if (l < r){
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		int i = l, j = m + 1; 
		int k = 0; 
		while (i <= m || j <= r) {
			if ((i <= m && j <= r && arr[i] < arr[j]) || (j > r))
				a[k++] = arr[i++];
			else a[k++] = arr[j++];
		}
		for (int i = 0; i < k; i++)
			arr[l + i] = a[i];
	}
}

int main(){
	int arr[20] = {2,3,5,2,1,8,56,34,3,4,21,31,43,12,3,1,9,2,3,2};
	int sl = 20;
	mergeSort(arr, 0, sl - 1);
	for (int i = 0; i < sl ; i++){
    	cout<<arr[i]<<" ";
    }
}