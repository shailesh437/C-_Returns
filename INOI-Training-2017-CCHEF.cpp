#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> EV(5005,0);
vector<ll> strength(5005,0);
vector<vector<ll>> DP(5005,vector<ll>(5005,-1));

 ll getCubeSum(ll X){
	ll Y=X; 
	ll s=0; 

	while(X){
		long long int d = X%10;
		s+=d;
		X=X/10;
	}
	return Y+(s*s*s);
}
ll N,initial_strength;

/*
imp**************
DP[current_city_no][trained_in_Gym_count] denotes 
the maximum EV that can be gained if starts from 
current_cty_no and trained_inGym_count
*/

ll getMax_XV(ll current_city_no, ll trained_in_Gym_count){

  if(current_city_no==N){
  	return strength[trained_in_Gym_count]*EV[current_city_no];
  }

  if(DP[current_city_no][trained_in_Gym_count] !=-1)
  	return DP[current_city_no][trained_in_Gym_count] ;

  return DP[current_city_no][trained_in_Gym_count] = 
  	     max(
  	     	getMax_XV(current_city_no+1,trained_in_Gym_count) + (strength[trained_in_Gym_count]*EV[current_city_no]),
  	     	getMax_XV(current_city_no+1,trained_in_Gym_count+1)
  	     	);
}




int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// your code goes here
	cin>>N>>initial_strength;
		for(int i=1;i<=N;i++){
			cin>>EV[i];
		}
		strength[0]=initial_strength;
		for(int i=1;i<=N;i++){
			strength[i]=getCubeSum(strength[i-1]);
		}

		ll ans = getMax_XV(1,0);
		cout<<ans;

}
