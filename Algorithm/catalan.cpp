#include<bits/stdc++.h>
#define int long long
int cata(int n){
    int tmp = 1;
    for (int i = 1; i<=n; i++){
        tmp *= (n+i);
        tmp /= i;
    }
    tmp /= (n + 1);
    return tmp;
}

signed main(){
    int n;
    std::cin>>n;
    std::cout<<cata(n);
}
