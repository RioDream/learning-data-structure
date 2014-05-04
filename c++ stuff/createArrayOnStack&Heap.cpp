// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

template<typename T>
void printArr(T* arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

//void func(int*& arr){ //指针引用
int* func(int* arr){ //指针传值
	arr = new int[10](); //arr被改变了
	cout<<"arr address after new"<<arr<<endl;
	return arr;
}

class temp{

public:
	temp(){
		arr = new int[10]();
	}

	~temp(){
		delete[] arr; //析构的时候要delete new出来的内存
	}

	int* arr;
};


int main()
{
	//Ê¹ÓÃnewÔÚ¶ÑÉÏ½¨Á¢Êý×é
	int* a;
	a = new int[2]; 
	a[0] = 0;
	a[1] = 1;
	printArr(a,2);

	cout<<"arr address "<<a<<endl;

	int* b = func(a);
	cout<<"arr address after "<<a<<endl;
	cout<<"b address after "<<b<<endl;

	printArr(a,10);
	cout<<"---"<<endl;
	cout<<"b"<<endl;
	printArr(b,10);

	cout<<"in class"<<endl;
	temp t;
	printArr(t.arr,10);

	//ÔÚÕ»ÉÏ¼òÀúÊý×é
	int c[] = { 0, 1 }; 
	return 0;
}

