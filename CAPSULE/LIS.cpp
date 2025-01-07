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

int lis(const vector<int> &A) {
	int lis_length_ans=1;
	vector<int> lis_arr(A.size(),1);
	for(int i=1;i<A.size();i++){
		lis_arr[i]=1;
		for(int j=i-1;j>=0;j--){
			if(A[j]<A[i] ){
				lis_arr[i] = max(lis_arr[i],1+lis_arr[j]); 
			}
		}
		if(lis_arr[i]>lis_length_ans){
			lis_length_ans=lis_arr[i];
		}		
	}
	logarr(lis_arr,0,lis_arr.size()-1);
	return lis_length_ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
		int ans = lis(A);
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
