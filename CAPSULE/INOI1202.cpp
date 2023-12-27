/*https://www.codechef.com/INOIPRAC/problems/INOI1202*/
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
	int TC=1;
	//cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		vector<int> arr(N+2,0);
		vector<int> preMax(N+2,0);
		vector<int> postMax(N+2,0);
		vector<int> sumForFirstCombination(N+2,0);
		vector<int> result(N+2,0);
		for(int i=1;i<=N;i++){
			cin>>arr[i];
			sumForFirstCombination[i]=arr[i]+i;
			result[1]=max(result[1],sumForFirstCombination[i]);
		}
		preMax[1]=sumForFirstCombination[1];
		for(int i=2;i<=N;i++){
			preMax[i]=max(preMax[i-1],sumForFirstCombination[i]);
		}
		postMax[N]=sumForFirstCombination[N];
		for(int i=N-1;i>=1;i--){
			postMax[i]=max(postMax[i+1],sumForFirstCombination[i]);
		}

		//logarr(preMax,1,N);
		//logarr(postMax,1,N);
		for(int i=1;i<N;i++){
			int maxVal=max(preMax[N-i]+i,
						   postMax[N-i]-(N-i)
						   );	
			//cout<<endl<<maxVal<<endl;
			result[i+1]=maxVal;
		}
		
		logarr(result,1,N);
		//for(int r:result) cout<<r<<" ";
		result.clear();
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
