#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e9
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
		int N,X;
		cin>>N>>X;	
		unordered_map<ll,ll> orig;
		unordered_map<ll,ll> derived;
		vector<ll> inp(N);	
		for(int i=0;i<N;i++){
			cin>>inp[i];
			orig[inp[i]]++;
		} 
		if(X==0){
			int count=0;
			for(auto a:orig){ 
				if(a.second>count){
					count=a.second;
				}
			}
			cout<<count<<" 0"<<endl;
			continue;
		}
		for(int i=0;i<N;i++){ 
			derived[inp[i]^X]++;
		}   
		int highest_eq_count=0;
		int lowest_op=inf;
		for(auto a:orig){ 			
			int x = a.second+derived[a.first];
			int y = derived[a.first];
			if((x>=highest_eq_count) ){

				if(x>highest_eq_count){
					highest_eq_count = x;
					lowest_op=y;	
				}else if(lowest_op>y){
					lowest_op=y;
				} 				
				
			}
			
		} 
		cout<<highest_eq_count<<" "<<lowest_op<<endl; 
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
