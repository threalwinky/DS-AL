#include<bits/stdc++.h>
using namespace std;

void interchange(int a[], int n)
{
	int i, j;
	for (i = 0 ; i<n-1 ; i++)
		for (j =i+1; j < n ; j++)
			if(a[j ]< a[i])
				swap(a[i], a[j]);
}

int main(){
	int arr[20] = {2,3,5,2,1,8,56,34,3,4,21,31,43,12,3,1,9,2,3,2};
	int sl = 20;
    interchange(arr, sl);

    for (int i = 0; i < sl ; i++){
    	cout<<arr[i]<<" ";
    }
}