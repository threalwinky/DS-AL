#include<bits/stdc++.h>
#define int long long
std::map<int, int> m;

signed main(){
    int n;
    std::cin>>n;
    int i = 2;
    while (n!=1){
        while (n%i==0){
            m[i]++;
            n/=i;
        }
        i++;
    }
    int sum = 1;
    for (std::pair<int, int> p:m){
        sum*=(std::pow(p.first, p.second+1)-1)/(p.first - 1);
    }
    std::cout<<sum;
}
