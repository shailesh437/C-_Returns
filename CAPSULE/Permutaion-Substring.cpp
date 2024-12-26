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


int solve(string A, string B) {
	int ans=0;
	map<char,int> a_map;
	map<char,int> b_map;
	for(int i=0;i<A.length();i++){
		a_map[A[i]]++;
	}
	for(int i=0;i<A.length();i++){
		b_map[B[i]]++;
	}
	bool match=true;
	for(int i=0;i<26;i++){
		if(a_map[i+'a']==b_map[i+'a']){

			continue;
		}else{
			match=false;
			break;
		}
	}
	cout<<endl<<"match = "<<match;
	if(match){
		ans++;
	}
	for(int i=1;i<B.length()-A.length()+1;i++){
		b_map[B[i-1]]--;
		b_map[B[A.length()+i-1]]++;

		match=true;
		for(int i=0;i<26;i++){
			if(a_map[i+'a']==b_map[i+'a']){

				continue;
			}else{
				match=false;
				break;
			}
		}

		if(match){
			ans++;
		}

	}

	return ans;

}


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int ans = solve("aca","acaa");
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
