/**
 *   author: winky
 *   created: 2023-05-08 16:36:02
**/

// Obey my waifu
//⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
//⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
//⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
//⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
//⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
//⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
//⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
//⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
//⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
//⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
//⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
//⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
//⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
//⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
//⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄⠄⠄⣾⡌⢠⣿⡿⠃

#include                    <bits/stdc++.h>
using namespace             std;
//#pragma GCC               optimize("Ofast,unroll-loops,inline")
//#pragma GCC               target("bmi,bmi2,lzcnt,popcnt")
//#pragma GCC               target("movbe")
//#pragma GCC               target("aes,pclmul,rdrnd")
//#pragma GCC               target("avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,tune=native")
#define fu(i, a, b)         for (int i = a; i<=b; i++)
#define fd(i, a, b)         for (int i = a; i>=b; i--)
#define fa(it, arr)			for (auto it : arr)
#define tri(a, b, c)        ((a) ? (b) : (c))
#define carr(arr, n)        cout<<"[";fu(i, 1, n ){cout<<arr[i]<<tri(i == n, "", ", ");}cout<<"]\n";
#define fi                  first
#define se                  second
#define all(it)             it.fi << " " << it.se <<"\n"
#define debug(x)            cerr<<"+Debug for "<<(#x)<<" : "<<x<<"\n";
#define comma(f, x)			fixed << setprecision((x)) << f
//#define int               long long
typedef pair<int, int>      ii;
typedef long long           ll;
typedef vector<int>         vi;
typedef vector<ii>          vii;
typedef vector<ll>          vll;
const int maxN =            3e5;
const int mod =             1e9 + 7;
const int inf =             INT_MAX;
const double PI =           3.14159265358979;
const auto INP_FILE =		"sample.inp";
const auto OUT_FILE =		"sample.out";
void IO(short choice){      if (choice == 1) freopen(INP_FILE, "r", stdin);
else						if (choice == 2){freopen(INP_FILE, "r", stdin); freopen(OUT_FILE, "w", stdout);}
else						if (choice == 3) ios::sync_with_stdio(false);cin.tie(nullptr);}
/*----- ----- ----- ----- ----- ----- ----- ----- ----- -----*/

long long expo_mod(int a, int b, int x){
    if (b == 1) return a%x;
    long long res = 2*expo_mod(a, b/2, x)%x;
    if (b%2) return (res%x + a%x)%x;
    return res%x;
}

signed main(){
    IO(2);//1 for INP, 2 for INP and OUT, 3 for stdio
    int a, b, x;
    cin>>a>>b>>x;
    cout<<expo_mod(a, b, x);
    
}
