#include<bits/stdc++.h>
using namespace std;
int dem = 1;

void genrec(vector<int> a, vector<int> v, vector<int> check, int len, int n, int s){
    if (len == n){
        cout << dem++ << " ";
        for (auto x : v) cout << x << " ";
        cout << '\n';
        return;
    }
    v.push_back(0);
    for (int i=s; i<a.size(); i++){
        if (!check[i]){
            check[i] = 1;
            v[len] = i;
            genrec(a, v, check, len + 1, n, i);
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
        genrec(a, v, check, 1, n, i);
        check[i] = 0;
    }
}

int main(){
    vector<int> a = {5, 3, 1, 2, 4, 6, 3};
    gen(a, 4);
}