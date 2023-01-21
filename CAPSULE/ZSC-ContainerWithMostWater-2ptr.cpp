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
int maxArea(vector<int> &A) {
	if(A.size()<=1) return 0;
	int i=0;
	int j=A.size()-1;
	int ans=INT_MIN;
	while(i<j){
		ans=max(ans,min(A[i],A[j])*(j-i));
		if(A[i]<A[j]){
			i++;
		}else if(A[i]>A[j]){
			j--;
		}else{
			i++;
			j--;
		}
	}
	return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A =  {1, 5, 4, 3 };
		int ans = maxArea(A);
		cout<<endl<<"ans="<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
