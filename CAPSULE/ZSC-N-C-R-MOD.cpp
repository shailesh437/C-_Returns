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
int solveForAns(int N,int r,int MOD,vector<vector<int>>& mat){
	int filledRow=0;
	int n=0; 
	while(n<N){
		for(int j=1;j<=r;j++){
			mat[1-filledRow][j]=(mat[filledRow][j-1]%MOD+ 
				mat[filledRow][j]%MOD)%MOD; 

		}  
		filledRow=1-filledRow;	
		n++;
	}
	return mat[filledRow][r];
}
int solve(int A, int B, int C) {
	vector<vector<int>> mat(2,vector<int>(B+1,0)); 
	for(int i=0;i<2;i++){
		mat[i][0]=1;
	}
	for(int i=1;i<=B;i++){
		mat[0][i]=0;
	} 
	int ANS = solveForAns(A,B,C,mat);
	return ANS;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int  A = 1000000;
		int  B = 1;
		int  C = 999999;
		/*int  A = 5;
		int  B = 2;
		int  C = 999999;*/
		cout<<solve(A,B,C);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
