#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
	string s = "hello_world!";

	/*test of substr(start,last+1)*/
	string sub = s.substr(0,1);
	cout<<sub<<endl;
	sub = s.substr(0);
	cout<<sub<<endl;

	/* test of the operator*/
	string strSum;
	//strSum = "hello"+"world"; error!
	strSum = strSum+"hello "+"world";
	cout<<strSum<<endl;

	return 0;
}