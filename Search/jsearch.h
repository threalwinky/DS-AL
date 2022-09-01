/**
 *      author: iwttry
 *      created: 01/09/2022
**/

//Time complexity : O(log2(sqrt(n)))
//Space complexity : O(1)

int JS(std::vector<int> v, int x){
	int bS = (int)sqrt(v.size());
	int start = 0;
	int next = bS;
	while(start < v.size() && x > v[next-1]) {
		start = next;
		next = next + bS;
		if (next >= v.size())
			next = v.size();
	}
	for(int i=start; i<next; i++) if (x == v[i]) return i;
	return -1;
}