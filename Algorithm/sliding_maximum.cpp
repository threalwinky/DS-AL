#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
    freopen("winky.inp", "r", stdin);
    freopen("winky.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    deque<int> dq;
    for (int i = 1; i<=n; i++){
        cin>>a[i];
    }
    dq.push_back(1);
    for (int i = 2; i<=k; i++){
        while (a[i] > a[dq.back()] && !dq.empty()) dq.pop_back();
        dq.push_back(i);
    }
    cout<<a[dq.front()]<<" ";
    for (int i = k + 1; i<=n; i++){
        if (dq.front() <= i - k){
            dq.pop_front();
        }
        while (a[i] > a[dq.back()] && !dq.empty()) dq.pop_back();
        dq.push_back(i);
        cout<<a[dq.front()]<<" ";
    }
}
