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
		int N;
		cin>>N;
		int A[N];
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		int A_e=0,A_o=0;
		for(int i=0;i<N;i++){
			if(A[i] & 1){
				A_o++;
			}else{
				A_e++;
			}
		}
		int e_N = N/2;
		int o_N = N-N/2;
		int ans=min(A_o,e_N)+min(A_e,o_N);
		cout<<ans<<endl;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
