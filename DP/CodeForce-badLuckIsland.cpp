#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
ld dp[100][100][100]={0.0};

ld fr(int r,int s,int p){ 
	if(r==0 or s==0) return 0.0;
	if(p==0) return 1.0;
	if(dp[r][s][p] != -1.0){
		return dp[r][s][p];
	} 
	ld total = r*s +s*p + p*r;
	ld result=0.0;
	result += fr(r-1,s,p)*((r*p)/total);
	result += fr(r,s-1,p)*((r*s)/total);
	result += fr(r,s,p-1)*((s*p)/total);
	return dp[r][s][p]=result;
}

ld fs(int r,int s,int p){
	if(s==0 or p==0) return 0.0;
	if(r==0) return 1.0;
	if(dp[r][s][p] != -1.0){
		return dp[r][s][p];
	} 
	ld total = r*s +s*p + p*r;
	ld result=0.0;
	result += fs(r-1,s,p)*((r*p)/total);
	result += fs(r,s-1,p)*((r*s)/total);
	result += fs(r,s,p-1)*((s*p)/total);
	return dp[r][s][p]=result;
}

ld fp(int r,int s,int p){
	if(r==0 or p==0) return 0.0;
	if(s==0) return 1.0;
	if(dp[r][s][p] != -1.0){
		return dp[r][s][p];
	} 
	ld total = r*s +s*p + p*r;
	ld result=0.0;
	result += fp(r-1,s,p)*((r*p)/total);
	result += fp(r,s-1,p)*((r*s)/total);
	result += fp(r,s,p-1)*((s*p)/total);
	return dp[r][s][p]=result;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	while(TC--){
		int r,s,p;
		cin>>r>>s>>p;
		fill((ld*)dp,(ld*)dp+100*100*100,-1.0);
		ld ans_r = fr(r,s,p); 
		fill((ld*)dp,(ld*)dp+100*100*100,-1.0);
		ld ans_s = fs(r,s,p);
		fill((ld*)dp,(ld*)dp+100*100*100,-1.0);
		ld ans_p = fp(r,s,p);
		cout<<fixed<<setprecision(9)<<ans_r<<" "<<ans_s<<" "<<ans_p;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
