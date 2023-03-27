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
void printAllPermute(vector<int> A,
					 int curr_index,
					 vector<int> B, 
					 vector<bool> &visited) {
	if(curr_index==A.size()){
		logarr(B,0,B.size()-1);
		return;
	}
	for(int i=0;i<A.size();i++){
		if(!visited[i]){
			visited[i]=true;
			B[curr_index]=A[i];
			printAllPermute(A,curr_index+1,B,visited);
			visited[i]=false;
		} 
	}

}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A={1,2,3};
		vector<int> B(A.size());
		vector<bool> visited(A.size(),false);
		printAllPermute(A,0,B,visited);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
