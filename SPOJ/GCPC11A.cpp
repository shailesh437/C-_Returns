#include<bits/stdc++.h>
#define ll long long
#define inf             1e18
using namespace std;
int main(){
    int TC;
    cin>>TC;
    ll n,k;
    while(TC--){
        cin>>n>>k;
        ll ans=inf;
        
        for(int i=2;1LL*i*i<=k;i++){
            if(k%i==0){
                ll kfpower=0;
                while(k%i==0){
                    kfpower++;
                    k/=i;                
                }
                ll kfpowerInN=0;
                ll den=i;
                while(den<=n){
                    kfpowerInN+=n/den;
                    if ( den > n / i) break;
                    den*=i;
                }
                ans=min(ans,kfpowerInN/kfpower);
            }
        }
        if(k>1){
            ll den=k;
            ll kpowerInN=0;
            while(den<=n){
                kpowerInN+=n/den;
                if ( den > n / k) break;
                den*=k;    
            }
            ans=min(ans,kpowerInN);
        }
        cout<<ans<<endl;
    }
    return 0;
}
