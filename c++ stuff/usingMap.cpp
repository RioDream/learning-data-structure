// usage:使用map的注意事项
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<string, int> words;
	words["hello"] = 1;
	words["world"] = 1;
	if (words["everyone"]){
		;
	}
	//everyone 字段被插入到了words这个map中
	cout << words["everyone"] << endl;

	map<string, int>::const_iterator it;
	it = words.find("again");
	//everyone 字段没被插入到words这个map中
	if (it != words.end()) cout << it->first << " " << it->second;

	getchar();
	return 0;
}

