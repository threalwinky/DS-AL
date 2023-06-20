#include<bits/stdc++.h>
using namespace std;


void gen(int n){
    vector<int> v;
    for (int i=0; i<n; i++){
        v.push_back(0);
    }
    while (true){
        for (auto x : v) cout << x << " ";
        cout << "\n";
        int tmp = 0;
        for (int i=n - 1; i>=0; i--){
            if (v[i] == 0){
                v[i] = 1;
                break;
            }
            v[i] = 0;
            tmp++;
        }
        if (tmp == n) break;
    }
}

int main(){
    gen(5);
}