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
void eraseIfPresent(vector<char> &NRA,char X){
	vector<char>::iterator it;
	for(auto it=NRA.begin();it!=NRA.end();it++){
		if(*it==X){
			NRA.erase(it);
			return;
		}
	}
}
string FirstNonRepeating(string A){
	char nonRepeatingChar=A[0];
	vector<char> ans;
	queue<char> nRQ;
	vector<char> NRA;
	ans.push_back(A[0]);
	unordered_map<char,int> m;
	m[A[0]]=1;
	NRA.push_back(A[0]);
	for(int i=1;i<A.length();i++){
		m[A[i]]++; 
		if(m[A[i]]>1){
			eraseIfPresent(NRA,A[i]);	
		}else{
			NRA.push_back(A[i]);
		}
		if(NRA.size()==0){
			nonRepeatingChar='#';	
		}else{
			nonRepeatingChar=NRA[0];
		}
		ans.push_back(nonRepeatingChar);		
	}


	string ANS(ans.begin(),ans.end());
	return ANS;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string A;
		cin>>A;
		cout<<A<<endl;
		cout<<FirstNonRepeating(A);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
