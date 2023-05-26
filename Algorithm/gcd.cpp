#include<bits/stdc++.h>
#define endl std::cout<<"\n";
int gcd(int a, int b){
    while (b!=0&&a!=0){
        if (a > b){
            a %= b;
        }
        else b %= a;
    }
    return a+b;
}

int main(){
    int a, b;
    std::cin>>a>>b;
    std::cout<<gcd(a, b);
    endl;
    std::cout<<std::__gcd(a, b);
    endl;
    std::cout<<(a*b)/gcd(a, b);
    endl;
}
