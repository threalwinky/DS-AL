#include<bits/stdc++.h>
#define endl std::cout<<"\n";
bool cmp(int a, int b){
    return a > b; 
}

int *LowerBound(std::vector<int> v, int x){
    int l = 0, r = v.size() - 1;
    while (l <= r){
        int m = l + (r - l)/2;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    if (v[l] < x) return &v[l] + 1;
    return &v[l];
}

int *UpperBound(std::vector<int> v, int x){
    int l = 0, r = v.size() - 1;
    while (l <= r){
        int m = l + (r - l)/2;
        if (v[m] <= x) l = m + 1;
        else r = m - 1;
    }
    if (v[l] <= x) return &v[l] + 1;
    return &v[l];
}

int *UpperDive(std::vector<int> v, int x){
    int l = 0, r = v.size() - 1;
    while (l <= r){
        int m = l + (r - l)/2;
        if (v[m] <= x) l = m + 1;
        else r = m - 1;
    }
    if (v[r] > x) return &v[r] - 1;
    return &v[r];
}

int *LowerDive(std::vector<int> v, int x){
    int l = 0, r = v.size() - 1;
    while (l <= r){
        int m = l + (r - l)/2;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    if (v[r] >= x) return &v[r] - 1;
    return &v[r];
}
std::vector<int> v = {1,3,6,8,9,10,15};
int main(){
    for (auto x : v) std::cout<<x<<" ";
    endl;
    std::cout<<"Lower bound using std::lower_bound : ";
    std::cout<<*std::lower_bound(v.begin(), v.end(), 6);
    endl;
    std::cout<<"Lower bound using std::lower_bound : ";
    std::cout<<*std::lower_bound(v.begin(), v.end(), 7);
    endl;
    std::cout<<"Lower bound using std::lower_bound : ";
    std::cout<<*std::lower_bound(v.begin(), v.end(), 16);
    endl;
    std::cout<<"Upper bound using std::upper_bound : ";
    std::cout<<*std::upper_bound(v.begin(), v.end(), 6);
    endl;
    std::cout<<"Upper bound using std::upper_bound : ";
    std::cout<<*std::upper_bound(v.begin(), v.end(), 7);
    endl;
    std::cout<<"Upper bound using std::upper_bound : ";
    std::cout<<*std::upper_bound(v.begin(), v.end(), 16);
    endl;
    std::cout<<"Upper dive using std::upper_bound : ";
    std::cout<<*std::upper_bound(v.begin(), v.end(), 6, cmp);
    endl;
    std::cout<<"Upper dive using std::upper_bound : ";
    std::cout<<*std::upper_bound(v.begin(), v.end(), 7, cmp);
    endl;
    std::cout<<"Upper dive using std::upper_bound : ";
    std::cout<<*std::upper_bound(v.begin(), v.end(), 16, cmp);
    endl;
    std::cout<<"Lower bound using self-making algorithm: ";
    std::cout<<*LowerBound(v, 6);
    endl;
    std::cout<<"Lower bound using self-making algorithm : ";
    std::cout<<*LowerBound(v, 7);
    endl;
    std::cout<<"Lower bound using self-making algorithm: ";
    std::cout<<*LowerBound(v, 16);
    endl;
    std::cout<<"Upper bound using self-making algorithm: ";
    std::cout<<*UpperBound(v, 6);
    endl;
    std::cout<<"Upper bound using self-making algorithm : ";
    std::cout<<*UpperBound(v, 7);
    endl;
    std::cout<<"Upper bound using self-making algorithm: ";
    std::cout<<*UpperBound(v, 16);
    endl;
    std::cout<<"Lower dive using self-making algorithm: ";
    std::cout<<*LowerDive(v, 6);
    endl;
    std::cout<<"Lower dive using self-making algorithm : ";
    std::cout<<*LowerDive(v, 7);
    endl;
    std::cout<<"Lower dive using self-making algorithm: ";
    std::cout<<*LowerDive(v, 16);
    endl;
    std::cout<<"Upper dive using self-making algorithm: ";
    std::cout<<*UpperDive(v, 6);
    endl;
    std::cout<<"Upper dive using self-making algorithm : ";
    std::cout<<*UpperDive(v, 7);
    endl;
    std::cout<<"Upper dive using self-making algorithm: ";
    std::cout<<*UpperDive(v, 16);
    endl;

    std::cout<<"Upper dive using self-making algorithm: ";
    std::cout<<*UpperDive(v, 1);
    endl;
    std::cout<<"lower dive using self-making algorithm: ";
    std::cout<<*LowerDive(v, 1);
    endl;
}
