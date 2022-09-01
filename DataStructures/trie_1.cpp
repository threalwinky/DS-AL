#include<bits/stdc++.h>
using namespace std;
const int ALPHA_SIZE = 26;
struct trie_node{
	trie_node *child_node[ALPHA_SIZE];
	bool isEnd;
};
trie_node *getNode(void){
	trie_node *pnode = new trie_node;
	pnode -> isEnd = NULL;
	for (int i = 0; i<ALPHA_SIZE; i++){
		pnode -> child_node[i] = NULL;
	}
	return pnode;
}
void insert(trie_node *root, string key){
	trie_node *crawl_node = root;
	for (int i = 0; i<key.length(); i++){
		int idx = key[i] - 'a';
		if (!crawl_node->child_node[idx])
			crawl_node->child_node[idx] = getNode();
		crawl_node = crawl_node->child_node[idx];
	}
	crawl_node->isEnd = true;
}
bool search(trie_node *root, string key){
	trie_node *find_node = root;
	for (int i = 0; i<key.length(); i++){
		int idx = key[i] - 'a';
		if (!find_node->child_node[idx]) return 0;
		find_node = find_node->child_node[idx];
	}
	if (!find_node->isEnd) return 0;
	return 1;
}
main(){
	trie_node *root = getNode();
	insert(root, "abc");
	cout<<search(root, "ab");
}