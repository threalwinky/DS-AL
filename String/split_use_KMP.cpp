#include<bits/stdc++.h>
using namespace std;
vector<string> split(string s, string p=" "){
    s = p + "#" + s;
    int n = s.length();
    vector<int> pi(n);
    vector<string> res;
    for (int i=1; i<n; i++){
        int j=pi[i-1];
        while (j > 0 && s[i] != s[j])
            j=pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    string t;
    int r = p.length() + 1;
    for (int i=p.length()+1; i<s.length(); i++){
        if (pi[i] == p.length()){
            t.clear();
            for (int j=r; j<=i-p.length(); j++){
                t+=s[j];
            }
            res.push_back(t);
            r = i + 1;
        }
    }
    t.clear();
    for (int j=r; j<s.length(); j++){
        t+=s[j];
    }
    res.push_back(t);
    return res;
}
int main(){
    string s = "a b c d e f : g";
    vector<string> v = split(s, " ");
    for (auto it : v){
        cout << it << "\n";
    }
}
