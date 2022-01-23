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
	while(TC--){
		int N;
		cin>>N;
		string inpStr;
		vector<int> word(6,0);
		for(int i=0;i<N;i++){
			cin>>inpStr;
			for(int i=0;i<inpStr.length();i++){
				if(inpStr[i]=='c') word[0]++;
				if(inpStr[i]=='o') word[1]++;
				if(inpStr[i]=='d') word[2]++;
				if(inpStr[i]=='e') word[3]++;
				if(inpStr[i]=='h') word[4]++;
				if(inpStr[i]=='f') word[5]++;
			}
		}
		word[0] /= 2;
		word[3] /= 2;
		cout<<*min_element(word.begin(),word.end())<<endl;
	}
	return 0;
	}
