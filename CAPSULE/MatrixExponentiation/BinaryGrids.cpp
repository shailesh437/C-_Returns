
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define logarr(arr,a,b)	for(ll z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> matA,
					     vector<vector<ll>> matB,
					     ll mod){
	ll m1rows=matA.size()*1ll;
	ll m1cols=matA[0].size()*1ll;
	ll m2rows=matB.size()*1ll;
	ll m2cols=matB[0].size()*1ll;
	vector<vector<ll>> ans(m1rows,vector<ll>(m2cols,0));
	for(ll i=0;i<m1rows;i++){
		for(ll j=0;j<m1cols;j++){
			//ans[i][j]=0;
			for(ll k=0;k<m2rows;k++){
				ans[i][j]+=((matA[i][k]%mod)*(matB[k][j]%mod))%mod;
				ans[i][j]%=mod;
			}
		}
	}
	return ans;
}

ll powMod(ll base,ll pow, ll mod){
	if(pow==0) return 1ll;
	ll X = powMod(base,pow/2,mod);
	 X = ((X%mod)*(X%mod))%mod;
	if(pow%2==0) return X;
	else
	return ((X%mod)*(base%mod))%mod;
}

vector<vector<ll>> IDENTITY_MAT={{1,0},{0,1}};
vector<vector<ll>> matExpo(vector<vector<ll>> matA,
						   ll pow,
						   ll mod){

	if(pow==0) return IDENTITY_MAT;
	vector<vector<ll>> ANS;
	ANS = matExpo(matA,pow/2,mod);
	ANS = multiplyMatrix(ANS,ANS,mod);
	if(pow%2==0){
		return ANS;
	}
	return multiplyMatrix(ANS,matA,mod);
}

int main(){
clock_t begin = clock();
	file_i_o();
	ll TC=1;
	while(TC--){
		ll pow;
		ll n;
		cin>>n;
			
		ll mod=1e9+7;
		vector<vector<ll>> matA={{3,2},{1,0}};
		/*vector<vector<ll>> matB={{3,2},{1,0}};
		vector<vector<ll>> ANS(matA.size(),
								vector<ll>(matB[0].size(),0));
		ANS = multiplyMatrix(matA,matB,10000006);
		cout<<endl<<ANS[0][0]<<" "<<ANS[0][1]<<endl;
		cout<<ANS[1][0]<<" "<<ANS[1][1];
		vector<vector<ll>> _MAT={{4},{1}};
		vector<vector<ll>> result(ANS.size(),vector<ll>(_MAT[0].size(),0));

		result = multiplyMatrix(ANS,_MAT,1000006);
		cout<<endl<<result[0][0]<<endl;
		cout<<result[1][0];*/
		
		vector<vector<ll>> ANS = matExpo(matA,pow,mod);
		vector<vector<ll>> multiplierMat={{4ll},{1ll}};		
		ANS = multiplyMatrix(ANS,multiplierMat,mod);
		cout<<endl<<ANS[0][0];
		
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
