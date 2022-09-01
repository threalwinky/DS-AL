#include <bits/stdc++.h>
#include "bsearch.h"
#include "jsearch.h"
#include "lsearch.h"
using namespace std;
vector <int> v = {2,4,5,7,9,10,44,55,67};
vector <int> v1 = {1};
int main(){
	freopen("search.out", "w", stdout);
	for (auto it : v) cout<<it<<" ";
	cout<<"\n";
	cout<<"BS 2 : "<<BS(v, 2)<<"\n";
	cout<<"LB 2 : "<<LB(v, 2)<<"\n";
	cout<<"UB 2 : "<<UB(v, 2)<<"\n";
	cout<<"LD 2 : "<<LD(v, 2)<<"\n";
	cout<<"UD 2 : "<<UD(v, 2)<<"\n";
	cout<<"BS 2 : "<<BS(v, 2)<<"\n";
	cout<<"BS 3 : "<<BS(v, 3)<<"\n";
	cout<<"BS 4 : "<<BS(v, 4)<<"\n";
	cout<<"JS 2 : "<<JS(v, 2)<<"\n";
	cout<<"JS 3 : "<<JS(v, 3)<<"\n";
	cout<<"JS 4 : "<<JS(v, 4)<<"\n";
	cout<<"LS 2 : "<<LS(v, 2)<<"\n";
	cout<<"LS 3 : "<<LS(v, 3)<<"\n";
	cout<<"LS 4 : "<<LS(v, 4)<<"\n";
}