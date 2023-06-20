#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a = 9, b = 3;
    cout << gcd(9, 3);
}