#include<iostream>

using namespace std;

void printArr(int* arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n = 9996786;
	//convert to digits , we can save the array
    int digits[32] = {}; //use 32 as max
    int base = 10;
    int i=0;
    while(n/(base/10)>0){
    	int digit = n%base/(base/10);
        //n = n-digit*base/10;
    	digits[i] = digit;
    	printArr(digits,32);
    	base *= 10;
    	i++;
    }

    string str = "asf";
    cout<<str.size()<<endl;

    printArr(digits,32);
}