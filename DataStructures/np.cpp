#include<bits/stdc++.h>
using namespace std;

bool np(int a[], int n){
    int tmp = 0;
    for (int i=n-1; i>=1; i--){
        if (a[i] < a[i-1]) tmp++;
    }
    if (tmp == n - 1) return 0;
    for (int i=n-1; i>=0; i--){
        if (a[i] > a[i - 1]){
            swap(a[i], a[i-1]);
            return 1;
        }
        else{
            swap(a[i], a[i-1]);
        }
    }
    return 1;
}

int main(){
    int a[] = {1, 2, 3, 4};
    //next_permutation(a, a + 4);

    while (np(a, 4)){
        for (int i=0; i<4; i++) cout << a[i] << " ";
        cout << endl;
    }
    
}
