#include<iostream>
using namespace std;
int merge(int A[],int *temp,int start,int midpoint,int end){
	int inv_count=0;
	int left_ptr=start;
	int right_ptr=midpoint+1;
	int k=0;
	while(left_ptr<=midpoint && right_ptr<=end){
		if(A[left_ptr]<=A[right_ptr]){
			temp[k++]=A[left_ptr++];
		}else{
			temp[k++]=A[right_ptr++];
			inv_count+= midpoint - left_ptr + 1;
		}
	}

	while(left_ptr<=midpoint)
		temp[k++]=A[left_ptr++];
	while(right_ptr<=end)
		temp[k++]=A[right_ptr++];
	return inv_count;
}
int invCountByMergeSort(int A[],int *temp,int start,int end){
	int midpoint,invCount=0;
	if(start<end){
		midpoint = (start+end)>>1;
		invCount+=	invCountByMergeSort(A,temp,start,midpoint);
		invCount+=	invCountByMergeSort(A,temp,midpoint+1,end);
		invCount+=  merge(A,temp,start,midpoint,end);
	}
	return invCount;
}
int main(){
	int A[]={5,3,4,2,1};
	int *temp = new int[sizeof(A)/sizeof(A[0])];
	cout<<invCountByMergeSort(A,temp,0,(sizeof(A)/sizeof(A[0]))-1);
	//The temp array has the sorted numbers.
	//If we wish to overwrite the main array it can be done here
	return 0;
}
