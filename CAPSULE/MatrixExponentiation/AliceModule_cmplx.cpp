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
ll MODD=1e9+7;

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

vector<vector<ll>> IDENTIY_MAT;

vector<vector<ll>> matExpo(vector<vector<ll>> inputMat,
						   ll power,
						   ll modd){
	if(power==0){
		return IDENTIY_MAT;
	}

	vector<vector<ll>> RES = matExpo(inputMat,power/2,modd);
	RES=multiplyMatrix(RES,RES,modd);
	if(power%2==0){
		return RES;
	}
	return multiplyMatrix(RES,inputMat,modd);	
}

int solve(int A,int B,vector<int> &C,int D) {

	//create digitFreq ;
	vector<ll> digitFreq(10,0);
	for(int i=0;i<C.size();i++){
		digitFreq[C[i]*1ll]++;
	}
	for(int x:C){
		cout<<endl<<x<<":"<<digitFreq[x];
	}
	cout<<endl;
	ll modd=B*1ll;
	//create transition matrix;
	vector<vector<ll>> transitionMat(B,vector<ll>(B,0));
	for(ll r=0;r<B*1ll;r++){
		for(ll d=0;d<10;d++){
			ll nextR=((r*10)+d)%modd;
			transitionMat[nextR][r]=(transitionMat[nextR][r]+digitFreq[d])%MODD;
			//transitionMat[nextR][r]%=modd;
		}
	}

	for(int i=0;i<transitionMat.size();i++){
		logarr(transitionMat[i],0,transitionMat[i].size()-1);
	}

	vector<vector<ll>> transitionMatRaisetoA(B,vector<ll>(B,0));
	IDENTIY_MAT.clear();
	IDENTIY_MAT.resize(B,vector<ll>(B,0));
	for(int i=0;i<B;i++){
		IDENTIY_MAT[i][i]=1;
	}
	transitionMatRaisetoA=matExpo(transitionMat,A*1ll,MODD);

	//state matrix
	vector<vector<ll>> multiplierMat(B,
			vector<ll>(1,0));
	multiplierMat[0][0]=1;


	for(int i=0;i<multiplierMat.size();i++){
		logarr(multiplierMat[i],0,multiplierMat[i].size()-1);
	}

	vector<vector<ll>> RES_MAT=multiplyMatrix(transitionMatRaisetoA,
										      multiplierMat,
										      MODD);

	return RES_MAT[D*1ll][0];
}


int solve1(int A, int B, const vector<int>& C, int D) {
    vector<int> digitFreq(10, 0);
    for (int digit : C) {
        digitFreq[digit]++;
    }

    vector<vector<int>> transition(B, vector<int>(B, 0));
    for (int r = 0; r < B; ++r) {
        for (int digit = 0; digit < 10; ++digit) {
            int nextR = (r * 10 + digit) % B;
            transition[nextR][r] = (transition[nextR][r] + digitFreq[digit]) % MODD;
        }
    }

    for(int i=0;i<transition.size();i++){
    	logarr(transition[i],0,transition[i].size()-1);
    }

    return 0;
 }   

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int a=21,b=12,d=10;
		vector<int> c={2,5,7,9,4,7,2,2};
		int ans=solve(a,b,c,d);
		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
