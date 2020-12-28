#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;

ll recursiveMultiply(ll chosenNumber,ll count){
	if(count==1){
		return chosenNumber;
	}
	return chosenNumber+recursiveMultiply(chosenNumber,count-1);
}
//Program to demonstrate Power function in recursive fashion
int main(){
	cout<<"Enter Two numbers to be multiplied:\n";
	ll no1,no2;
	cin>>no1>>no2;
	ll chosenNumber=max(no1,no2);
	ll count=min(no1,no2);
	ll ans=0;
	if(no1==0||no2==0){
		ans=0;
	}else{
		ans=recursiveMultiply(abs(chosenNumber),abs(count));
		if((no1<0 && no2<0)||(no1>0 && no2>0)){
		}else{
			ans*=-1;
		}
	}
	
	
	cout<<"\n Ans = "<<ans;
}
