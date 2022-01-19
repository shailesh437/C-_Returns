#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 

int main(){ 
	int TC;
	cin>>TC;
	int letter1[26],letter2[26];
	while(TC--){
		string s;
		cin>>s; 
		memset(letter1,0,sizeof letter1);
		memset(letter2,0,sizeof letter2);
		int end1=0,start2=0;
		if(s.length()%2){
			end1=s.length()/2;
			start2=s.length()/2+1;
		}else{
			end1=s.length()/2;
			start2=s.length()/2;
		}
		for(int i=0;i<end1;i++){
			letter1[s[i]-97]++;
		}
		for(int i=start2;i<s.length();i++){
			letter2[s[i]-97]++;
		}
		bool NO=0;
		for(int i=0;i<26;i++){
			if(letter1[i]!=letter2[i]){
				cout<<"NO"<<endl;
				NO=1;
				break;
			}
		}
		if(!NO){
			cout<<"YES"<<endl;
		}
	} 
	return 0;
	}
