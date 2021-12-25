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
int W,H;
char ch[101][101];
int dp[101][101][101];

int dx1[]={1,0,1,0};
int dy1[]={0,1,0,1};
int dx2[]={1,0,0,1};
int dy2[]={0,1,1,0};
/*
int dx1[] = {1,1,0,0};
int dx2[] = {1,0,1,0};
int dy1[] = {0,0,1,1};
int dy2[] = {0,1,0,1};
*/
int tour(int x1,int x2,int y1,int y2){
	if(x1>=H or x2>=H or y1>=W or y2>=W or
		ch[x1][y1]=='#' or ch[x2][y2]=='#'){
		return -1000000;
	}
	if(x1==H-1 and y1 == W-1){
		return ch[x1][y1]=='*';
	}
	if(dp[x1][y1][x2]!= -1){
		return dp[x1][y1][x2];
	}
	int result=-1000000;
	loop(i,0,3)
		result=max(result,tour(x1+dx1[i],x2+dx2[i],y1+dy1[i],y2+dy2[i]));

	result += (ch[x1][y1]=='*');	
	result += (ch[x2][y2]=='*');
	if(x1==x2 and y1==y2 and ch[x1][y1]=='*'){
		result -= 1;//arrived at same place so reduce 1 to avoid double counting
	}
	return dp[x1][y1][x2]=result;	
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		cin>>W>>H;
		memset(dp,-1,sizeof(dp));
		loop(i,0,H-1)
			loop(j,0,W-1)
				cin>>ch[i][j];
		int ans = tour(0,0,0,0);
		cout<<ans<<endl;		
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
