// usage:ʹ��map��ע������
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
	//everyone �ֶα����뵽��words���map��
	cout << words["everyone"] << endl;

	map<string, int>::const_iterator it;
	it = words.find("again");
	//everyone �ֶ�û�����뵽words���map��
	if (it != words.end()) cout << it->first << " " << it->second;

	getchar();
	return 0;
}

