#include<bits/stdc++.h> 
#define MOD 4000000007
//https://www.spoj.com/problems/CRYPTO1/
//If p is a prime of form 4k+3, then 
//and a is quadratic residue 
//then 
#define ll long long
using namespace std;

ll powerModP(ll a, ll k, ll P){
    ll ans=1; 
    while(k){
        if(k & 1){
            ans=((ans%P)*(a%P))%P;  
        }
        a=((a%P)*(a%P))%P; 
        k=k>>1;
    }
    return ans;
}


int main(){
ll k = MOD/4;
ll remainder;
cin>>remainder;
ll timeInSec = powerModP(remainder,k+1,MOD);
if(timeInSec > MOD/2){
    timeInSec = MOD - timeInSec;
}
time_t  result = timeInSec;
cout<<endl<<asctime(std::localtime(&result));

return 0;
}

