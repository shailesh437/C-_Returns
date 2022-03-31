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
 int romanToDecimal(string &str) {
 	int val=0;
 	unordered_map<char,int> m;
 	m['I']=1;
 	m['V']=5;
 	m['X']=10;
 	m['L']=50;
 	m['C']=100;
 	m['D']=500;
 	m['M']=1000;
 	if(str.length() == 1){
 		return m[str[0]];
 	}
 	for(int i=0;i<(str.length()-1);i++){
 		if(m[str[i]]<m[str[i+1]]){
 			val -= m[str[i]];
 		}else{
 			val += m[str[i]];
 		}
 	}
 	val += m[str[str.length()-1]];
 	/*if(m[str[str.length()-2]]>=m[str[str.length()-1]]){
 		val += m[str[str.length()-1]];
 	}else{
 		val -= m[str[str.length()-1]];

 	}*/
 	return val;
 }

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//string str = "MMMDCCXCIV";
		string str = "MMMDCCXCIV";
		cout<<romanToDecimal(str);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
