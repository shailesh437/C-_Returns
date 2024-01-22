#include <bits/stdc++.h>
using namespace std;
#define ll long long 



int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
    
    vector<ll> a(n+1,0);
    vector<ll> w(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    
    
    
    /*
    vector<vector<ll>> biomass(n+1,vector<ll>(n+1,0));
    
    for(int i=0;i<n;i++){
        ll sum=0;
        ll max_weight=0;
        for(int j=i;j<n;j++){
            sum += a[j];
            max_weight=max(max_weight,w[j]);
            biomass[i][j]=sum*max_weight;
            
        }
    }
    */
    
    
    
     vector<vector<ll>> dp(k+1,vector<ll>(n+1,10e17));
    
     dp[0][0]=0;
     
     ll maxweight=0;
     ll sum_a=0;
     ll cost=0;
     
     for(int i=1;i<=n;i++){
         maxweight=max(maxweight,w[i]);
         sum_a+=a[i];
         cost=maxweight*sum_a;
         dp[0][i]=cost;
     }
     
     
    
    for(int walls=1;walls<=k;walls++){
        for(int i=walls+1;i<=n;i++){
             maxweight=0;
             sum_a=0;
             cost=0;
            for(int next=i;next>walls;next--){
                maxweight=max(maxweight,w[next]);
                sum_a+=a[next];
                cost=sum_a*maxweight;
                dp[walls][i]=min(dp[walls][i],
                    dp[walls-1][next-1]+cost);
            }
        }
    }
    
    cout<<dp[k][n]<<endl;
}
