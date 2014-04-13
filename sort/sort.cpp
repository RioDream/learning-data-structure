#include <iostream>
#include <cstdlib>

using namespace std;


//a swap function without new variables
void swap(int& a, int& b){
	a = a+b;
	b = a-b;
	a = a-b;
}

void BubbleSort1(int* a, int len){
	for(int i=0;i<len;i++){
		//第i次排序会将当前最大的移动到
		//倒数第i个
		for(int j=1;j<len-i;j++){ //找出前 len-i个元素中的最大
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
			}
		}
	}
}

void InsertSort1(int* a,int len){
	int i,j,k;
	for(i=1;i<len;i++){ //a[0]已经是一个有序区，从a[1]开始看
		//为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
		//如果a[i]不需要前插,j=i-1, 代表不需要移动
		for(j=i-1;j>=0;j--){
			if(a[j]<a[i]) break; //刚刚好找到一个小于a[i]的元素，就吧a[i]放在其后就可以
		}

		//找到了合适位置（j==i-1说明现在a[i-1]<a[i]。不用做什么）
		if(j!=i-1){
			int temp = a[i];
			//将j之后的右移
			for(k=i-1;k>j;k--){
				a[k+1] = a[k];
			}
			a[j+1] = temp;
		}
	}
}

//************归并*************
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

//************quick sort**************

//使得左边没有比s[l]更大的数，右边没有比s[l]更小的数
int AdjustArray(int s[], int l, int r) //返回调整后基准数的位置
{
	int i = l, j = r;
	int x = s[l]; //s[l]即s[i]就是第一个坑
	while (i < j)
	{
		// 从右向左找小于x的数来填s[i]
		while(i < j && s[j] >= x) 
			j--;  
		if(i < j) 
		{
			s[i] = s[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}

		// 从左向右找大于或等于x的数来填s[j]
		while(i < j && s[i] < x)
			i++;  
		if(i < j) 
		{
			s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	s[i] = x;

	return i;
}

void quick_sort1(int s[], int l, int r)
{
	if (l < r)
    {
		int i = AdjustArray(s, l, r);//先成挖坑填数法调整s[]
		quick_sort1(s, l, i - 1); // 递归调用 
		quick_sort1(s, i + 1, r);
	}
}

//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;  
            if(i < j) 
				s[i++] = s[j];
			
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;  
            if(i < j) 
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}



//************print*********
void printArr(int* arr,int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	const int LEN = 10;
	cout<<"hello"<<endl;
	int arr[LEN];
	for(int i=0;i<LEN;i++){
		arr[i] = rand();
	}
	//BubbleSort1(arr,LEN);
	//InsertSort1(arr,LEN);
	//MergeSort(arr,LEN);
	quick_sort1(arr,0,LEN-1);
	printArr(arr,LEN);
	return 0;

}