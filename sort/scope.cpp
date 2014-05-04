#include<iostream>

using namespace std;

void printArr(int* arr, int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void newArr(int* arr, int n){
	arr = new int[n]();
	cout << "arr in function: "<<endl;
	printArr(arr, n);
}

int main(){
	int* a = new int[3];
	newArr(a, 10);

	cout << "arr out function: "<<endl;
	printArr(a, 10);
	return 0;
}