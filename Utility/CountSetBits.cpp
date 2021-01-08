#include<iostream>
using namespace std;
int countOfSetBits(int N){
	int ans=0;
	while(N){
		N=N&(N-1);
		ans++;
	}
	return ans;
}
int main(){
	int N;
	cin>>N;
	cout<<countOfSetBits(N);
	return 0;
}
