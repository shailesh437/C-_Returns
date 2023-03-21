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
bool isvalid(vector<vector<char> > &A,
	int row,
	int col,
	int ele,
	int totalRows){
	for(int i=0;i<totalRows;i++){
		if(A[row][i]== (ele+'0') or A[i][col]==(ele+'0')){
			return false;
		}
	}

	row=row-row%(int)sqrt(totalRows);
	col=col-col%(int)sqrt(totalRows);

	for(int i=0;i<sqrt(totalRows);i++){
		for(int j=0;j<sqrt(totalRows);j++){
			if(A[row+i][col+j]==ele+'0'){
				return false;
			}
		}
	}
	return true;
}
bool sudoKoSolved(vector<vector<char> > &A,
	int currentRow,
	int currentCol,
	int totalRows,
	vector<vector<char>> &mainAns
	){
	if(currentCol==totalRows){
		currentCol=0;
		currentRow+=1; 
	}

	if(currentRow==totalRows){
		// all placed well
		for(int i=0;i<A.size();i++){
			for(int j=0;j<A[0].size();j++){
				mainAns[i][j]=A[i][j];
			}
		}
		return true;
	}
	
	if(A[currentRow][currentCol]!='.'){
		return sudoKoSolved(A,currentRow,currentCol+1,totalRows,mainAns);
	}else{
		for(int c=1;c<=totalRows;c++){
			if(isvalid(A,currentRow,currentCol,c,totalRows)){
				A[currentRow][currentCol]=c+'0';
				if(sudoKoSolved(A,currentRow,currentCol+1,totalRows,mainAns)){
					return true;
				}	
				A[currentRow][currentCol]='.';
			}
		}
	}
	return false;
}
void solveSudoku(vector<vector<char> > &A) {
	vector<vector<char>> ANS(A.size(),vector<char>(A[0].size(),0));
	cout<<endl<<A.size()<<"::"<<A[0].size()<<endl;
	sudoKoSolved(A,0,0,A.size(),ANS);
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			A[i][j]=ANS[i][j];
		}
	}
	for(int i=0;i<A.size();i++){
		logarr(A[i],0,A[i].size()-1);
		cout<<endl;
	}
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<vector<char>>  A = {
			{'5','3','.','.','7','.','.','.','.' },
			{'6','.','.','1','9','5','.','.','.' },
			{'.','9','8','.','.','.','.','6','.' },
			{'8','.','.','.','6','.','.','.','3' },
			{'4','.','.','8','.','3','.','.','1' },
			{'7','.','.','.','2','.','.','.','6' },
			{'.','6','.','.','.','.','2','8','.' },
			{'.','.','.','4','1','9','.','.','5' },
			{'.','.','.','.','8','.','.','7','9' }
		}; 
		solveSudoku(A);
		/*for(int i=0;i<A.size();i++){
			logarr(A[i],0,A[i].size()-1);
		}*/
		char c='9';
		cout<<c<<endl;
		if(c==(9+'0')){
			c=8+'0';
		}
		cout<<c<<endl;

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
