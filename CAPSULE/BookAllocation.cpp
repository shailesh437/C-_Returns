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
	//int ANS=-1;;
	bool allocable(int maxPageAllowed,
				   int A[],
				   int N,
				   int M){
		int allotmentToSingle=0;
		int totalStudents=M-1;
		for(int i=0;i<N;i++){
			if(A[i]>maxPageAllowed)
				return false;
			if(allotmentToSingle+A[i]<=maxPageAllowed){
				allotmentToSingle += A[i];
				continue;	
			} 
			cout<<endl<<allotmentToSingle<<":"<<totalStudents;
			totalStudents--;
			allotmentToSingle=A[i];
		}
		if(totalStudents<0) return false; 
		return true;
	}
	int findPages(int A[], int N, int M) 
	{
	 	int low=A[0];
	 	int high = 0;
	 	for(int i=0;i<N;i++) high += A[i];
	 	int ans=0;
	 	while(low<=high){
	 		int mid = low+(high-low)/2;
	 		//cout<<endl<<low<<":"<<mid<<":"<<high;
	 		if(allocable(mid,A,N,M)){
	 			high=mid-1;
	 			ans=mid;
	 		}else{
	 			low=mid+1;
	 		}
	 	} 

		return ans;
	} 
int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
			int N,M;
			cin>>N>>M;
			int arr[N];
			for(int i=0;i<N;i++){
				cin>>arr[i];
			}
		cout<<	findPages(arr,N,M);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
