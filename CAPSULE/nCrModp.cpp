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


ll getExpoMod(ll base, ll power, ll mod){
	if(power==0) return 1LL;
	ll squareOfBase = ((base%mod)*(base%mod))%mod;
	if(power&1){
		return ((base%mod)*(getExpoMod(squareOfBase,power>>1,mod)%mod))%mod;
	}
	return getExpoMod(squareOfBase,power>>1,mod)%mod; 
}
int solve(int A, int B, int C) {
	if(C==1) return 0;
	/*Fermats little theorem (x inverse)%y = 1 if gcd(x,y)=1*/

	// here A_Combinaton_B % C = A!/(A-B)!*(B inverse) 
	//we have to take mod 
	//So B inverse mod C would be B raise to C-1 mod C 
	//So we need to find A*(A-1)*...(A-B) % C 
	ll ans=1LL;
	ll Cc=C*1LL;
	ll Aa=A*1LL;
	ll Bb=B*1LL;

	for(ll i=Aa-Bb+1LL;i<=Aa;i++){
		ans=((ans%Cc)*(i%Cc))%Cc;
	}
	cout<<endl<<"ans = "<<ans<<endl;

	//calculate B factorial raise to C-2 mod m
	ll factoB=1LL;
	for(ll i=2*1LL;i<=Bb;i++){
		factoB*=i%Cc;
		factoB%=Cc;
	}

	ll ans1=getExpoMod(factoB,Cc-2,Cc);
	cout<<endl<<"ans1 = "<<ans1<<endl;
	ans = ((ans)*(ans1))%Cc;

	return (int) ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//cout<<solve(5,2,13); 10 
		//cout<<solve(1,1,1); 0 
		//cout<<solve(778,578,10007); 3624
		cout<<solve(3985,574,92867); //35801
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
