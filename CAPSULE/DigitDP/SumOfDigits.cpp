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
int dp[15][2][200];
int MOD=1000000007;
string s;
int process(int indexPosition,int isSmaller,int sumTillNow){
	if(indexPosition==s.size()){
		return sumTillNow;
	}
	if(dp[indexPosition][isSmaller][sumTillNow]!=-1){
		return dp[indexPosition][isSmaller][sumTillNow];
	}
	int maxLimit=9;
	if(isSmaller==0){
		maxLimit=s[indexPosition]-'0';
	}
	int ans=0;
//	cout<<endl<<maxLimit<<endl;
	for(int i=0;i<=maxLimit;i++){
		int newIsSmaller=isSmaller;
		int newSum=(sumTillNow%MOD+i)%MOD;
		if(isSmaller==0 and i<maxLimit){
			newIsSmaller=1;
		}
		ans+=process(indexPosition+1,newIsSmaller,
				newSum);
		ans%=MOD;

	}
	return dp[indexPosition][isSmaller][sumTillNow]=ans;
}
vector<int> solve(vector<string> &A) {
	vector<int>  ans;
	for(int i=0;2*i<A.size()-1;i++){
		ll  L=stoll(A[2*i]);
		ll  R=stoll(A[2*i+1]);
		L=L-1;
		s=to_string(R);
		memset(dp,-1,sizeof dp);
	//	cout<<endl<<"S="<<s<<endl;
		int ans1=process(0,0,0);
		cout<<"\n ans1= "<<ans1;
		s=to_string(L);
		memset(dp,-1,sizeof dp);
		int ans2=process(0,0,0);
		cout<<"\n ans2= "<<ans2;

		ans.push_back((ans1%MOD-ans2%MOD)%MOD);
	}
	return ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<string> A = { "1", "5", "22", "23"};
		A={"10","15"};
		A={"611767","8259217","25","39","451","35981444",
		"243646","501368","6376","92970",
		"2257",
		"69483450",
		"85062","290739","8917","921640","9036","2214930","11044","13212740","81","322","151090","7199338","26","890441","73","981","7482","205500","332","59792138","21","179","128353","24580355","250010","556688528","8046","9637","348278","56717188","636700","3913006","3346","7866411","112812","24989130","52460","77622383","80","247636387","279","39334","83826","20296237"};
		A={"2257","69483450"};

		vector<int> ans = solve(A);
		if(ans.size()){
			logarr(ans,0,ans.size()-1);
		}
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
