#include<bits/stdc++.h>
#include <vector>
using namespace std;

void print(string s){ cout<<s<<"\n"; }

void pre_func1(string s){
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i=0; i<n; i++){
        for (int j = 0; j<=i; j++){
            if (s.substr(0, j) == s.substr(i - j + 1, j)) pi[i] = j;
        }
    }
    for (auto x : pi) cout<<x<<" ";
    cout<<endl;
}

void pre_func2(string s){
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i=1; i<n; i++){
        int j = pi[i - 1] + 1;
        while (j && s.substr(0, j) != s.substr(i - j + 1, j)) 
            j--;
        pi[i] = j;
    } 
    for (auto x : pi) cout<<x<<" ";
    cout<<endl;
}

void pre_func3(string s){
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i=1; i<n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    for (auto x : pi) cout<<x<<" ";
    cout<<endl;
}

int main(){
    string a = "abcabcd";
    string b = "aabaaab";
    string c = "aa";
    print(a);
    print(b);
    pre_func1(a);
    pre_func1(b);
    pre_func2(a);
    pre_func2(b);
    pre_func3(a);
    pre_func3(c + "#" + b);
}
