#include<bits/stdc++.h>
using namespace std;
int dem = 1;
void gen_rec(vector<int> a, vector<int> v, int len, int n){
    if (len == n){
        cout << dem++ << " ";
        for (auto x : v) cout << a[x - 1] << " ";
        cout << "\n";
        return;
    }
    v.push_back(0);
    for (int i=1; i<=a.size(); i++){
        v[len] = i;
        gen_rec(a, v, len + 1, n);
    }
}

void gen(vector<int> a, int n){
    vector<int> v;
    v.push_back(0);
    for (int i=1; i<=a.size(); i++){
        v[0] = i;
        gen_rec(a, v, 1, n);
    }
}

int main(){
    vector<int> a = {5, 3, 1, 2, 4};
    gen(a, 4);
}