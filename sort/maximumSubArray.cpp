int maxSubArray(int A[], int n) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  int maxV = INT_MIN;  
  return maxArray(A, 0, n-1, maxV);      
}  
int maxArray(int A[], int left, int right, int& maxV)  
{  

	//如果超过了，就返回INT_MIN，这样和别人比较的时候就没意义了
  if(left>right)  
     return INT_MIN;  

   //左右中
   int mid = (left+right)/2;  
   int lmax = maxArray(A, left, mid -1, maxV);  
   int rmax = maxArray(A, mid + 1, right, maxV);  	

   //maxV是左右最大的
   maxV = max(maxV, lmax);  
   maxV = max(maxV, rmax);  

   //中间的左半部分，求最大
   int sum = 0, mlmax = 0;  
   for(int i= mid -1; i>=left; i--)  
   {  
     sum += A[i];  
     if(sum > mlmax)  
       mlmax = sum;  
   }  

   //中间的右半部分，求最大
   sum = 0; int mrmax = 0;  
   for(int i = mid +1; i<=right; i++)  
   {  
     sum += A[i];  
     if(sum > mrmax)  
       mrmax = sum;  
   }  

   //求左中右最大
   maxV = max(maxV, mlmax + mrmax + A[mid]);  
   return maxV;  
 }  