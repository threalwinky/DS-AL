#include <bits/stdc++.h>
using namespace std;
const int INT_SIZE = 32;
class Trie{
	public:
	struct TrieNode{
		int value;
		TrieNode* Child[2];
	};
	TrieNode* getNode()
	{
		TrieNode* newNode = new TrieNode;
		newNode->value = 0;
		newNode->Child[0] = newNode->Child[1] = NULL;
		return newNode;
	}
	TrieNode *root = getNode();
	void insert(int key){
		TrieNode* temp = root;
		for (int i = INT_SIZE - 1; i >= 0; i--){
			bool current_bit = (key & (1 << i));
			if (temp->Child[current_bit] == NULL)
			temp->Child[current_bit] = getNode();
			temp = temp->Child[current_bit];
		}
		temp->value = key;
	}
	void remove(int key){
		TrieNode* temp = root;
		for (int i = INT_SIZE - 1; i >= 0; i--){
			bool current_bit = (key & (1 << i));
			if (!temp -> child_node[bit])
					return;
				if (temp -> isEnd == 1){
					temp -> Child[bit] = nullptr;
					
					return;
				}
				crawl_node = crawl_node -> child_node[bit];
			
		}
	}
	int min_xor(int key){
		TrieNode* temp = root;
		for (int i = INT_SIZE - 1; i >= 0; i--) {
			bool current_bit = (key & (1 << i));
			if (temp->Child[current_bit] != NULL)
				temp = temp->Child[current_bit];
			else if (temp->Child[1 - current_bit] != NULL)
				temp = temp->Child[1 - current_bit];
		}
	//cout<<temp->value<<"\n";
	return key ^ temp->value;
	}
};
class Solution{
	public : 
		inline void FIO()
		{cin.tie(0) -> ios::sync_with_stdio(false);}
	private :
	//declare variable;
	int n;
	public :
	//handle
		void input(){
			cin>>n;
		}
		Trie T;
		void solve();
		void output(){}
};
void Solution::solve(){
	while (n --> 0){
		int type, val;
		cin>>type>>val;
		if (type == 0) 
		T.insert(val);
		else if (type == 1)
		T.remove(val);
		else cout<<T.min_xor(val)<<"\n";
	}
}
main(){
	Solution sol;
	sol.FIO();
	sol.input();
	sol.solve();
	sol.output();
}