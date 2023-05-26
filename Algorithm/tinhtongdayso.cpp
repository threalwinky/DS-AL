#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n = 6, m = 4;
    int tmp1 = (m - 1)/2+1;
    int tmp2 = m - tmp1;
    int tong1 = (tmp1*(tmp1+1))/2;
    int tmp3 = n/2;
    int tong2 = (tmp3 * (tmp3 + 1))/2;
    int tong3 = ((n*(n+1))/2-tong2) - (((n - tmp2)*(n - tmp2 + 1))/2-tong2);
    cout<<tong1 + tong3;

}
