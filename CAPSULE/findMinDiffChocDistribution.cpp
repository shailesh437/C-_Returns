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
//cholocateDistrution
//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
 long long findMinDiff(vector<long long> a, long long n, long long m){
    //code n = chockPack m = students
    sort(a.begin(),a.end());
    if(m==n) return a[n-1] - a[0];
    long long local_diff;
    long long global_diff  = INT_MAX;
	for(int i=0;i<=(n-m);i++){
    		local_diff = a[i+m-1]-a[i];
    		//cout<<endl<<local_diff;
			global_diff = min(global_diff,local_diff);
			//i=i+m;	    		
    }
    return global_diff;
    } 
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int N = 21, M = 12;
		/*vector<ll> A;
		A.pb(3);
		A.pb(4);
		A.pb(1);
		A.pb(9);
		A.pb(56);
		A.pb(7);
		A.pb(9);
		A.pb(12);*/
		vector<ll> A
		={34 ,88 ,89 ,39 ,67 ,71 ,85 ,57 ,18 ,7 ,61 ,50 
			,38 ,6 ,60 ,18 ,19 ,46 ,84 ,74 ,59};
		cout<<endl<<findMinDiff(A,N,M);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
