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

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int mat[4][5] = 
		{
			{1, 2, 1, 4, 8},
			{3, 7, 8, 5, 1},
			{8, 7, 7, 3, 1},
			{8, 1, 2, 7, 9},
		};
		unordered_map<int,int> umap;
		for(int col=0;col<5;col++){
			umap[mat[0][col]]=1;
		}
		for(int col=0;col<5;col++){
			if(umap[mat[1][col]]){
				umap[mat[1][col]]=2;
			}     
		}
		stack<int> extra;
		for(pair<int,int> mapEle:umap){
			if(mapEle.second!=2){
				extra.push(mapEle.first);
			}
		}
		while(!extra.empty()){
			umap.erase(extra.top());
			extra.pop();
		}
		for(int i=2;i<4;i++){
			for(int col=0;col<5;col++){
				if(umap[mat[i][col]]==i){
					umap[mat[i][col]]=i+1;
				} 
			}
		}
		for(pair<int,int> mapEle:umap){
			cout<<endl<<mapEle.first<<" "<<mapEle.second;
		}	
	
}
	 #ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
