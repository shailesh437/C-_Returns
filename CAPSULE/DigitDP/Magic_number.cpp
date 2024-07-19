/*
Problem Description
Consider the decimal presentation of an integer. Let's call a number D - magic if digit D appears in decimal presentation of the number on all even positions and nowhere else.

For example, the numbers 1727374, 17, 1 are 7 - magic but 77, 7, 123, 34, 71 are not 7 - magic.

On the other hand the number 7 is 0 - magic, 123 is 2 - magic, 34 is 4 - magic and 71 is 1 - magic.

Find the number of D - magic numbers in the segment [L, R] that are multiple of C. Because the answer can be very huge you should only find its value modulo 109 + 7 (so you should find the remainder after dividing by 109 + 7).



Problem Constraints
1 <= C <= 2000

0 <= D <= 9

It is guaranteed that A <= B, the number of digits in A and B are the same and don't exceed 2000.



Input Format
First argument is an numeric string A denoting the positive integer L. (Without Leading Zeroes).

Second argument is an numeric string B denoting the positive integer R. (Without Leading Zeroes).

Third argument is an integer C.

Fourth argument is an integer D.



Output Format
Return an integer denoting the number of D - magic numbers in the segment [L, R] that are multiple of C. Because the answer can be very huge you should only find its value modulo 109 + 7 (so you should find the remainder after dividing by 109 + 7).


*/



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
ll MOD = 1000000007;
//vector<vector<vector<int>>> 
//dp(2000,vector<vector<int>>(2,vector<int>(2000,-1))); 
ll dp[2001][2][2001];
ll find(string S,ll position,ll isSmainter,
	ll currRemainder,
	ll C,ll D){
	if(S=="9"){
	//	cout<<endl<<"entered with position = "<<position;
	//	cout<<endl<<"entered with isSmainter = "<<isSmainter;
	}
	if(position==S.length()){
		if(currRemainder==0) {
			return 1;
		}
		return 0;
	}
	if(dp[position][isSmainter][currRemainder]!=-1){
		if(S=="9"){
			//cout<<endl<<" for "<<dp[position][isSmainter][currRemainder];
		}
		return dp[position][isSmainter][currRemainder];
	}
	ll ans=0;
	ll maxLimit =  (S[position]-'0')*1ll;
	if(isSmainter==1){
		maxLimit=9;
	}
	//cout<<endl<<"maxLimit="<<maxLimit;
	for(int i=0;i<=maxLimit;i++){
		ll newIsSmainter=isSmainter;
		ll newCurrRemainder=currRemainder;
		if(isSmainter==0 and i<maxLimit){
			newIsSmainter=1;
		}
		if(position%2==1 and i!=D){ //even place
			ans+=0;
		}else if(position%2==0 and i==D){ //odd place
			ans+=0;
		}else{

			newCurrRemainder *= 10;
            newCurrRemainder += i;
            newCurrRemainder %= C;

			ans+= find(S,position+1,newIsSmainter,
				newCurrRemainder,
				C,
				D); 
			ans%=MOD;
			if(S=="9"){
			//	cout<<endl<<"ans = "<<ans;
			}
		}
		
	}


	return dp[position][isSmainter][currRemainder]=ans;
}

void fill3DVector(std::vector<std::vector<std::vector<int>>>& vec, int value) {
    for (auto& plane : vec) {
        for (auto& row : plane) {
            std::fill(row.begin(), row.end(), value);
        }
    }
}


string subtractOne(string a){
string s = a.substr(1);
    string s1 = "";
  
    for (int i = 0; i < s.size() - 1; i++)
        s1 += '0'; 
    if (a[0] == 1 and s == s1) {
        int l = s.size();
        a = "";
        a += '0';
        for (int i = 0; i < l; i++)
            a += '9';
    }
    else {
        for (int i = a.size() - 1; i >= 0; i--) { 
            if (a[i] == '0')
                a[i] = '9'; 
            else {
                a[i] = (((a[i] - '0') - 1) + '0');
                break;
            }
        }
    }
    return a;
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



int solve(string A, string B, int C, int D) {
	memset(dp,-1,sizeof dp); 
	ll ans1 = find(B,0,0,0,C,D);
	cout<<endl<<"ans1 = "<<ans1;
		//fill3DVector(dp,-1);
	
	//string X = 	subtractOne1(A);
	//cout<<endl<<"X = "<<X;
	A = subtractOne1(A);
	if(A.length()<B.length()){
		A="0"+A;
	}	
	//memset(dp,sizeof dp,-1);
	memset(dp,-1,sizeof dp);
	cout<<endl<<"A = "<<A;
	ll ans2 = 0;
	if(A.length()>1)
		ans2 = find(A,0,0,0,C,D);
	cout<<endl<<"ans2 = "<<ans2;
	//return (int)ans2;
	return  (int)(ans1%MOD-ans2%MOD+MOD)%MOD
	;
}


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string A, B;
		int C, D;
		cin>>A>>B>>C>>D;
		cout<<endl<<"A="<<A<<":B="<<B<<":C="<<C<<":D="<<D;
		int ans = solve(A,B,C,D);
		cout<<endl<<"ans = "<<ans;
		//cout<<subtractOne1(A);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}


