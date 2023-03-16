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
int solve(vector<int> &A, vector<int> &B) {
    multimap<int,int> semap;
    for(int i=0;i<A.size();i++){ 
        semap.insert(pair<int,int>(B[i],A[i]));
    }
    int ans=1;
    auto it = semap.begin();
    int prevJobEnd=it->first; 
    it++;
    for(;it!=semap.end();it++){ 

        if(it->second>=prevJobEnd){
            ans++;
            prevJobEnd=it->first;
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
		/*vector<int> A= { 1, 5, 7, 1 };
		vector<int> B= { 7, 8, 8, 8 };*/
        vector<int> A= { 3, 2, 6};
        vector<int> B= { 9, 8, 9};
		int ANS = solve(A,B);
		cout<<endl<<ANS;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
