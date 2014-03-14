// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//使用new在堆上建立数组
	int* a = nullptr;
	a = new int[2]; 
	a[0] = 0;
	a[1] = 1;

	//在栈上简历数组
	int b[] = { 0, 1 }; 
	return 0;
}

