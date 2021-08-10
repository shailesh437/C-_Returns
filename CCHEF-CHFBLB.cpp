#include<iostream>
#include<cmath>
using namespace std;
int main(){
	
	int TC;
	cin>>TC;
	while(TC--){
		int N,p,K;
		cin>>N>>p>>K;

		int a = p%K - 1;
		int b = ((N-1)/K)*K;
		b = N - 1 - b;
		int ans = 0;
		if (a>b){
			ans += (b+1)*((N-1)/K + 1) +(a-b)*((N-1)/K);
		}else{
			ans += ((N-1)/K + 1)*(a+1);
		}   
		for (int i = a+1; i<=N;i+=K){
			ans += 1;
			if (i==p){
				cout<<ans;
				break;
			}		
		}
	}
			
				return 0;
}
