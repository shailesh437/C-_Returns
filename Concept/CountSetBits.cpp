#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cout<<"Program to count the set bits for the given number: ";
	cout<<endl<<"Enter the number : ";
	cin>>N;
	int count=0;
	while(N){
		N= N & (N-1);
		count++;
	}
	cout<<endl<<"Count of set bits = "<<count;

	return 0;
}
