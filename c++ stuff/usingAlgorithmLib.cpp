// usage: ���Է����㷨�� algorithm 
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//template <typename C,typename T>
//void display(const C<T>& vec);

template <typename itType>
void display(itType, itType);


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = {0,2,1,3,4,5};
	//using find() 
	vector<int>::const_iterator it = find(vec.begin(), vec.end(), 2);
	if (it != vec.end()){
		cout << *it << endl;
	}
	cout << endl;

	//using sort() binary_search()
	vector<int> tmp1 = vec; //������ֵ����
	display(tmp1.begin(), tmp1.end());

	cout << endl;

	vector<int> tmp2(vec.size()); //���������ָ����С
	copy(vec.begin(), vec.end(), tmp2.begin());
	display(tmp2.begin(), tmp2.end());
	if (tmp1 == tmp2){
		cout << "ֱ�Ӹ�ֵ��ʹ��copy()���ƣ����һ��" << endl;
	}
	cout << endl;

	bool gotcha1 = binary_search(tmp2.begin(), tmp2.end(), 2);
	if (gotcha1) cout << "sort()֮ǰʹ��binary_search() �ҵ�elem��";

	cout << endl;

	sort(tmp2.begin(), tmp2.end()); //sort
	cout << "sort()֮��" << endl;
	display(tmp2.begin(), tmp2.end());
	bool gotcha = binary_search(tmp2.begin(), tmp2.end(), 2);
	if (gotcha) cout << "sort()֮��ʹ��binary_search() �ҵ�elem��";


	getchar();
	return 0;
}


//template <typename C, typename T>
//void display(const C<T>& con){
//	auto it = con.begin();
//	auto it_end = con.end();
//	for (; it != it_end; it++){
//		cout << *it << endl;
//	}


template <typename itType>
void display(itType it_begin, itType it_end){
	for (; it_begin != it_end; it_begin++){
		cout << *it_begin << " ";
	}
	cout << endl;
}