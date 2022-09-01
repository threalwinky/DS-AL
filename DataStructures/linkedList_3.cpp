#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};
typedef struct Node* node;
node NewNode(int x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = nullptr;
	return tmp;
}
int NodeSize(node a){
	int cnt = 0;
	while (a != nullptr){
		cnt++;
		a = a->next;
	}
	return cnt;
}
void PushFront(node &a, int x){
	node tmp = NewNode(x);
	if (a == nullptr){
		a = tmp;
	}
	else{
		tmp -> next = a;
		a = tmp;
	}
}
void PopFront(node &a){
	if (a != nullptr)
	a = a->next;
}
int Front(node a){
	if (a != nullptr)
	return a->data;
}
void PushBack(node &a, int x){
	node tmp = NewNode(x);
	if (a == nullptr){
		a = tmp;
	}
	else{
		node p = a;
		while (p -> next != nullptr){
			p = p->next;
		}
		p->next = tmp;
	}
}
void PopBack(node a){
	if (a == nullptr) return;
	node before = nullptr, after = a;
	while (after -> next != nullptr){
		before = after;
		after = after -> next;
	}
	if (before == nullptr){
		a = nullptr;
	}
	else{
		before -> next = nullptr;
	}
}
/* void PushMiddle(node &a, int x, int pos){
	int n = NodeSize(a);
	if (pos <= 0 || pos > n + 1){
		cout<<"Undefined position to insert";
		return;
	}

	if (n == 1){
		PushFront(a, x);
		return;
	}
	if (pos == n - 1){
		PushBack(a, x);
		return;
	}
	node p = a;
	for (int i = 1; i<pos - 1; i++){
		p = p -> next;
	}
	node tmp = NewNode(x);
	tmp -> next = p -> next;
	p -> next = tmp;
} */
int Back(node a){
	if (a == nullptr) return 0;
	node p = a;
	while (p -> next != nullptr){
		p = p->next;
	}
	return p->data;
}
void PrintList(node a){
	while (a != nullptr){
		cout<<a -> data<<" ";
		a = a->next;
	}
	cout<<endl;
}
int main(){
	node head = nullptr;
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	PushBack(head, 3);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	
	PushBack(head, 4);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	
	PushFront(head, 2);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	
	PushFront(head, 1);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	
	PushBack(head, 5);
	PrintList(head);
	cout<<NodeSize(head)<<endl;
	cout<<Front(head)<<" "<<Back(head)<<endl;
	
	
	PopFront(head);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	
	PopBack(head);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl;
	
	/* PushMiddle(head, 3, 2);
	PrintList(head);
	cout<<Front(head)<<" "<<Back(head)<<endl;
	cout<<NodeSize(head)<<endl; */
}