#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n;
void bsort(int *arr,int i, int j){
	if(i==n-1){
		return;
	}
	if(j==n-i-1){
		i++;
		j=0;
	}
	if(arr[j]>arr[j+1]){
			swap(arr[j],arr[j+1]);
		}
	return bsort(arr,i,j+1);
 }
int main(){
	int arr[] = {4,3,2,1};
	n=sizeof(arr)/sizeof(arr[0]);
	cout<<endl;
	bsort(arr,0,0);
	for(int k=0;k<n;k++){
		cout<<" "<<arr[k];
	}
	cout<<"\n AFTER SORTING... \n";
	for(int k=0;k<n;k++){
		cout<<" "<<arr[k];
	}
	return 0;
}                     
