#include<bits/stdc++.h>
using namespace std;

int F[100001];

int fibo(int n){
	F[0] = F[1] = 1;
	if (F[n] == 0){
		F[n] = fibo(n - 1) + fibo(n-2);
	}
	return F[n];
}

int main(){
	cout<<fibo(10);
	cout<<fibo(50);	
}