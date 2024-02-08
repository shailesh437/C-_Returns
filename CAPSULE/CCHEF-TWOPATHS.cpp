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
		int N,M,K;
		cin>>N>>M>>K;
		vector<vector<int>> inp_mat(N+1,vector<int>(M+1,0));
		vector<vector<int>> inp_mat_pfixSum(N+1,vector<int>(M+1,0));
		int MAX_AREA_DP[N+1][M+1][K+2];
		int MIN_AREA_DP[N+1][M+1][K+2];
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>inp_mat[i][j];
				if(j) inp_mat_pfixSum[i][j] = inp_mat_pfixSum[i][j - 1];
                inp_mat_pfixSum[i][j] += inp_mat[i][j];

				//inp_mat_pfixSum[i][j]=inp_mat_pfixSum[i][j-1]+inp_mat[i][j];
			}
		}	
		
		for(int r=0;r<N;r++){
			for(int c=0;c<M;c++){
				for(int k=0;k<=K;k++){
					MAX_AREA_DP[r][c][k]=inp_mat_pfixSum[r][c];

					if(!r)
						continue;

					if(!c or !k){
						MAX_AREA_DP[r][c][k]+=MAX_AREA_DP[r-1][c][k];						
					}else{
						MAX_AREA_DP[r][c][k]+=
						max(MAX_AREA_DP[r-1][c][k],
							MAX_AREA_DP[r-1][c-1][k-1]);
					}
				}
			}
		}

		for(int r=0;r<N;r++){
			for(int c=0;c<M;c++){
				for(int k=0;k<=K;k++){
					MIN_AREA_DP[r][c][k]=inp_mat_pfixSum[r][c]- inp_mat[r][c] ;

					if(!r)
						continue;

					if(!c or !k){
						MIN_AREA_DP[r][c][k]+=MIN_AREA_DP[r-1][c][k];						
					}else{
						MIN_AREA_DP[r][c][k]+=
						min(MIN_AREA_DP[r-1][c][k],MIN_AREA_DP[r-1][c-1][k-1]);
					}
				}
			}
		}

		
		int ans=INT_MIN;
		for(int c=0;c<M;c++){
			for(int c1=c+K+1;c1<M;c1++){
				ans=max(ans,MAX_AREA_DP[N-1][c1][K]-MIN_AREA_DP[N-1][c][K]);
			}
		}

		cout<<endl<<ans;


	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
