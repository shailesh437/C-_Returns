#include <iostream>
using namespace std;
int decimalToBinary(int N){
	int place=1;
	int ans=0;
	while(N){
		int digit = N & 1;
		ans+=digit*place;
		N=N>>1;
		place*=10;
	}
	return ans;
}
int main(){
	int N;
	cin>>N;	
	cout<<decimalToBinary(N);
}
