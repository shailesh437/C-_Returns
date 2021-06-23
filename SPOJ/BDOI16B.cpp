#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
int main(){
   int TC;
    cin>>TC;
    ll n,k;
    int tc=1;
    while(TC--){
        cin>>n>>k;
        ll ans=inf;
        for(int i=2;i*i<=k;i++){
            ll kfpower=0;
            while(k%i==0){
                kfpower++;
                k/=i;                
            }
            if(kfpower==0){
                continue;
            }
            ll kfpowerInN=0;
            ll den=i;
            while(den<=n){
                kfpowerInN+=n/den;
                den*=i;
            }
            ans=min(ans,kfpowerInN/kfpower);
        }
        if(k>1){
            ll den=k;
            ll kpowerInN=0;
            while(den<=n){
                kpowerInN+=n/den;
                den*=k;    
            }
            ans=min(ans,kpowerInN);
        }
        if(ans==inf){
            ans=0;
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
        tc++;
    }
    return 0;
}
