#include<bits/stdc++.h>
using namespace std;
int dem = 1;

void genrec(vector<int> a, vector<int> v, vector<int> check, int len, int n){
    if (len == n){
        cout << dem++ << " ";
        for (auto x : v){
            cout << a[x] << " ";
        }
        cout << "\n";
        return;
    }
    v.push_back(0);
    for (int i=0; i<a.size(); i++){
        if (check[i] != 1){
            v[len] = i;
            check[i] = 1;
            genrec(a, v, check, len + 1, n);
            check[i] = 0;
        }
    }
}

void gen(vector<int> a, int n){
    vector<int> v;
    vector<int> check(a.size(), 0);
    v.push_back(0);
    for (int i=0; i<a.size(); i++){
        v[0] = i;
        check[i] = 1;
        genrec(a, v, check, 1, n);
        check[i] = 0;
    }
}

int main(){
    vector<int> a = {5, 3, 1, 2, 4};
    gen(a, 4);
}