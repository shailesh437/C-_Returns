#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int stringToNumber(char *s,int digit,int place){
	if(digit<0){
		return 0;
	}
	int val = (s[digit]-'0')*place;
	return stringToNumber(s,digit-1,place*10)+val;
}

int stringToNumber(char *s,int n){
	if(n==0)
		return 0;
	int digit = s[n-1]-'0';
	int part1ans=stringToNumber(s,n-1);
	return part1ans*10+digit;
}

int main(){
	char s[1000] ;
	cout<<"Enter the String::";
	cin>>s;
	cout<<stringToNumber(s,strlen(s)-1,1);
	cout<<endl<<"second method"<<endl;
	cout<<stringToNumber(s,strlen(s));
}
