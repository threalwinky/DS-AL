#include<bits/stdc++.h>
using namespace std;
int arr[20] = {2,3,5,2,1,8,56,34,3,4,21,31,43,12,3,1,9,2,3,2};
int sl = 20;
void bubble(int a[],int n)
{
	int i, j;
	for (i = 0 ; i<n-1 ; i++)
		for (j =n-1; j >i ; j --)
			if(a[j]< a[j-1])
				swap(a[j], a[j-1]);
}

int main(){
	
    bubble(arr, sl);

    for (int i = 0; i < sl ; i++){
    	cout<<arr[i]<<" ";
    }
}