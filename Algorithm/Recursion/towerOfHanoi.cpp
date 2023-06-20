#include<bits/stdc++.h>
using namespace std;

void sol(int n, char a, char b, char c){
    if (n == 1) {
        cout << a << " -----> " << c << "\n";
        return;
    }
    sol(n-1, a, c, b);
    cout << a << " -----> " << c << "\n";
    sol(n-1, b, a, c);
}


int main(){
    int n = 4;
    sol(n, 'A', 'B', 'C');
}