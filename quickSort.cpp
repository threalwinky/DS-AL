#include<bits/stdc++.h>
using namespace std;
int a[20] = {2,3,5,2,1,8,56,34,3,4,21,31,43,12,3,1,9,2,3,2};
int sl = 20;

void qs(int a[], int left, int right){
	//init
	int i, j, x;
	i = left; j = right;
	x = a[(i+j)/2];

	//handle
	do {
	
		while (a[i] < x) i++;
		while (a[j] > x) j--;

		if (i <= j) {

			swap(a[i], a[j]);
			i++; j--;

		}
	}while (i <= j);
	//recurse
	if (i < right) qs(a, i ,right);
	if (left < j) qs(a, left, j);
	
}

int main(){
	
	qs(a, 0, sl - 1);

    for (int i = 0; i < sl ; i++){
    	cout<<a[i]<<" ";
    }
    int a[20] = {2,3,5,2,1,8,56,34,3,4,21,31,43,12,3,1,9,2,3,2};
    sort(a, a+sl);
    cout<<endl;
    for (int i = 0; i < sl ; i++){
    	cout<<a[i]<<" ";
    }

}