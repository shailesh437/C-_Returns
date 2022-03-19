#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define MOD 1000000007
using namespace std;
void file_i_o()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
}
/* 
    0 1 2 3 4( position index)
	a b c a a  
a   1          (represents palindr.sub from roq startint to col ending pos)
b     1
c       1
a        1
a          1

diagnall =  all 1
lower than diagnoal of no signifiance 

Strategy:
countOfSib(startChar+middleString+endChar) 
 if(startchar =  endChar )
   countOfSub(startChar+middlestring) + 
   countOfSub(middlestring+endChar) + 
   coutOfSub(middleString) 

if(startchar <>  endChar )
   countOfSub(startChar+middlestring) + 
   countOfSub(middlestring+endChar)  -  
   1  




*/
long long int  countPS1(string str)
{
	ll x;
	x=0;
	return x;
	//return (ll)0;
       //Your code here
	int dp[1000][1000];
	cout<<str.length();
	return 0;
	//memset(dp,0,sizeof dp);
	for(int gap=0;gap<str.length();gap++){
		for(int i=0,j=gap;j<str.length();i++,j++){
		if(gap == 0){
			dp[i][j]=1; //individually all are pal char
		}
		else if(gap == 1){
			dp[i][j]=2;	
		}else{
			
				if(str[i]==str[j]){
					dp[i][j]=(dp[i][j-1]%MOD + dp[i+1][j]%MOD+1)%MOD;
				}else{
					dp[i][j]=(dp[i][j-1]%MOD + dp[i+1][j]%MOD-
						dp[i+1][j-1]%MOD)%MOD;
				}
			}		
		}		
	}    
	//return dp[0][str.length()-1];
	return 0;    	
}
ll countPS(string s){
	ll dp[s.length()][s.length()];
	memset(dp,0,sizeof dp);
	for(int gap=0;gap<s.length();gap++){
		for(int i=0,j=gap; j<s.length();j++,i++){
			if(gap==0){
				dp[i][j]=1;
			}else if(gap==1){
				dp[i][j]=(s[i]==s[j])?3:2;
			}else{
				if(s[i]==s[j]){
					dp[i][j]= (dp[i][j-1]%MOD + dp[i+1][j]%MOD +1)%MOD; 	
				}else{
					dp[i][j]= (dp[i][j-1]%MOD + dp[i+1][j]%MOD - dp[i+1][j-1]%MOD)%MOD; 	
				}
				if(dp[i][j]<0){
					dp[i][j]+=MOD;
				}
			}
		}
	}
	/*
	for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return dp[0][s.length()-1];
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string s ="abcdcba";
		ll ans =  countPS(s);
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
