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
long getMaxSubArrSum(vector<long> V){
 long ans=INT_MIN;
    long sum=0; 
    for(int i=0;i<V.size();i++){
        if(sum>0){
            sum+=V[i];
        }else{
            sum=V[i];
        }
        ans=max(ans,sum);
    }
    return ans;
}
long solve(vector<vector<int> > &A) { 
    vector<long> sumC(A[0].size(),0);
    long ans=INT_MIN;
    for(int rowStart=0;rowStart<A.size();rowStart++){
        //sumC.clear();
       for(int rowEnd=rowStart;rowEnd<A.size();rowEnd++){           
           for(int col=0;col<A[0].size();col++){
               sumC[col]+=A[rowEnd][col];               
            }
            ans=max(ans,getMaxSubArrSum(sumC));
       } 
       for(int i=0;i<sumC.size();i++) sumC[i]=0; 
    }
    return ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
	vector<vector<int>> M={{-5 ,-4 ,-3},
						   {-1 ,2 ,3},
						   { 2 ,2 ,4}}; 
	cout<<solve(M);					   
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
