#include<bits/stdc++.h>
using namespace std;
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		if(N==1){
			cout<<"no"<<endl;
		}else if(N==2){
			cout<<"yes"<<endl;
		}else if((N & 1) == 0){
			cout<<"no"<<endl;
		}else{
			bool isprime=true;
			for(int i=3;i*i<=N;i+=2){
					if(N%i==0){
						isprime =false;
						break;		
					}
			}
			if(isprime){
				cout<<"yes"<<endl;	
			}else{
				cout<<"no"<<endl;
			}
			
		}
	}
	return 0;
}
