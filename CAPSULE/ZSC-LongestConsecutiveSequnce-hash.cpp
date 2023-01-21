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
int longestConsecutive(const vector<int> &A) {
    set<int> S;
    map<int,int> m;
    for(int x:A) S.insert(x);

    for(auto it=S.begin();it!=S.end();it++){
        cout<<*it<<" ";
        int x = *it;
        int prevOfx=x-1;
        auto itPre=S.find(prevOfx);
        if(S.find(prevOfx)==S.end()){
        	m[x]=1;
        }else{
        	m[x]=m[prevOfx]+1;
        }
    }
    int ans=1;
    for(auto it=m.begin();it!=m.end();it++){
    	ans=max(ans,it->second);
    }
    return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> A={100, 4, 200, 1, 3, 2};
		vector<int> A={2,1};
		int ANS = longestConsecutive(A);
		cout<<endl<<"ANS="<<ANS;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
