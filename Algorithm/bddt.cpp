#include<bits/stdc++.h>

std::vector<std::pair<int, int>> dsc;
std::vector<int> dsk[10001];
int mtk[1001][1001];

int main(){
    int n, m;
    std::cin>>n>>m;
    for (int i = 0; i<m; i++){
        int x, y;
        std::cin>>x>>y;
        dsc.push_back({x, y});
        dsk[x].push_back(y);
        dsk[y].push_back(x);
        mtk[x][y] = 1;
        mtk[y][x] = 1;
    }
    std::cout<<"Duyet theo danh sach canh : \n";
    for (std::pair<int ,int> p : dsc)
        std::cout<<p.first<<" "<<p.second<<"\n";
    std::cout<<"Duyet theo danh sach ke : \n";
    for (int i = 1; i<= n; i++){
        std::cout<<i<<" ";
        for (int x:dsk[i]) std::cout<<x<<" ";
        std::cout<<"\n";
    }
    std::cout<<"Duyet theo ma tran ke : \n";
    for (int i = 1; i<=n; i++){
        for (int j = 1; j <=n; j++){
            std::cout<<mtk[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}
