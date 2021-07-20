#include<iostream>
using namespace std;
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		int sumOfDigits=0;
		while(N){
			sumOfDigits+= N%10;
			N=N/10;
		}
		cout<<sumOfDigits<<endl;
	}
	return 0;
}
