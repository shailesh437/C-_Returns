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

long long int powMod(int base,int power,int MOD){
	if(power==1) return base%MOD;
	if(power==0) return 1;
	long long int ans=1;
	if(power&1){
		ans*=base%MOD;
	}
	ans*=(powMod(base,power/2,MOD)%MOD)*
	     (powMod(base,power/2,MOD)%MOD);
	ans%=MOD;     
	return ans;
}
int solve(vector<int> &A) {
     sort(A.begin(),A.end());
     int MOD=1e9+7;
     int N=A.size(); 
     int start=0;
     int end=N-1;
     long long int valToAdd=A[N-1]%MOD;
     int p = powMod(2,N-1,MOD)-1;
     cout<<endl<<p<<"::"<<N-1;
     valToAdd*=p;
     valToAdd%=MOD;
     long long int valToSubtract=A[0]%MOD;
     valToSubtract*=p;
     valToSubtract%=MOD;
     cout<<endl<<valToSubtract<<":"<<valToAdd<<endl;
     //return 0;
	 long long int ans=(valToAdd-valToSubtract);
     start++;
     end--;
     int i=1;
     while(start<end){
     	long long int x = powMod(2,N-1-i,MOD)-1;
     	long long int y = powMod(2,i,MOD)-1;
     	long long int z = x-y;
     	if(z<0){
     		z+=MOD;
     	}
     	z%=MOD;
     	
     	valToAdd=((A[end]%MOD)*(z))%MOD;
     	valToSubtract=((A[start]%MOD)*(z))%MOD;
     	//valToSubtract%=MOD;
     	z=valToAdd-valToSubtract;
     	if(z<0)z+=MOD;
     	z%=MOD;
    	cout<<endl<<valToSubtract<<":"<<valToAdd<<endl;
    	//long long int z = (A[end]%MOD-A[start]%MOD)%MOD;
    	ans+=z; 
	    //if(ans<0)ans+=MOD;
	    //else
	    ans%=MOD;
	    
	    cout<<endl<<ans<<endl;
     	start++;
     	end--;
     	i++;
     } 
     return (int)ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> A={1,2};//1
		//vector<int> A={7, 8, 6, 4, 6 };//66
		//vector<int> A={3, 10, 2, 3, 8, 1, 10, 4};//1787
		vector<int> A={ 7, 8, 6, 4, 6, 7, 3, 10, 2, 3, 8, 1, 10, 4, 7, 1, 7, 3, 7, 2, 9, 8, 10, 3, 1, 3, 4, 8, 6, 10, 3, 3, 9, 10, 8, 4, 7, 2, 3, 10, 4, 2, 10, 5, 8, 9, 5, 6, 1, 4, 7, 2, 1, 7, 4, 3, 1, 7, 2, 6, 6, 5, 8, 7, 6, 7, 10, 4, 8, 5, 6, 3, 6, 5, 8, 5, 5, 4, 1, 8, 9, 7, 9, 9, 5, 4, 2, 5, 10, 3, 1, 7, 9, 10, 3, 7, 7, 5, 10, 6, 1, 5, 9, 8, 2, 8, 3, 8, 3, 3, 7, 2, 1, 7, 2, 6, 10, 5, 10, 1, 10, 2, 8, 8, 2, 2, 6, 10, 8, 8, 7, 8, 4, 7, 6, 7, 4, 10, 5, 9, 2, 3, 10, 4, 10, 1, 9, 9, 6, 1, 10, 7, 4, 9, 6, 7, 2, 2, 6, 10, 9, 5, 9, 2, 1, 4, 1, 5, 5, 5, 5, 8, 7, 4, 2, 8, 6, 10, 7, 3, 2, 8, 9, 6, 8, 5, 2, 9, 6, 10, 8, 6, 4, 9, 9, 4, 2, 9, 10, 7, 5, 4, 4, 4, 9, 7, 1, 5, 9, 9, 9, 10, 8, 8, 7, 5, 4, 1, 4, 1, 10, 3, 6, 5, 1, 6, 10, 5, 7, 10, 3, 3, 5, 8, 8, 6, 5, 9, 2, 3, 9, 10, 4, 7, 9, 1, 3, 2, 1, 6, 2, 2, 1, 9, 6, 1, 7, 5, 7, 3, 6, 9, 7, 3, 9, 5, 8, 3, 5, 1, 7, 3, 10, 10, 1, 9, 2, 4, 2, 2, 1, 4, 5, 1, 4, 10, 2, 10, 7, 10, 4, 4, 9, 1, 6, 7, 7, 5, 1, 1, 5, 7, 3, 7, 8, 6, 7, 10, 9, 8, 3, 9, 3, 10, 10, 7, 1, 3, 8, 7, 2, 4, 3, 2, 6, 10, 10, 2, 5, 10, 2, 1, 8, 6, 9, 8, 1, 5, 9, 1, 5, 3, 10, 7, 2, 1, 5, 3, 3, 3, 1, 6, 6, 3, 10, 1, 3, 9, 4, 9, 1, 5, 1, 10, 2, 10, 7, 3, 6, 5, 5, 10, 10, 4, 7, 1, 6, 1, 3, 10, 5, 4, 6, 2, 8, 5, 4, 2, 5, 7, 10, 5, 3, 3, 7, 5, 2, 3, 9, 9, 10, 3, 9, 9, 9, 7, 9, 4, 9, 4, 4, 4, 9, 1, 5, 8, 7, 9, 10, 1, 7, 9, 8, 10, 1, 4, 4, 4, 8, 4, 3, 7, 6, 3, 7, 6, 9, 8, 10, 7, 1, 5, 2, 1, 5, 9, 8, 1, 9, 7, 3, 5, 8, 10, 4, 10, 3, 9, 4, 1, 2, 8, 9, 10, 2, 6, 5, 10, 3, 6, 8, 5, 10, 10, 5, 6, 10, 4, 6, 8, 1, 9, 2, 10, 10, 8, 9, 3, 6, 4, 5, 10, 1, 3, 1, 2, 10, 7, 3, 2, 3, 1, 8, 4, 2, 2, 10, 1, 6, 7, 8, 8, 5, 1, 7, 5, 8, 5, 9, 6, 9, 3, 7, 1, 7, 7, 5, 7, 3, 9, 10, 7, 1, 8, 1, 2, 1, 2, 4, 8, 8, 3, 7, 5, 6, 3, 1, 3, 10, 1, 10, 10, 5, 6, 2, 1, 4, 8, 9, 9, 7, 1, 5, 7, 8, 7, 1, 10, 8, 6, 10, 8, 9, 6, 4, 4, 9, 4, 8, 10, 4, 8, 9, 8, 5, 2, 10, 1, 10, 9, 9, 6, 9, 5, 4, 8, 2, 4, 9, 1, 10, 8, 10, 10, 4, 3, 5, 4, 8, 2, 3, 3, 1, 3, 2, 8, 6, 2, 8, 5, 2, 8, 2, 2, 2, 8, 1, 5, 1, 9, 6, 2, 7, 7, 3, 2, 10, 7, 5, 9, 1, 9, 2, 1, 3, 3, 10, 8, 6, 7, 5, 7, 4, 8, 10, 8, 5, 10, 2, 8, 1, 7, 1, 9, 6, 4, 10, 5, 2, 6, 5, 2, 6, 6, 5, 10, 9, 4, 9, 6, 3, 3, 3, 8, 1, 4, 5, 7, 4, 7, 4, 4, 5, 5, 4, 10, 8, 3, 6, 9, 10, 1, 3, 5, 8, 7, 6, 8, 2, 4, 4, 4, 9, 6, 2, 1, 9, 8, 7, 4, 6, 1, 9, 1, 5, 2, 2, 4, 6, 10, 4, 5, 2, 6, 1, 9, 4, 6, 7, 6, 10, 10, 1, 8, 7, 4, 8, 7, 2, 6, 1, 7, 6, 1, 9, 2, 3, 3, 7, 10, 2, 1, 5, 3, 8, 5, 1, 4, 3, 9, 1, 4, 8, 1, 1, 4, 5, 10, 3, 8, 5, 3, 6, 3, 5, 5, 4, 9, 7, 1, 9, 10, 3, 3, 4, 2, 9, 4, 5, 3, 3, 5, 6, 2, 8, 6, 8, 2, 7, 10, 9, 2, 4, 4, 4, 8, 10, 9, 7, 8, 1, 5, 9, 5, 9, 2, 7, 9, 6, 3, 2, 10, 10, 7, 1, 7, 5, 10, 10, 1, 9, 10, 4, 2, 5, 9, 10, 7, 8, 8, 4, 8, 2, 3, 3, 2, 6, 1, 10, 1, 5, 1, 2, 4, 8, 5, 2, 2, 4, 1, 4, 3, 2, 8, 6, 7, 6, 5, 3, 3, 2, 8, 3 };
		cout<<solve(A);
		//cout<<powMod(2,88200,1e9+7);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}

/*
Given an integer array, A of size N.
You have to find all possible non-empty subsequences of the array of numbers and then, for each subsequence, find the difference between the largest and smallest numbers in that subsequence. Then add up all the differences to get the number.

As the number may be large, output the number modulo 1e9 + 7 (1000000007).

NOTE: Subsequence can be non-contiguous.



Problem Constraints
1 <= N <= 10000

1<= A[i] <=1000*/
