#include<bits/stdc++.h> 
#define vi vector<int> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define MOD 1000000007
#define PRIME 3
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
int powMOD(int base,int power){
	if(power==0){
		return 1;
	}
	if(power==1){
		return base;
	}
	
	int ans=1;
	if(power&1){
		ans=base%MOD;
	}
	base=(base%MOD*base%MOD)%MOD;
	return (ans*powMOD(base,power/2))%MOD;
} 
int calcHash(string s){
	int h=0;
	for(int i=0;i<s.length();i++){
		h+=s[i]*powMOD(PRIME,i);
	}
	return h;
} 
int getPrefixHash(int pfxHashTiintNow,char x,int pos){
	int val = (pfxHashTiintNow%MOD-(x*powMOD(PRIME,pos))%MOD)%MOD;
	if(val<0)val += MOD; 
	return val;
}
int getSuffixHash(int sfxHashTiintNow,char x,int pos){
	int val = (sfxHashTiintNow-x)/PRIME;
	if(val<0)val += MOD; 
	return val;
}
int ans=0;
int longestPrefSuff(string s){
	int wholeTextHash=calcHash(s);
	int prefixHashTillNow=wholeTextHash;
	int suffixHashTillNow=wholeTextHash;
	for(int i=0;i<s.length()-1;i++){
		prefixHashTillNow=getPrefixHash(prefixHashTillNow,
										s[s.length()-i-1],
										s.length()-i-1);
		suffixHashTillNow=getSuffixHash(suffixHashTillNow,
										s[i],
										i);
		cout<<prefixHashTillNow<<"<-->"<<suffixHashTillNow<<endl;
		if(prefixHashTillNow == suffixHashTillNow){
			cout<<"\n i = "<<i<<endl;
			//cout<<endl<<s.substr(i+1)<<endl;
			string pfx=s.substr(0,s.length()-i-1);
			string sfx=s.substr(i+1);
			//cout<<"\n pfx=["<<pfx<<"] sfx=["<<sfx<<"]";
			if(pfx==sfx){
				ans=max(ans,(int)pfx.length());
			}
		} 
	}
	return ans; 
} 
int lps(string s){
	int lps[s.length()];
	lps[0]=0;
	int i=0;
	int j=1;
	while(j<s.length()){
		if(s[i] == s[j]){
			lps[j]=i+1;
			i++;
			j++;
		}else{
			if(i==0){
				lps[j]=0;
				j++;
			}else{
				i=lps[i-1];
			}
		}
	}
	return lps[s.length()-1];
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		 string s;
		 cin>>s;
		 //string s ="abdcabdeabdcabdea";
		 //string s ="aaa";
		 //cout<<longestPrefSuff(s);
		 cout<<lps(s);
		/* cout<<calcHash('a',1);
		 cout<<calcHash('z',1);*/
		 //cout<<powMOD(2,9+1+1);
		//cout<<rabinKarpForLPS("ljjoeuljjoef");
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
