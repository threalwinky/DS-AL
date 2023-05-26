#include<bits/stdc++.h>
#define int long long 
signed main(){
    int k;
    std::cin>>k;
    while (k--){
    int n;
    std::stack<int> st;
    std::cin>>n;
    int r = 0;
    for (int i = 1; i<=n; i++){
        int j = i + r;
        if (j > 9){
            r = j / 10;
            j %= 10;
        }
        else r = 0;
        st.push(j);
    }
    for (int i = n - 1; i>= 1; i--){
        int j = i + r;
        if (j > 9){
            r = j / 10;
            j%=10;
        }
        else {
            r = 0;
        }
        st.push(j);
    }
    while (r != 0){
        st.push(r%10);
        r/=10;
    }
    while (!st.empty()){
        std::cout<<st.top();
        st.pop();
    }
    }
}
