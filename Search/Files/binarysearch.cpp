    #include<bits/stdc++.h>
using namespace std;
#define NMAX 10001
#define FASTINPUT(); ios::sync_with_stdio(0);\
    cin.tie(0);\
    cout.tie(0);\
typedef long long ll;
typedef unsigned long long ull;
int a[6] = {1,2,4,7,8,9}, x = 2 /*3*/,n = 2;
void inp(){}
void out(){
	bool check = 0;
	int l = 0,r = n-1;
	while (l<=r){
		int m = (l+r)/2;
		if (a[m] == x){
			check = 1;
			break;
		}
		else if (a[m] > x){
			r = m - 1;
		}
		else l = m+1;
	}
	if (check) cout<<"FOUND";
	else cout<<"NOT FOUND";
}
int main(){
    FASTINPUT();
    inp();
    out();
}