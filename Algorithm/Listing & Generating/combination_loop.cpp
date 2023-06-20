#include<bits/stdc++.h>
using namespace std;
int dem = 1;
void genrec(vector<int> a, vector<int> v, int len, int n, int s){
    if (len == n){
        cout << dem++ << " ";
        for (auto x : v){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    v.push_back(0);
    for (int i=s; i<a.size(); i++){
        v[len] = i;
        genrec(a, v, len + 1, n, i);
    }
}

void gen(vector<int> a, int n){
    vector<int> v;
    v.push_back(0);
    for (int i=0; i<a.size(); i++){
        v[0] = i;
        genrec(a, v, 1, n, i);
    }
}

int main(){
    vector<int> a = {5, 3, 1, 2, 4};
    gen(a, 3);
}