#include<bits/stdc++.h>

bool check_palin(int n){
    int tmp = 0, tmp1 = n;
    while (n!=0){
        tmp+=n%10;
        tmp*=10;
        n/=10;
    }
    tmp/=10;
    return tmp == tmp1;
}

int main(){
    int ans = 0;
    for (int i = 10000; i<=100000; i++){
        if (check_palin(i)) ans++;
    }
    std::cout<<ans;
}
