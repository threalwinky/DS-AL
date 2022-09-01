#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[6] = {0,1,2,4,5,7}, count = 0;
    for (int i =1; i<6;i++)
        for (int j =0; j<6;j++)
            if (j!=i)
            for (int k =0; k<6;k++)
                if (k!=j&&k!=i)
                for (int l =0; l<6;l++)
                    if (l!=k&&l!=j&&l!=i){
                    cout<<a[i]<<a[j]<<a[k]<<a[l]<<endl;
                    count++;
                    }
    cout<<count;
}