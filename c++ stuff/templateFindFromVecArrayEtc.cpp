// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>


template <typename iterType, typename elemType>
iterType findLa(iterType it_begin, iterType it_end, elemType value);


int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::string> svec = { "hello", "world" };
	std::string str = "worldo";
	auto it = findLa(svec.begin(), svec.end(), str);
	if (it != svec.end()) {
		std::cout << "gotcha" << std::endl;
	}else{
		std::cout << "not found" << std::endl;
	}
	
	getchar();
	return 0;
}

template <typename iterType, typename elemType>
iterType findLa(iterType it_begin, iterType it_end, elemType value){
	while (it_begin != it_end){
		if (*it_begin == value){
			break;
		}
		it_begin++;
	}
	return it_begin;

}
