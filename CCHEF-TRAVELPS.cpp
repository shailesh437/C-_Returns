#include<bits/stdc++.h> 
using namespace std;
 

int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		int N,A,B;
		string s;
		cin>>N>>A>>B>>s;
		int zero=0,one=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){	
				zero++;
			}else{
				one++;
			}
		}
		cout<<(A*zero+B*one)<<endl;
	} 
	return 0;
	}
