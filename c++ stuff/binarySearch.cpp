
#include<iostream>

using namespace std;

int binarySearch(int* arr, int low, int high,int target){
	if(low>high){
		return -1;
	}

	int mid = (low+high)/2;

	if(arr[mid]>target){
		return binarySearch(arr,low,mid-1,target);
	}
	if(arr[mid]<target){
		return binarySearch(arr,mid+1,high,target);
	}

	return mid;
}

int search(int* arr, int len, int target){
	return binarySearch(arr,0,len-1,target);
}

void printArr(int* arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

int main(){
	const int LEN = 8;
	int arr[LEN] = {1,2,3,4,5,6,7,8};
	printArr(arr,LEN);
	cout<<"hello"<<endl;
	int target = 7;
	cout<<search(arr,LEN,target)<<endl;
	return 0;
}