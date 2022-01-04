#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define logarr(arr,a,b)	for(ll z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
ll NW[100005];
ll MA[100005];
ll MI[100005];
ll P[100005];
ll ANS=0;
vector<ll> graph[100005];
void getMaxDiffInNW(ll i,ll parent ){
	for(ll child: graph[i]){
		if(child!=parent){
			getMaxDiffInNW(child,i);
			MA[i]=max({MA[i],MA[child]});
			MI[i]=min({MI[i],MI[child]});
		}		
	}
	MA[i]=max(MA[i],NW[i]);
	MI[i]=min(MI[i],NW[i]);
	ANS=max(ANS,abs(NW[i]-MA[i]));
	ANS=max(ANS,abs(NW[i]-MI[i]));

}
int main(){ 
	ll TC=1;
	//cin>>TC;
	while(TC--){
		ll N;
		cin>>N;
		memset(NW,0,sizeof NW);
		memset(graph,0,sizeof graph);
		// memset(MA, -1000000000,sizeof MA);
		// memset(MI,1000000000,sizeof MI);
		loop(i,1,N) cin>>NW[i];
		loop(i, 1, N) {
		MA[i] = -inf;
		MI[i] = inf;
		}

		ll root=0;
		loop(i,1,N) {
			cin>>P[i];
			if(P[i]==-1){
				root = i;
			}else{
				graph[P[i]].pb(i);
			}
		}
		getMaxDiffInNW(root,0);
		cout<<ANS;

	}
	  
	return 0;
}
