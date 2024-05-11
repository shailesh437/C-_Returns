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
// list can give memeroy error use vector instead
 
vector<list<int>> graph;


void checkIfPathFromCtoB(int src,int tgt,
vector<bool> &visited){
    visited[src]=true;
    cout<<endl<<src<<" visited\n";
    if(src==tgt) return;
    for(auto it:graph[src]){
        if(!visited[it]){
            checkIfPathFromCtoB(it,tgt,visited); 
        }
    } 
}
int solve(vector<int> &A, const int B, const int C) {
if(C>B) return 0;
graph = vector<list<int>>(A.size()+1);

vector<bool> visited(A.size()+1,false);
for(int i=1;i<A.size();i++){
    graph[A[i]].push_back(i+1);
}

for(int i=1;i<A.size();i++){
	cout<<endl<<A[i]<<":";
	for(int x: graph[A[i]])
		cout<<x<<", ";
}

checkIfPathFromCtoB(C,B,visited);
return visited[B];
}


int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		vector<int> A;
		for(int i=0;i<N;i++){
			int x;
			cin>>x;
			A.push_back(x);
		}
		int B,C;
		cin>>B>>C;
		int ans = solve(A,B,C);
		cout<<endl<<"Ans = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
