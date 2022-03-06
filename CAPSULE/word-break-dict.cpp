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
unordered_map<string,int> dp;
int wordBreak(string A, vector<string> &B) {
        //code here
	if(A.length()==0){
		return 1;
	}
	if(dp[A]!=0) return dp[A];
	for(int i=1;i<=A.length();i++){
		string ss = A.substr(0,i);
		bool found=false;
		for(int j=0;j<B.size();j++){
			if(ss.compare(B[j]) == 0){
				found = true;
				break;
			}
		}

		if(found and wordBreak(A.substr(i),B) == 1 ){
			return dp[A]=1;
		}
	}
	return dp[A]=0;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int n = 12;
		vector<string> B  = { "i", "like", "sam",
		"sung", "samsung", "mobile",
		"ice","cream", "icecream",
		"man", "go", "mango" };
		string A = "ilikemango";
		cout<<wordBreak(A,B);
	}
		 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
