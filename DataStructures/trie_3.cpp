#include<iostream>
using namespace std;
class trie{
	private : 
		static const int ALSZ = 26;
	public :
		struct trie_node{
			trie_node *child_node[ALSZ];
			int isEnd;
		};
		trie_node *new_node(){
			trie_node *pnode = new trie_node;
			pnode -> isEnd = 0;
			for (int i = 0; i<ALSZ; i++)
				pnode -> child_node[i] = NULL;
			return pnode;
		}
		trie_node *root = new_node();
		void insert(string key){
			trie_node *crawl_node = root;
			for (int i = 0; i<key.length(); i++){
				int idx = key[i] - 'a';
				if (!crawl_node -> child_node[idx])
					crawl_node -> child_node[idx] = new_node();
				crawl_node = crawl_node -> child_node[idx];
			}
			crawl_node -> isEnd++;
		}
		bool search(string key){
			trie_node *crawl_node = root;
			for (int i = 0; i<key.length(); i++){
				int idx = key[i] - 'a';
				if (!crawl_node -> child_node[idx])
					return 0;
				crawl_node = crawl_node ->child_node[idx];
			}
			return (crawl_node -> isEnd > 0) ? 1 : 0;
		}
		int count(string key){
			trie_node *crawl_node = root;
			for (int i = 0; i<key.length(); i++){
				int idx = key[i] - 'a';
				if (!crawl_node -> child_node[idx])
					return 0;
				crawl_node = crawl_node ->child_node[idx];
			}
			return crawl_node -> isEnd;
		}
};
int main(){
	trie t;
	t.insert("ab");
	t.insert("a");
	t.insert("a");
	cout<<t.count("ab");
}