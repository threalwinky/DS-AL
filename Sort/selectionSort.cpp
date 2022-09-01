#include<bits/stdc++.h>
using namespace std;

void selection(int a[],int n ){
	int min,i,j; 
	for (i=0; i<n-1 ; i++) {
		min = i;
		for(j = i+1; j <n ; j++)
			if (a[j] < a[min]) 
				min = j; 
		swap(a[min],a[i]);
	}
}

int main(){
	int arr[20] = {2,3,5,2,1,8,56,34,3,4,21,31,43,12,3,1,9,2,3,2};
	int sl = 20;
    selection(arr,sl);

    for (int i = 0; i < sl ; i++){
    	cout<<arr[i]<<" ";
    }
}