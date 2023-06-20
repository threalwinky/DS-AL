#include<bits/stdc++.h>
using namespace std;
bool nextp(vector<int> &v){
    int tmp, sz = v.size();
    for (int i=sz-2; i>=0; i--){
        if (v[i] < v[i+1]){
            tmp = i;
            break;
        }
        tmp = i;
    }
    if (tmp == 0  && v[tmp] == sz) return 0;
    for (int i = sz - 1; i>=tmp; i--){
        if (v[i] > v[tmp]){
            swap(v[i], v[tmp]);
            break;
        }
    }
    for (int i = sz - 1; i >= (tmp + sz + 1)/2; i--){
        swap(v[i], v[sz + tmp - i]);
    }
    return 1;
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    do {
        for (auto x : v) cout << x << " ";
        cout << "\n";
    } while (nextp(v)) ;
}