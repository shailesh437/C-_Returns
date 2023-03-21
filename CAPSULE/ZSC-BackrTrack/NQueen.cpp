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
void place_N_Queens(vector<vector<char>> mat,
	int currentRow,
	int TotalRow,
	vector<bool> cols,
	vector<bool> diagonalNo,
	vector<bool> antiDiagonalNo,
	vector<vector<string>> &ANS){

	if(currentRow==TotalRow){
		vector<string> Soln;
		Soln.clear();
		//all queens placed,so its one of the soln
		for(int i=0;i<mat.size();i++){
			logarr(mat[i],0,mat[i].size()-1);
			Soln.push_back(string(mat[i].begin(),mat[i].end()));
		}
		cout<<endl<<"-------------------------------\n";
		ANS.push_back(Soln);
		return;
	}
	for(int col=0;col<TotalRow;col++){
		if(cols[col]==false and 
			diagonalNo[currentRow-col+TotalRow-1]==false and 
			antiDiagonalNo[currentRow+col]==false){
			mat[currentRow][col]='Q';
		cols[col]= true ;
		diagonalNo[currentRow-col+TotalRow-1] = true; 
		antiDiagonalNo[currentRow+col] = true;
		place_N_Queens(mat,currentRow+1,TotalRow,cols,diagonalNo,antiDiagonalNo,ANS);
		mat[currentRow][col]='.';
		cols[col]= false ;
		diagonalNo[currentRow-col+TotalRow-1] = false; 
		antiDiagonalNo[currentRow+col] = false;
	}
}

} 
vector<vector<string>> solveNQueens(int A) {
	vector<vector<char>> mat(A,vector<char>(A,'.'));
	int currentRow=0;
	int TotalRow=A;
	vector<bool> cols(A,false);
	vector<bool> diagonalNo(2*A-1,false);
	vector<bool> antiDiagonalNo(2*A-1,false);
	vector<vector<string>> ANS;
	place_N_Queens(mat,0,A,cols,diagonalNo,antiDiagonalNo,ANS);
	return ANS;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A=4;
		vector<vector<string>> ANS = solveNQueens(A);
		for(int i=0;i<ANS.size();i++){
			logarr(ANS[i],0,ANS[i].size()-1);
		}
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
