#include<bits/stdc++.h>
#define endl std::cout<<"\n"
std::vector<int> v;

int main(){
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    std::vector<int>::iterator it = v.begin();
    std::cout<<*v.end();
    std::vector<std::vector<int>> w;
    w.push_back(v);
    std::cout<<"\t"<<w[0][2];
    endl;
    std::cout<<"It\"s mine";
    endl;
    std::cout<<v.at(1);
}
