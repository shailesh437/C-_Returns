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
int solve(vector<int> &A, int B) {
    sort(A.begin(),A.end()); 
    int i=0;
    int j=i+1;
    int ans=0;
    while(j<A.size()){
    	if(i==j ) j++;
    	if(j>=A.size()) break;
        int diff = A[j]-A[i];
        if(diff==B and i!=j){ 
            ans++;
            i++;j++;
            while(j<A.size() and A[j]==A[j-1]) j++;
            while(i<A.size() and A[i]==A[i-1]) i++;
        }
        else if(diff<B){
            j++;
        }else {
            i++;
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
		 //vector<int> A = {1, 5, 3, 4, 2};
 		//int B = 3;
 		// vector<int> A = {8, 12, 16, 4, 0, 20};
 		//int B = 4;
 		//vector<int> A = {8, 12, 16, 4, 0, 20};
 		//int B = 0;
 		vector<int> A = {1,2};
 		int B = 0;	
 		int ans = solve(A,B);
 		cout<<endl<<"ans = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
