/**
 *      author: iwttry
 *      created: 01/09/2022
**/

//Time complexity : O(log2(n))
//Space complexity : O(1)
int BS(std::vector<int> v, int x){
	int l = 0, r = v.size() - 1;
	while (l < r){
		int m = l + (r - l)/2;
		if (v[m] == x) return m;
		if (v[m] > x) r = m; else l = m+1;
	}
	if (v[l] == v[r] && v[l] == x) return r; return -1;
}
int LB(std::vector<int> v, int x){
	int l = 0, r = v.size() - 1;
	while (l <= r){
		int m = l + (r - l)/2;
		if (v[m] == x) return m;
		if (v[m] >= x) r = m - 1;
		else l = m+1;
	}
	if (l >= v.size() || l < 0) return -1; return l;
}
int UB(std::vector<int> v, int x){
	int l = 0, r = v.size() - 1;
	while (l <= r){
		int m = l + (r - l)/2;
		if (v[m] > x) r = m - 1;
		else l = m+1;
	}
	if (l >= v.size() || l < 0) return -1; return l;
}
int LD(std::vector<int> v, int x){
	int l = 0, r = v.size() - 1;
	while (l <= r){
		int m = l + (r - l)/2;
		if (v[m] < x) l = m+1;
		else r = m - 1;
	}
	if (r >= v.size() || r < 0) return -1; return r;
}
int UD(std::vector<int> v, int x){
	int l = 0, r = v.size() - 1;
	while (l <= r){
		int m = l + (r - l)/2;
		if (v[m] == x) return m;
		if (v[m] <= x) l = m+1;
		else r = m - 1;
	}
	if (r >= v.size() || r < 0) return -1; return r;
}