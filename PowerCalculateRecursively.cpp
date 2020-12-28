#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
float recursivePower(float base,int index){
	if(index==0)
		return 1;
	int newIndex=index/2;/*BITSHIFT WONT WORK IF INDEX IS NEGATIVE*/
	float tempAnswer=recursivePower(base,newIndex);
	if(index%2==0)
		return tempAnswer*tempAnswer;
	else{		
		if(index<=0)
			return (tempAnswer*tempAnswer)/base;
		else
			return base*tempAnswer*tempAnswer; 	
	}
}
//Program to demonstrate Power function in recursive fashion
int main(){
	cout<<"Enter the base(can be decimal):\n";
	float base;
	cin>>base;
	cout<<"\nEnter the index(has to be integer):\n";
	int index;
	cin>>index;
	cout<<"\n Ans = "<<recursivePower(base,index);
}
