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
int powMod(int  base,
	int  power,
	int  MOD){

	if(power==0) return 1;
	if(power==1) return base;
	long long int ans=1; 
	int  comm = powMod(base,power/2,MOD);
	//ans=((comm%MOD)*(comm%MOD))%MOD;
	ans*=comm%MOD;
	ans%=MOD;
	ans*=comm%MOD;
	ans%=MOD;	
	if(power&1){
		ans*=base;
		ans%=MOD;
	}    
	return ans;       
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A = 30790;
		int B = 155656;
		int BB=B;
		int MOD = 1e9+7;
		cout<<powMod(204512989,2,MOD)%MOD<<endl; 
		cout<<endl<<"-------------"<<endl;
		int ans=A%MOD*1l; 
		while(B>=2){
			ans= powMod(ans,B,MOD);
			B--;
		}    
		cout<<endl<<ans<<endl;

		//Another way : Fermats little theorem ****
		// pow(X,P-1)__-_-=1(MOD P)P is prime 
		//So here break B! such that we can apply FLT
		//B! = (P-1)*(P-1)*(P-1)***.X
		//X = B! MOD (P-1)..yahhoooo .. lets call it X;

		long long int X = 1;
		int MOD_MINUS_1=1e9+6;
		
		while(BB>1){
			X*=BB%MOD_MINUS_1;
			X%=MOD_MINUS_1;
			BB--;
		}
		cout<<endl<<"new Poerr = "<<X<<endl;
		int newPower = (int)X;
		cout<<powMod(A,newPower,MOD);

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
