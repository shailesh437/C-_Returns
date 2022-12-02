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
vector<int> solve(int A, vector<vector<int> > &B) {
    vector<int> V(A,0);
    for(int i=0;i<B.size();i++){
        V[B[i][0]-1]+=B[i][2];
        V[B[i][1]]+=(B[i][2]*-1);
    }
    for(int i=1;i<A;i++){
        V[i]+=V[i-1];
    }
    return V;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A = 5;
		vector<vector<int>> B = {{1, 2, 10}, {2, 3, 20},{2, 5, 25}};
		vector<int> ANS = solve(A,B);
		for(int x:ANS)cout<<x<<" ";
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
