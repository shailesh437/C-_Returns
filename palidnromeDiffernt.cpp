#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
bool checkPalindrome(int *arr,int startIndex,int endIndex){
	if(startIndex>=endIndex){
		return true;
	}
	if(arr[startIndex]!=arr[endIndex]){
		return false;
	}  
	return checkPalindrome(arr,startIndex+1,endIndex-1);
}
int main(){
	int N;
	cin>>N;
	int* arr = new int[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	string result=checkPalindrome(arr,0,N-1)==0?"false":"true";
	cout<<result;
	return 0;
}
