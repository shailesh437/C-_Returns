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

bool valid_( vector<pair<int,int>> inp_arr_val_indx,
			int N,
			int mid,
			int L){

	vector<int> DP(N,1);

	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(abs(inp_arr_val_indx[i].second - inp_arr_val_indx[j].second )>=mid){
				DP[i]=max(DP[i],1+DP[j]);
			}
		}
		if(DP[i]>=L){
			return true;
		}
	}

	return false;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		int N,L;
		cin>>N>>L;

		vector<pair<int,int>> inp_arr_val_indx(N);
		for(int i=0;i<N;i++){
			cin>>inp_arr_val_indx[i].first;
			inp_arr_val_indx[i].second=i;
		}
		sort(inp_arr_val_indx.rbegin(),inp_arr_val_indx.rend());

		//get the lowest possible cost when the values are not distinct
		int low_cost=0;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if( inp_arr_val_indx[i].first != inp_arr_val_indx[i].first){
					break;
				}
				low_cost=max(low_cost,abs(inp_arr_val_indx[i].second-
								inp_arr_val_indx[i].second));

			}
		}

		int l=low_cost;
		int r=N-1;
		while(l<r){
			int mid=(l+r+1)/2;
			if(valid_(inp_arr_val_indx,N,mid,L)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<l<<endl;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
