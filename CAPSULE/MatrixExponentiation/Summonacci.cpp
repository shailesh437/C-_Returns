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
		for(ll j=0;j<m2cols;j++){
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

vector<vector<ll>> IDENTITY_MAT={{1,0,0,0},
								 {0,1,0,0},
								 {0,0,1,0},
								 {0,0,0,1}
								 };
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



int solve(int A, int B, int C) {
    ll pow=A*1ll-2*1ll;
	ll n=A*1ll;
    ll f1=B*1ll;
	ll f2=C*1ll;
    ll mod=1e9+7;

    vector<vector<ll>> matA=
		{{1,1,1,1},
		{0,1,1,1},
		{0,0,1,1},
		{0,0,1,0}
		};

    vector<vector<ll>> ANS(4,vector<ll>(4,0));
	ANS = matExpo(matA,pow,mod);
	
	vector<vector<ll>> multiplierMat(4,vector<ll>(1,0));
	
	multiplierMat[0][0]=f2+2ll*f1;
	multiplierMat[1][0]=f1+f2;
	multiplierMat[2][0]=f2;
	multiplierMat[3][0]=f1;
    cout<<endl<<ANS.size();
    cout<<endl<<ANS[0].size();
    cout<<endl<<multiplierMat.size();
    cout<<endl<<multiplierMat[0].size();
    cout<<endl<<"===============\n";	
    for(int i=0;i<ANS.size();i++){
    	logarr(ANS[i],0,3);
    }
    cout<<endl<<"===============\n";	
    for(int i=0;i<multiplierMat.size();i++){
    	logarr(multiplierMat[i],0,0);
    }
    cout<<multiplierMat[0].size();
    ANS = multiplyMatrix(ANS,multiplierMat,mod);
    
    int x = (int)ANS[0][0];
    return x;

}

int main(){
	clock_t begin = clock();
	file_i_o();
	ll TC=1;
	while(TC--){
		int a = 3;
		int b = 1;
		int c = 1;
		int ans_x  = solve(a,b,c);
		cout<<endl<<ans_x;
		return 0;
		ll pow;
		ll n;
		cin>>n;
		pow=n-2;
		ll f1;
		ll f2;
		cin>>f1>>f2;
		ll mod=1e9+7;
		vector<vector<ll>> matA=
		{{1,1,1,1},
		{0,1,1,1},
		{0,0,1,1},
		{0,0,1,0}
		};

	cout<<endl;
	for(int i=0;i<matA.size();i++){
		for(int j=0;j<matA[0].size();j++){
			cout<<matA[i][j]<<" ";
		}
		cout<<endl;
	}

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

	vector<vector<ll>> ANS(4,vector<ll>(4,0));
	ANS = matExpo(matA,pow,mod);
		
	cout<<endl;
	for(int i=0;i<ANS.size();i++){
		for(int j=0;j<ANS[0].size();j++){
			cout<<ANS[i][j]<<" ";
		}
		cout<<endl;
	}
	vector<vector<ll>> multiplierMat(4,vector<ll>(1,0));
	multiplierMat[0][0]=f1+2ll*f2;
	multiplierMat[1][0]=f1+f2;
	multiplierMat[2][0]=f2;
	multiplierMat[3][0]=f1;

	ANS = multiplyMatrix(ANS,multiplierMat,mod);


	cout<<endl<<ANS[0][0];
	return 0;

}
	 #ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
