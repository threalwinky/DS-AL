#include <iostream>
using namespace std;
int main(){
	int *array = new int[100000001];
	array[100000001] = 2;
	cout<<array[100000001];
	
	delete[] array;
	return 0;
	
}