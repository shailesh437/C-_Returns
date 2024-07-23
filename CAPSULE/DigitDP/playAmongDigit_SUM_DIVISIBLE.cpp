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

int MOD=1000000007;
int dp[12][2][120][1500];

vector<bool> dp_prime(120,true);



int find(string A,int position,int isSmaller,
	int C,
	int sumOfDigitis,
	int currRemainder){
	if(position==A.length()){
		if(currRemainder==0 
			and dp_prime[sumOfDigitis]==true){
			return 1;
	}
	return 0;
}
if(dp[position][isSmaller][sumOfDigitis][currRemainder]!=-1){
	return dp[position][isSmaller][sumOfDigitis][currRemainder];
}
int maxLimit=A[position]-'0';

if(isSmaller==1){
	maxLimit=9;
}
int ans=0;
for(int i=0;i<=maxLimit;i++){
	int newIsSmaller=isSmaller;
	int newSumOfDigits=sumOfDigitis+i;
		//int newCurrRemainder=(currRemainder*10+i)%C;
	int newCurrRemainder = currRemainder;
	newCurrRemainder*=10;
	newCurrRemainder+=i;
	newCurrRemainder%=C;
	if(isSmaller==0 and i<maxLimit){
		newIsSmaller=1;
	}
	ans+=find(A,
		position+1,
		newIsSmaller,
		C,
		newSumOfDigits,
		newCurrRemainder
		);

	ans%=MOD;

} 
return dp[position][isSmaller][sumOfDigitis][currRemainder]=ans;

}



string subtractOne1(string inp){
	vector<int> num(inp.size(),0);
	int string_len = inp.length()-1;
	for(int i=string_len;i>=0;i--)
	{
		num[string_len-i]=inp[i]-'0';
	} 
	int deduct=0;
	if(num[0]>0){
		num[0]-=1;
	}else{
		num[0]=9;
		deduct=1;
	} 
	for(int i=1;i<=string_len;i++){
		if(num[i]-deduct>=0){
			num[i]-=deduct;
			deduct=0;
		}else{
			num[i]=9;
		}
	}
	if(deduct>0){
		num[string_len]=0;
	}
    //logarr(num,0,num.size()-1);

	while(num[string_len]==0 and string_len>0){
		string_len--;
	}
	vector<char> result;
    //logarr(num,0,num.size()-1);
	for(int i=string_len;i>=0;i--)
	{
		result.push_back(num[i]+'0');
	}
    //logarr(result,0,result.size()-1);

	string result_s(result.begin(),result.end());
	return result_s;
}
bool checkIfSumOfDigitsIsPrime(ll X){
	int digitSum=0;
	while(X){
		digitSum+=X%10;
		X/=10;
	}
	return dp_prime[digitSum];
}

int solve(string A, string B, int C) {
	memset(dp,-1,sizeof dp);
	int ans1,ans2;
	int ans = 0;
	if(C<=1500){
		ans1=find(B,0,0,C,0,0); 
		cout<<endl<<ans1;
		memset(dp,-1,sizeof dp);
		A=subtractOne1(A);
		cout<<endl<<A;
		ans2=find(A,0,0,C,0,0);
		cout<<endl<<ans2;
		ans=(ans1%MOD-ans2%MOD+MOD)%MOD;
	}else{ 
		ll C_long = C;
		char *endptr;
		const char *A_str=A.c_str();
		ll A_long=strtol(A_str,&endptr,10);

		const char *B_str=B.c_str();
		ll B_long=strtol(B_str,&endptr,10);


		ll range_start=0;
		if(A_long%C_long==0){
			range_start=A_long;
		}else{
			range_start=(A_long/C_long+1)*C_long;
		}
		for(ll i=range_start;i<=B_long;i+=C_long){
			if(i%C_long==0 and checkIfSumOfDigitsIsPrime(i)){
				ans+=1;
				if(ans>MOD){
					ans%=MOD;
				}
			}
		} 
	}
	return ans;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		dp_prime[0]=false;
		dp_prime[1]=false; 
		for(int i=2;i*i<101;i++){
			for(int j=i*i;j<101;j+=i)
				dp_prime[j]=false;
		}
		string A,B;
		int C;
		cin>>A>>B>>C;
		cout<<endl<<"A="<<A<<":B="<<B<<":C="<<C<<endl;
		int ans = solve(A,B,C);
		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
