/**
 *      author: iwttry
 *      created: 01/09/2022
**/

//Time complexity : O(n)
//Space complexity : O(1)

int LS(std::vector<int> v, int x){
	for (int i = 0; i<v.size(); i++){
		if (v[i] == x) return i;
	}
	return -1;
}