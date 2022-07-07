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
		int N,C;
		cin>>N>>C;
		int stall[N];
		for(int i=0;i<N;i++){
			cin>>stall[i];
		}
		sort(stall,stall+N);

		int low=1,high=stall[N-1]-stall[0];
		int ans=0;
		while(low<=high){
			int mid=low+(high-low)/2;
			int cowsLeft=C;
			int diff = mid;
			cowsLeft--;
			int lastPosition=stall[0]; 
			for(int i=1;i<N and cowsLeft>0;i++){
				if(stall[i]-lastPosition>=mid){
					cowsLeft--;
					lastPosition=stall[i];	
				}
			}
			if(cowsLeft==0){
				ans=mid;
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
