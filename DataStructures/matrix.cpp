#include<bits/stdc++.h>
using namespace std;

struct M{
    using type = int;
    vector<vector<int>> data;
    int row, col;
    auto & operator [] (int i){return data[i];}
    M(int r, int c){
        vector<int> tmp(c, 0);
        data.resize(r, tmp);
        row = data.size();
        col = data[0].size();
    }
    M(vector<vector<int>> _data): data(_data){
        row = data.size();
        col = data[0].size();
    }
    friend ostream & operator << (ostream &out, const M a){
        for (auto x : a.data){
            for (auto y : x){
                cout << y << " ";
            }
            cout << "\n";
        }
        return out;
    }
    M operator*(const M& b) const{
        M tmp(row, b.col);
        for (int i=0; i<row; i++){
            for (int j=0; j<b.col; j++){
                for (int k=0; k<col; k++)
                    tmp.data[i][j] += data[i][k]*b.data[k][j];
            }
        }
        return tmp;
    }
    M supow(M a, int b){
        if (b == 1) return a;
        if (b & 1) return supow(a, b/2)*supow(a, b/2)*a;
        return supow(a, b/2)*supow(a, b/2);
    }
};

int main(){
    M a({
        {0, 1},
        {1, 1}
    });
    M b(2, 1);
    b.data[0][0] = 1;
    b.data[1][0] = 1;
    M c = a.supow(a, 6) * b;
    //cout << a.col;
    //cout << a << b << c;
    cout << c;
}