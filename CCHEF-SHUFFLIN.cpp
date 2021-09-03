#include<bits/stdc++.h>

int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		int A[N];
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		int A_e=0,A_o=0;
		for(int i=0;i<N;i++){
			if(A[i] & 1){
				A_o++;
			}else{
				A_e++;
			}
		}
		int e_N = N/2;
		int o_N = N-N/2;
		int ans=min(A_o,e_N)+min(A_e,o_N);
		cout<<ans<<endl;
	} 
	return 0;
	}
