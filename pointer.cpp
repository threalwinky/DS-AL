#include<iostream>
using namespace std;
struct Sinhvien{
	int tuoi;
	string ten;
};
void double1(int x){
	x*=2;
}
void double2(int &x){
	x*=2;
}
void double3(int *x){
	*x *= 2;
}
int main(){
	int a, b;bool c;char d;string e;
	cout<<&a;cout<<endl;
	cout<<&b;cout<<endl;
	cout<<&c;cout<<endl;
	cout<<&d;cout<<endl;
	cout<<&e;cout<<endl;
	int *ptr = nullptr;
	cout<<(ptr == nullptr)<<endl;

	ptr = &a;

	cout<<(ptr == nullptr)<<endl;
	cout<<ptr<<endl;
	cout<<*ptr<<endl;

	a = 3;

	cout<<*ptr;
	cout<<*&a;
	cout<<*(&a);
	cout<<endl;
	double1(a);
	cout<<a<<endl;
	double2(a);
	cout<<a<<endl;
	double3(&a);
	cout<<a<<endl;;

	Sinhvien x;
	x.ten = "123 ";

	Sinhvien *ptrsv = &x;

	(*ptrsv).tuoi = 456;
	cout<<(*ptrsv).ten<<ptrsv->tuoi;

	int arr[5];
	
	cout<<endl<<&arr<<endl;
	for (int &x : arr){
		cout<<&x<<" ";
	}

	cout<<endl<<*arr<<endl;
	for (int &x : arr){
		cout<<x<<" ";
	}
}