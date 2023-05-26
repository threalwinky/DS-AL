#include<bits/stdc++.h>
#define endl std::cout<<"\n";
struct compare{
    bool operator () (int a, int b){
        return a<b;
    }
};
bool cmp(int a, int b){
    return a < b;
}
int main(){
    std::list<int> l;
    l.push_back(1); 
    l.push_back(2); 
    l.push_back(3); 
    l.push_back(4); 
    std::cout<<l.front();
    endl;
    std::cout<<l.back();
    std::priority_queue<int, std::vector<int>, compare> pq;
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(3);
    while (!pq.empty())
    {
        std::cout<<pq.top();
        pq.pop();
    }
    std::set<int, greater<int>> st;
    st.insert(2);
    st.insert(5);
    st.insert(3);
    st.insert(1);
    st.insert(4);
    endl;
    for (int x : st){
        std::cout<<x;
    }
}
