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
	    vector<int> Mods(1000000,0);
	    int MOD=1e9+7; 
	    for(int i=0;i<A.size();i++){
	        A[i]%=B;
	        //cout<<A[i]<<" ";
	    } 
	    for(int i=0;i<A.size();i++){
	        Mods[A[i]]++;
	        //cout<<Mods[A[i]]<<" ";
	    }

	    //cout<<endl;
	    int ans=0;
	    int pairWith=0;
	    for(int i=0;i<A.size();i++){
	      	 if(A[i]>0)
	      	 pairWith = B - A[i];
	      	 else
	      	 pairWith = 0;

	      	 Mods[A[i]]--;
	      	 //cout<<endl<<pairWith<<endl;
	    	 //return 0;
	      	 ans+=Mods[pairWith]%MOD;
	      	 
	      	 ans%=MOD;

	    }
	    return ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> A = { 1, 2, 3, 4, 5 };
		//int B = 2;
		//vector<int> A = {5, 17, 100, 11};
 		//int B = 28;
 		vector<int> A = { 1 };
		int B = 1000000;
		int ans= solve(A,B);
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
