#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node* node;

node make_node(int x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = nullptr;
	return tmp;
}

bool empty_list(node a){
	return (a == nullptr);
}

int list_size(node a){
	int cnt = 0;
	while (a != nullptr){
		++cnt;
		a = a -> next;

	}
	return cnt;
}

void insert_front(node &a, int x){
	node tmp = make_node(x);
	if (a == nullptr){
		a = tmp;
	}
	else{
		tmp -> next = a;
		a = tmp;
	}
}

void insert_back(node &a, int x){
	node tmp = make_node(x);
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

void insert_middle(node &a, int x, int pos){
	int n = list_size(a);
	if (pos <= 0 || pos > n + 1){
		cout<<"Undefined position to insert";
		return;
	}

	if (n == 1){
		insert_front(a, x);
		return;
	}
	if (pos == n - 1){
		insert_back(a, x);
		return;
	}
	node p = a;
	for (int i = 1; i<pos - 1; i++){
		p = p -> next;
	}
	node tmp = make_node(x);
	tmp -> next = p -> next;
	p -> next = tmp;
}

void delete_front(node &a){
	if (a == nullptr) return;
	a = a->next;
}

void delete_back(node &a){
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

void delete_middle(node &a, int pos){
	if (pos <= 0 || pos > list_size(a)){
		cout<<"Undefined position to delete";
		return;
	}
	node before = nullptr, after = a;

	for (int i = 1; i<pos; i++){
		before = after;
		after = after -> next;
	}
	if (before == nullptr) a = a->next;
	else{
		before -> next = after -> next;
	}
}

void print_list(node a){
	while (a != nullptr){
		cout<<a -> data<<" ";
		a = a->next;
	}
}

int main(){
	node head = nullptr;
	while (1){
		cout<<endl<<"--------------------------"<<endl;
		cout<<"1. Chen phan tu vao dau"<<endl;
		cout<<"2. Chen phan tu vao cuoi"<<endl;
		cout<<"3. Chen phan tu vao giua"<<endl;
		cout<<"4. Xoa phan tu o dau"<<endl;
		cout<<"5. Xoa phan tu o cuoi"<<endl;
		cout<<"6. Xoa phan tu o giua"<<endl;
		cout<<"7. In ra danh sach";
		cout<<endl<<"--------------------------"<<endl;
		int lc; cin>>lc;
		if (lc == 1){
			cout<<"Nhap vao so can chen : ";
			int x; cin>>x;
			insert_front(head, x);
		}
		else if (lc == 2){
			cout<<"Nhap vao so can chen : ";
			int x; cin>>x;
			insert_back(head, x);
		}
		else if (lc == 3){
			cout<<"Nhap vao so can chen : ";
			int x; cin>>x;
			cout<<"\nNhap vao vi tri can chen : ";
			int p; cin>>p;
			insert_middle(head, x, p);
		}
		if (lc == 4){
			delete_front(head);
		}
		else if (lc == 5){
			delete_back(head);
		}
		else if (lc == 6){
			cout<<"\nNhap vao vi tri can xoa : ";
			int p; cin>>p;
			delete_middle(head, p);
		}
		else if (lc == 7){
			print_list(head);
		}
	}
}