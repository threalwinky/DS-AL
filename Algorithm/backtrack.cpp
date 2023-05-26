#include<bits/stdc++.h>
int a[1001];
bool check(std::string s){
    std::map<int, int> m;
    for (int i = 0; i<s.length(); i++){
        m[s[i]]++;
    }
    if (m.size() == s.length()) return true;
    return false;
}
void chl(std::string s, int n, int k){
    if (s.length() == k){
        std::cout<<s<<"\n";
        return;
    }
    for (int i = 1; i<=n; i++){
        chl(s + std::to_string(i), n, k);
    }
}

void chkl(std::string s, int n, int k){
    if (s.length() == k){
        std::cout<<s<<"\n";
        return;
    }
    for (int i = 1; i<=n; i++){
        if (s.find(std::to_string(i)) == std::string::npos)
        chkl(s + std::to_string(i), n, k);
    }
}

void thl(std::string s,int tmp, int n, int k){
    if (s.length() == k){
        std::cout<<s<<"\n";
        return;
    }
    for (int i = tmp; i<=n; i++){
        thl(s + std::to_string(i),i, n, k);
    }
}

void thkl(std::string s,int tmp, int n, int k){
    if (s.length() == k){
        std::cout<<s<<"\n";
        return;
    }
    for (int i = tmp + 1; i<=n; i++){
        thkl(s+std::to_string(i), i, n, k);
    }
}

int main(){
    freopen("winky.inp", "r", stdin);
    freopen("winky.out", "w", stdout);
    int n, k;
    std::cin>>n>>k;
    for (int i = 1; i<=n; i++){
        std::cin>>a[i];
    }
    for (int i = 1; i<=n; i++){
        thl(std::to_string(i),i, n, k);
    }
}
