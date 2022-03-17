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
string mobileKeyPadSeq(string s){
	unordered_map<char,string> m;
	
	m['A']="2";
	m['B']="22";
	m['C']="222";
	m['D']="3";
	m['E']="33";
	m['F']="333";
	m['G']="4";
	m['H']="44";
	m['I']="444";
	m['J']="5";
	m['K']="55";
	m['L']="555";
	m['M']="6";
	m['N']="66";
	m['O']="666";
	m['P']="7";
	m['Q']="77";
	m['R']="777";
	m['S']="7777";
	m['T']="8";
	m['U']="88";
	m['V']="888";
	m['W']="9";
	m['X']="99";
	m['Y']="999";
	m['Z']="9999";
	m[' ']="0";
	string ans="";
	for(int i=0;i<s.length();i++){
		ans+=m[s[i]];
	}
	return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string s;
		getline(cin,s);
		cout<<mobileKeyPadSeq(s);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
