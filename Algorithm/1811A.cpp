#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while (T-->0){
        bool flag = 1;
        int n, d;
        cin>>n>>d;
        string s;
        cin>>s;
        for (int i = 0; i<s.length(); i++){
            if (flag == 1 && (s[i] - '0') < d){
                flag = 0;
                cout<<d;
            }
            cout<<s[i];
        }
        if (flag) cout<<d;
        cout<<"\n";
    }
}
