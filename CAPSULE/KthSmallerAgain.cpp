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

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		int N,Q;
		cin>>N>>Q;
		vector<pair<ll,ll>> ranges; 
		ll qarr[Q];
		ll maxRange=INT_MIN;
		int checkIndex=0;
		for(int i=0;i<N;i++){
			ll a,b;
			cin>>a>>b;
			ranges.push_back({a,b});
		}
		sort(ranges.begin(),ranges.end()); 
		/*for(pair<ll,ll> p:ranges){
			cout<<p.first<<"-"<<p.second<<endl;
		} */ 
		int last_range=0;
		for(int v=1;v<ranges.size();v++){
			if(ranges[last_range].second >= 
				ranges[v].first){
				 ranges[last_range].second = 
				max(ranges[last_range].second,
					ranges[v].second);
				
			}else{
				last_range++;
				ranges[last_range]=ranges[v];
			}  
		} 
		for(pair<ll,ll> p:ranges){
			cout<<p.first<<"-"<<p.second<<endl;
		} 
		//return 0;
		for(int i=0;i<Q;i++){
			cin>>qarr[i];
		}
		for(int i=0;i<Q;i++){
			ll ans = -1;
			ll K = qarr[i];
			//cout<<"\n K = "<<K<<endl;
			for(int v=0;v<=last_range;v++){
				//cout<<endl<<ranges[v].second-ranges[v].first+1<<endl;
				if(ranges[v].second-ranges[v].first+1>=K){
					ans=ranges[v].first+K-1;
					break;		
				}else
				K=K-(ranges[v].second-ranges[v].first+1);
			}
			cout<<ans<<endl;
		}
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
