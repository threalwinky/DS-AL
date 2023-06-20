#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
};
typedef struct Node* node;
struct LL{
    node head = nullptr;
    int size = 0;
    node InitNode(int x, node y){
        node tmp = new Node;
        tmp -> val = x;
        tmp -> next = y;
        return tmp;
    }
    inline bool IsEmpty()
    { return head == nullptr; }
    void PushBack(int x){
        node tmp = InitNode(x, nullptr);
        if (IsEmpty()) head = tmp;
        else{
            node p = head;
            while (true){
                if (p -> next == nullptr){
                    p -> next = tmp;
                    break;
                }
                else p = p->next;
            }
        }
        size++;
    }
    void PushFront(int x){
        node tmp = InitNode(x, head);
        head = tmp;
        size++;
    }
    void PopBack(){
        if (!IsEmpty()){
            node before = nullptr, after = head;
            while (after->next != nullptr){
                before = after;
                after = after -> next;
            }
            if (before == nullptr) head = nullptr;
            else before -> next = nullptr;
            size--;
        }
    }
    void PopFront(){
        if (!IsEmpty()){ head = head -> next; size--; }
    }
    void Insert(int x, int pos){
        if (IsEmpty()){
            PushBack(x);
            return;
        }
        if (pos == 0){
            PushFront(x);
            return;
        }
        if (pos >= 1 && pos <= size){
            node tmp = InitNode(x, nullptr);
            node p = head;
            for (int i=1; i<pos; i++){
                p = p -> next;
            }
            tmp -> next = p -> next;
            p -> next = tmp;
        }
        size++;
    }
    void Change(int x, int pos){
        if (!IsEmpty()){
            if (pos >= 1 && pos <= size){
                node p = head;
                for (int i=1; i<pos; i++){
                    p = p -> next;
                }
                p->val = x;
            }
        }
    }
    void Delete(int pos){
        if (!IsEmpty()){
            if (pos >= 1 && pos <= size){
                node p = head;
                for (int i=1; i<pos - 1; i++){
                    p = p -> next;
                }
                p->next = p->next->next;
            }
        }
    }
    int Back(){
        if (IsEmpty()) return -INT_MAX;
        node p = head;
        while (p -> next != nullptr){
            p = p -> next;
        }
        return p->val;
    }
    inline int Front(){ return (!IsEmpty()) ? head->val : -INT_MAX; }
    inline int Size(){return size;}
    void Print(){
        node p = head;
        cout << "[ ";
        if (!IsEmpty()) 
        while (p != nullptr){
            cout << p->val << 
            ((p->next == nullptr) ? " " : ", ");
            p = p -> next;
        } cout << "]\n";
    }
};

int main(){
    LL a;
    a.PushBack(5);
    a.PushBack(8);
    a.PushBack(9);
    a.PushBack(10);
    a.PushFront(3);
    a.PushFront(2);
    a.PushFront(8);
    a.PushBack(2);
    a.Insert(100, 5);
    a.Print();
    a.Change(200, 7);
    //cout << 123;
    a.Print();
    a.Delete(3);
    a.Delete(5);
    a.Print();
    a.PopFront();
    a.PopBack();
    cout << a.Back();
}