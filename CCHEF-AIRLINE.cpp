#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		int A,B,C,D,E;
		cin>>A>>B>>C>>D>>E;
		if(A<=E and (B+C)<=D){
			cout<<"YES\n";
		}else if(B<=E and (A+C)<=D){
			cout<<"YES\n";
		}else if(C<=E and (A+B)<=D){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	} 
	return 0;
	}
