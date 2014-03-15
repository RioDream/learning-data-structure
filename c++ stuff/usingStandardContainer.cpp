// usage：比较vector、list、deque容器的迭代器的不同
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
	cout << "可以对vector的iter进行自增,自减操作" << endl;
	it_vec++;
	it_vec--;
	cout << "可以对vector的iter进行加减操作" << endl;
	it_vec = it_vec + 1;
	cout << *it_vec << endl;

	cout << endl;

	list<int> li(10, 1);
	list<int>::const_iterator it_li = li.begin();
	cout << "可以对list的iter进行自增,自减操作" << endl;
	it_li++;
	it_li--;
	cout << "不可以对list的iter进行加减操作" << endl;
	//it_li = it_li + 1;
	cout<<*it_li<<endl;

	cout << endl;

	deque<int> de(10, 2);
	deque<int>::const_iterator it_de = de.begin();
	cout << "可以对deque的iter进行自增,自减操作" << endl;
	it_de++;
	it_de--;
	cout << "可以对deque的iter进行加减操作" << endl;
	it_de = it_de + 1;
	cout << *it_de << endl;

	getchar();
	return 0;
}

