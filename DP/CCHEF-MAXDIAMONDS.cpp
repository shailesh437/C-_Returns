#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
int N;
int grid[50][50];
int dp[50][50][50];
int dx1[]={1,0,1,0};
int dy1[]={0,1,0,1};
int dx2[]={1,0,0,1};
int dy2[]={0,1,1,0};

int getMaxDiamonds(int x1,int y1,int x2,int y2){
if(x1>=N or x2>=N or y1>=N or y2>=N or grid[x1][y1]==-1 or grid[x2][y2]==-1){
	return -100000;
}
if(x1==N-1 and y1==N-1){
	return grid[x1][y1]==1;
}
if(dp[x1][y1][x2]!=-1){
	return dp[x1][y1][x2];
}
int result=-100000;
loop(i,0,3)
	result = max(result,
				 getMaxDiamonds(x1+dx1[i],
							 	y1+dy1[i],
							 	x2+dx2[i],
							 	y2+dy2[i]
				 				)
				 );
result+= grid[x1][y1]==1;
result+= grid[x2][y2]==1;
if(x1==x2 and y1==y2 and grid[x1][y1]==1)
	result -= 1;
return dp[x1][y1][x2]=result;	
}
int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		cin>>N;
		memset(dp,-1,sizeof(dp));
		loop(i,0,N-1)
			loop(j,0,N-1)
				cin>>grid[i][j];
		int ans = getMaxDiamonds(0,0,0,0);	
		if(ans<0) ans=0;
		cout<<ans<<endl;		

	} 
	return 0;
	}
