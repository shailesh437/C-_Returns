#include<iostream>
using namespace std;
int pow(int x,int p){
	if(p==1)
		return x;
	int smallans=x*x;
	if(p&1)	{
		return x*pow(smallans,p/2);
	}
	return pow(smallans,p/2);
}
int main() {
	int n;
	cin>>n;
	cout<<pow(2,n+1)-2; /* 2 raise to (N+1) - 2*/
	return 0;
}
