#include<iostream>

using namespace std;

void printArr(int* arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int* arr = new int[10]();
	arr[1]=1;
	printArr(arr,10);

	//the new will cover the old data 

	arr = new int[11]();
	printArr(arr,11);

	//
	int a[32]={};
	printArr(a,32);



}