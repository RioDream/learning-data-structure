// usage���Ƚ�vector��list��deque�����ĵ������Ĳ�ͬ
//

#include "stdafx.h"

#include <list>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	vector<int> vec(10, 0);
	vector<int>::const_iterator it_vec = vec.begin();
	cout << "���Զ�vector��iter��������,�Լ�����" << endl;
	it_vec++;
	it_vec--;
	cout << "���Զ�vector��iter���мӼ�����" << endl;
	it_vec = it_vec + 1;
	cout << *it_vec << endl;

	cout << endl;

	list<int> li(10, 1);
	list<int>::const_iterator it_li = li.begin();
	cout << "���Զ�list��iter��������,�Լ�����" << endl;
	it_li++;
	it_li--;
	cout << "�����Զ�list��iter���мӼ�����" << endl;
	//it_li = it_li + 1;
	cout<<*it_li<<endl;

	cout << endl;

	deque<int> de(10, 2);
	deque<int>::const_iterator it_de = de.begin();
	cout << "���Զ�deque��iter��������,�Լ�����" << endl;
	it_de++;
	it_de--;
	cout << "���Զ�deque��iter���мӼ�����" << endl;
	it_de = it_de + 1;
	cout << *it_de << endl;

	getchar();
	return 0;
}

