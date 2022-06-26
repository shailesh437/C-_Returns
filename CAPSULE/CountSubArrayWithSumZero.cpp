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
ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll ans=0;
        map<ll,ll> m;
        ll sumTillNow=0;
        ll target=0;
        m[0]=1;
        for(int i=0;i<n;i++){
        	sumTillNow += arr[i];
        	ans += m[sumTillNow-target];
        	cout<<"\n ans = "<<ans;
        	m[sumTillNow]++;
        }   
        return ans;
    }
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<ll> arr = {0,0,5,5,0,0};
		int n=6;
	//	int n = 10;
   //vector<ll> arr = {6,-1,-3,4,-2,2,4,6,-12,-7};
		cout<<findSubarray(arr,n);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
