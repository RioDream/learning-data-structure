#include <iostream>
using namespace std;

class vehicle{
public:
	vehicle(){cout<<"i am a vehicle"<<endl;};
	virtual void go(){
		cout<<"vehicle goes"<<endl;
	};
};

class car: public vehicle{
public:
	car(){cout<<"I am a car"<<endl;};
	virtual void go(){
		cout<<"car goes"<<endl;
	};
	float price;
};

class boat:public vehicle{
public:
	boat(){cout<<"I am a boat"<<endl;};
	virtual void go(){	
//	void go(){
		cout<<"boat goes!	"<<endl;
	}; 
	float price;
};
// class twothings:public boat,public car{
class twothings:public car,public boat{
public:
	twothings(){cout<<"i am a twothings"<<endl;};
///*	
	virtual void go() override{
		cout<<"twothing goes!"<<endl;
		
	};
//*/
	void test(){
		cout<<"test"<<endl;
	};

};

int main() {
	// your code goes here


	vehicle* c = new car();
	c->go();

	vehicle* b = new boat();
	b->go();

	twothings* t = new twothings();
	t->go();
	//twothings* t_c = new car();
	//t_c->go();
	//twothings* t_b = new boat();
	//t_b->go();

	car* c_t = new twothings();
	c_t->go();
	boat* t_b = new twothings();
	t_b->go();
	return 0;
}