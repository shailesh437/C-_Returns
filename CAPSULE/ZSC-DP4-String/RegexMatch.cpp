#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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


bool pendingPatternisAllAsterix(string pattern,int pat_index){
	for(int i=pat_index;i>=0;i--){
		if(pattern[i]!='*') return false;
	}
	return true;
}
bool isPatternFound(string S,
	string pattern,
	int s_index,
	int pat_index,
	vector<vector<int>> &dp){

	if(s_index<0 and pat_index<0) return true;

	if(s_index>=0 and pat_index<0) return false;

	
	
	if(s_index<0 and !pendingPatternisAllAsterix(pattern,pat_index)) 
		return false; 

	if(s_index<0 and pendingPatternisAllAsterix(pattern,pat_index)) 
		return true; 

	if(s_index>=0 and pendingPatternisAllAsterix(pattern,pat_index)) 
		return true;

	if(dp[s_index][pat_index]!=-1)
		return dp[s_index][pat_index];

	if(pattern[pat_index]==S[s_index] or 
		pattern[pat_index]=='?'	){
		return 
	dp[s_index][pat_index]=
	isPatternFound(S,pattern,s_index-1,pat_index-1,dp);
} else if(pattern[pat_index]=='*'){
	return 
	dp[s_index][pat_index]=
	isPatternFound(S,pattern,s_index,pat_index-1,dp) or 
	isPatternFound(S,pattern,s_index-1,pat_index,dp); 
}else  
return dp[s_index][pat_index]=false;

} 
int isMatchCopd(const string A, const string B) {
	vector<vector<int>>dp(2,vector<int>(B.length()+1,0));
	dp[0][0]=1;
	if(B[0]=='*'){
		dp[0][1]=1;
	}else{
		dp[0][1]=0;
	} 
	cout<<endl;
	logarr(dp[0],0,dp[0].size()-1);
	cout<<endl;
	for(int i=2;i<=B.length();i++){
		if(B[i-1]=='*'){
			dp[0][i]=dp[0][i-1];
		}else{
			dp[0][i]=0;
		}
	}
	cout<<endl;
	logarr(dp[0],0,dp[0].size()-1);
	cout<<endl;
	for(int i=1;i<=A.length();i++){
		dp[i%2][0]=0;
		for(int j=1;j<=B.length();j++){
			if(A[i-1]==B[j-1]){
				dp[i%2][j]=dp[(i-1)%2][j-1];
			}
			else{
				if(B[j-1]=='*'){
					dp[i%2][j]=dp[(i-1)%2][j] or dp[i%2][j-1];
				}
				else if(B[j-1]=='?'){
					dp[i%2][j]=dp[(i-1)%2][j-1];
				}
				else{
					dp[i%2][j]=0;
				}
			}
		}
	}

	return dp[A.length()%2][B.length()];
}
int isMatch(const string A, const string B) {
    //string B1=string(B.begin(),B.end());
	vector<char> V;
	int i=B.length()-1;
	while(B[i]=='*' and B[i-1]=='*' and i>0){
		i--;
	}
	cout<<"i="<<i;
	for(int j=0;j<=i;j++){
		V.push_back(B[j]);
	}
	cout<<endl;

	logarr(V,0,V.size()-1);
	cout<<endl;
	string B1(V.begin(),V.end());
	if(B1.length()==1 and B1[0]=='*') 
		return 1;


	cout<<endl<<"1"<<B1; 
	auto it = std::find(B.begin(), B.end(), '*');
	int index=0;
	while (it != B.end()) {
		index = std::distance(B.begin(), it);
		it=std::find(B.begin()+index+1, B.end(), '*'); 
	}  
	int remainingLength=B.length()-index-1;  
	if(remainingLength>A.length()) 
		return 0;
	cout<<endl<<B1;     
	vector<vector<int>> dp(A.length()+1,
		vector<int>(B1.length()+1,-1));
	return isPatternFound(A,B1,A.length()-1,B1.length()-1,dp); 
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string A ="caabccca";
		string B ="c*";
		A="bbbcbcb";
		B="*b";
		A="bbbcbcb";
		B="**b";
		A="cc";
		B="***??";

		int ans = isMatchCopd(A,B);
		
	/*	vector<vector<int>> dp(A.length()+1,
		vector<int>(B.length()+1,-1));
	   ans =  isPatternFound(A,B,A.length()-1,B.length()-1,dp); 
*/

		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
