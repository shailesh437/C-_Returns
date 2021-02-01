#include<iostream>
using namespace std;

int shrinkTD(int X,int ar[]){
	if(X==1){
		return 0;
	}
	if(ar[X]!=0){
		return ar[X];
	}
	int a,b,c;
	a=b=c=INT_MAX;
	if(X%2 ==0){
		a= shrinkTD(X/2,ar) ;
	}
	if(X%3 ==0){
		b= shrinkTD(X/3,ar) ;
	}
	c=shrinkTD(X-1,ar);
	int res = 1 + min(a,min(b,c));
	return ar[X]=res;	
}


int shrinkBU(int X){
	int *arr = new int[X];
	for(int i=0;i<X+1;i++){
		arr[i]=0;
	}
	arr[1]=0;
	for(int i=2;i<=X;i++){
		int a ,b,c;
		a=b=INT_MAX;
		if(i%2==0){
			a=arr[i/2];
		}
		if(i%3==0){
			b=arr[i/3];
		}
		c=arr[i-1];
		arr[i]=1+min(a,min(b,c));
	}

	return arr[X];	
}

int main(){
	int no_to_reduce;
	cout<<"Enter the no_to_reduce: ";
	cin>>no_to_reduce;
	int *arr = new int[no_to_reduce+1];
	for(int i=0;i<no_to_reduce+1;i++){
		arr[i]=0;
	}
	cout<<" Steps needed = "<<shrinkTD(no_to_reduce,arr);
	cout<<" Steps needed = "<<shrinkBU(no_to_reduce);

	return 0;
}
