// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int min(int arr[200],int);

template<typename T>
size_t findFromVec(vector<T>& vec, T value);

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1, 2 ,3};
	int min_num = min(arr,3);

	vector<string> strVec = { "hello", "world" };
	string str = "hello";

	std::cout << findFromVec(strVec, str) << std::endl;
	int a;
	std::cin>>a;

	return 0;

}

template<typename T>
size_t findFromVec(vector<T>& vec, T value)
{
	auto i = vec.begin();
	auto vec_end = vec.end();
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value){
			return i;
		}
	}
	return -1;


}

int min(int* arr,int len)
{
	int* i = arr;
	int min_num = *i;
	for (; i != arr+3 ; i++){
		if(min_num>*i){
			min_num = *i;
		}
	}
	return min_num;
}

