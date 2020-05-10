#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int TC;
	cin>>TC;	
	int N;
	while(TC--){
		double ans=0.0;
		cin>>N;
		for(int i=1;i<=N;i++){
			ans+=(N*1.0/i);
		}
		cout<<setprecision(2)<<fixed<<ans<<endl;
	}

	return 0;
}
