#include <iostream>
#include <string>
using namespace std;

class MyFunctor
{
public:
	MyFunctor(){};

	void operator() (){
		cout<<"i am functor class "<<endl;
	}

	~MyFunctor(){};
	
};



int main(){
	string s = "hello";
	cout<<s[0]<<endl;

	cout<<(s+'h')<<endl;
	MyFunctor* f = new MyFunctor();
	(*f)();
	//&f();
	return 0;
}