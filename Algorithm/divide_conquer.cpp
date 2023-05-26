#include<bits/stdc++.h>
#define int long long

int mul(int a, int b){
    if (b == 1) return a;
    if (b % 2 == 0) return mul(a, b/2) + mul(a,b/2);
    return mul(a, b/2) + mul(a, b/2) + a;
}

int pow(int a, int b){
    if (b == 1) return a;
    if (b % 2 == 0) return pow(a, b/2) * pow(a,b/2);
    return pow(a, b/2) * pow(a, b/2) * a;
}

signed main(){
    int a = 9, b = 18;
    std::cout<<mul(a, b)<<"\n";
    std::cout<<pow(a, b);

}
