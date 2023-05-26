#include<bits/stdc++.h>
#define int long long
void check_snt1(int n){

    for (int i = 2; i<n; i++){
        if (n%i==0){
            std::cout<<"Khong phai la so nguyen to\n"<<i;
            return;
        }
    }
    std::cout<<"La so nguyen to";
}

void check_snt2(int n){

    for (int i = 2; i<=sqrt(n)+1; i++){
        if (n%i==0){
            std::cout<<"Khong phai la so nguyen to\n";
            return;
        }
    }
    std::cout<<"La so nguyen to";
}
signed main(){
    int n = 10000000019;
    //check_snt1(n);
    check_snt2(n);
}
