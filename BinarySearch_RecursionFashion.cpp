 #include<iostream>
 #include<bits/stdc++.h>
 #include<algorithm>
using namespace std;
int key_to_search;
int indexOf_no_to_find;
int getIndex(int *arr,int s,int e){
	if(s<=e){
		int midpoint=(s+e)>>1;
		if(arr[midpoint]==key_to_search){
			return midpoint;
		}else if(arr[midpoint]>key_to_search){
			e=midpoint-1;
		}else{
			s=midpoint+1;
		}
		return getIndex(arr,s,e) ;
	}else{
		return -1;
	}
}
//Program to demonstrate binary search in recursive fashion
int main(){
	int arr[]={1,2,3,4,5,10,20};
	int indexOf_no_to_find=0;
	cout<<"Enter the Key you want to search ?";
	cin>>key_to_search;
	indexOf_no_to_find=getIndex(arr,0,(sizeof(arr)/sizeof(arr[0]))-1);
	if(indexOf_no_to_find==-1){
		cout<<" ABSENT";
	}else{
		cout<<" PRESENT AT "<<indexOf_no_to_find+1;
	}
}
