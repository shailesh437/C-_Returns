#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define R 3
#define C 3
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
void printUtil(string arr[R][C], 
	int firstRowCol,  
	int totalRow )
{
	if(firstRowCol >=C || arr[0][firstRowCol].length()==0)
		return;
	vector<string> res;
	int r=0;
	res.push_back(arr[r][firstRowCol]);
	r++;
	int c=0;
	int lastRowCol=0;
	while(r<R and lastRowCol<C){
		while(arr[r][c].length()>0){
			res.push_back(arr[r][c]);
			c++;
			break;
		}
		r++;

		if(r==(R-1)){
			res.push_back(arr[r][lastRowCol++]); 
			for(string s:res)
				cout<<s<<" ";
			cout<<endl;
			res.clear();
			r=0;
		}
	}
	printUtil( arr , 
		firstRowCol+1,  
		totalRow );
}
void justPrintArr(int Arr[4][3],int RR,int CC){
	
	for(int i=0;i<RR;i++){
		for(int j=0;j<CC;j++){
			cout<<Arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void NowPrintSentence(vector<string> &sentence){
	for(int w=0;w<sentence.size();w++){
		cout<<w<<" ";
	}
	cout<<endl;
}
void resetSelfAndDescend(int limit[4],
	int limit_val[4],
	int row){
	limit_val[row]=-1;
	for(int i=row+1;i<4;i++)
		limit_val[i]=-1;
}
void printSen(vector<int> vecS){ 
	for(int s:vecS){
		cout<<s<<" ";
	} 
	cout<<endl;
}
void check( int Arr[4][3],
			int limit[4],        //{2,1,2,2}
			int currRowColPtr[4],//{-1,-1,-1,-1}
			int curr_Row, 
			vector<int> res,
			int counter){ 
	if(curr_Row == -1 ){
		return;
	}
	bool exit = true;
	for(int i=0;i<4;i++){
		if(currRowColPtr[i]<limit[i])
			exit = false;
	}
	if(exit) return;
	currRowColPtr[curr_Row]++;
	if(curr_Row == 3 and 
		currRowColPtr[curr_Row]<=limit[curr_Row]){ //LAST ROW 
		res.push_back(Arr[curr_Row][currRowColPtr[curr_Row]]);
	printSen(res);
	res.pop_back();	
} else if(currRowColPtr[curr_Row]>limit[curr_Row]){
	resetSelfAndDescend(limit,currRowColPtr,curr_Row);
	curr_Row=curr_Row-1; 	
	res.pop_back();		 
}else{
	res.push_back(Arr[curr_Row][currRowColPtr[curr_Row]]);
	curr_Row = curr_Row + 1;	 
}		
check(Arr,limit,currRowColPtr,curr_Row,res,counter+1);
}
int TOTROWS;
int TOTCOLS;

void check2(int Arr[4][3],
			int limit[4],        //{2,1,2,2}
			int currRowColPtr[4],//{-1,-1,-1,-1}
			int curr_Row, 
			vector<int> res,
			int counter){

	for(int c=0;c<=limit[curr_Row] and curr_Row<3;c++){
		res.push_back(Arr[curr_Row][c]);
		check2(Arr,limit,currRowColPtr,curr_Row+1,res,counter);
		res.pop_back();
	}
	for(int c=0;c<=limit[curr_Row] and curr_Row==3;c++){
		res.push_back(Arr[curr_Row][c]);
		printSen(res);
		res.pop_back();
	}


}
int TOT_ROW,TOT_COL; 
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		/*string arr[R][C]  = {{"you", "we"},
		{"have", "are"},
		{"sleep", "eat", "drink"}};

		printUtil(arr,0,R );*/

		int Arr[4][3]={{1,2,3},{4,5,0},{7,8,9},{9,0,9}};
		int limit[4]={2,1,2,2}; //0 based 
		int limit_val[4]={-1,-1,-1,-1};
		int CC = sizeof Arr[0]/sizeof Arr[0][0];
		int RR = sizeof Arr/sizeof Arr[0];
		//cout<<CC<<"-"<<RR;
		justPrintArr(Arr,RR,CC);
		TOTROWS = sizeof Arr/sizeof Arr[0];
		TOTCOLS = sizeof Arr[0]/sizeof Arr[0][0];
		int curr_Row=0;
		vector<int> res;
		int cnt=0;
		//check(Arr,limit,limit_val,curr_Row,res,cnt);
		check2(Arr,limit,limit_val,curr_Row,res,cnt);
		cout<<endl;
		std::vector<string> SEN;
		TOT_COL = CC;
		TOT_ROW = RR;      
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();

	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
