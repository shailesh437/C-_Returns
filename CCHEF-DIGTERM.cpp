//https://www.codechef.com/OCT21C/problems/DIGITREM

#include<bits/stdc++.h>
#define ll long long int 
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(ll  i=a;i<=b;i++)
#define logarr(arr,a,b)	for(ll  z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
ll  getPos(ll N,ll  D){ 
	ll  ans=-1;
	ll  digPos=1;
	while(N){
		ll  d = N%10;
		if(d==D){
			ans=digPos;
		}
		N/=10;
		digPos++;
	}
	return ans;
}
ll  length(ll N){
	return to_string(N).length();
}

ll getValueToSubtract(ll N,ll  pos){
	//cout<<"\n getValueToSubtract called witn "<<N<<"-"<<pos;
	string N_str = to_string(N);
	ll  s = N_str.length()-pos;
	string N_str_1 = N_str.substr(0,s);
	//cout<<"\n getValueToSubtract N_str_1 "<<N_str_1;
	ll N_1 = stoll(N_str_1)*pow(10,pos);
	return N_1;
}
ll  getZeroCount(ll  N){
	ll  cnt=0;
	while(N){
		ll  dig=N%10;
		if(dig==0){
			cnt++;
		}
		N=N/10;
	}
	return cnt;
}
ll  getOnestr(ll  N){
	ll  ans=0;
	while(N>=0){
		ans+=pow(10,N-1);
		N--;
	}		
	return ans;
}

int  main(){ 
	ll  TC;
	cin>>TC;
	while(TC--){
		ll  N,D,N_copy;
		cin>>N>>D;
		N_copy=N;
		ll  no_to_add=0;
		if(D==0 && length(N)>2){  
			int place=1,currDigit=0;;
			ll placeValue=1;
			ll valueTillNow=0;
			ll allOnes[11]={0,1,11,111,
				1111,11111,111111,
				1111111,11111111,
				111111111,1111111111};
				while(N){
					currDigit=N%10;
					valueTillNow+=placeValue*currDigit;
					if(currDigit==0){
						no_to_add=allOnes[place]-valueTillNow; 
					}
					placeValue*=10;
					N/=10;	
					place++;
				}
				cout<<no_to_add<<endl;
				continue;
			}

			no_to_add=0; 
			vi v;	
			while(1){
			//cout<<endl<<"calling getPos with "<<N<<"-"<<D<<endl;
				ll  posOfD = getPos(N,D);
				if(posOfD==-1){
					v.push_back(no_to_add);
					if(getPos(no_to_add+N_copy,D)==-1){
						break;	
					}else{ 
						N=N_copy+no_to_add;
						posOfD = getPos(N,D);
						N_copy=N;
						no_to_add=0;
					}					
				}  
			//cout<<"\n posOfD = "<<posOfD<<endl;
				if(posOfD<length(N)){
					ll  subtract = getValueToSubtract(N,posOfD); 
					N=N-subtract; 
				}
				ll  T = pow(10,posOfD-1)*(D+1); 
				no_to_add+=	(T-N); 
				N=N+no_to_add; 
			}
			ll final_result=0;
			for(ll x: v){
			    final_result+=x;
			} 
			cout<<final_result<<endl;
			v.clear();

		}  
	return 0;
}
