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
int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++){
    	cout<<A[i]<<" ";
    }
    cout<<endl;
    int N = A.size()-1;
    if(A[N]==0) return 1;
    int cnt=1;
    for(int i=N-1;i>=0;i--){
       
        if(cnt==A[i] and A[i]!=A[i+1]){
        	cout<<"\n Returning for "<<A[i]<<":cnt="<<cnt<<endl;
            return 1;
        }
       // if(A[i]!=A[i+1]){ 
            cnt++;
        //}
    }
    return -1;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int aSize;
		cin>>aSize;
		vector<int> V;
		for(int i=0;i<aSize;i++){
			int x;
			cin>>x;
			V.push_back(x);
		}
		cout<<solve(V);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
