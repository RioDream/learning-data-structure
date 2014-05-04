//usage: 一个关于c++仿函数的小实例

#include <iostream>

using namespace std;

template <class T>
//名字不用plus因为plus是c++ 11里面的一个functor
struct plus1{ 
	T operator()(const T& x,const T& y) const {return x+y;}
};


int main(){
	plus1<int> p; 
	int o = p(1,2);
	cout<<o<<endl;
	return 0;
}