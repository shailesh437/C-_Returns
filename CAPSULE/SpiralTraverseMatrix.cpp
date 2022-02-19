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
/*
void printSpiral(int matrix[][], int row,int col){
	int rowBoundary=row;
	int colBoundary=col;
	int rowStart=1;
	int colStart=1;
	int rowp=0;
	int colp=0;
	int wl=0;
	while(rowBoundary>2 and colBoundary>2){
		colp++;rowp++;
	while(colp<=colBoundary){
		cout<<rowp<<" "<<colp++<<endl;
	}
	rowp++;colp--;
	while(rowp<=rowBoundary){
	 	cout<<rowp++<<"-"<<colp<<endl;
	}
	colp--;rowp--;
	 while(colp>=colStart){
	 	cout<<rowp<<"-"<<colp--<<endl;
	 }
	 rowp--;colp++;
	while(rowp>rowStart){
	 	cout<<rowp--<<"-"<<colp<<endl;
	 }
	 colBoundary--;
	 rowBoundary--;
	 colStart++;
	 rowStart++;
	}


}
*/

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {

	int rowEnd=r-1;
	int colEnd=c-1;
	int rowStart=0;
	int colStart=0; 
	vector<int> ans;
	vector<int> ans1; 
	//while(rowBoundary>2 and colBoundary>2 and ansCounter<16){
	if(r==1 && c>1){
		for(int i=0;i<c;i++){
			ans1.push_back(matrix[0][i]);
		}
		return ans1;
	}
	if(r>1 && c==1){
		for(int i=0;i<r;i++){
			ans1.push_back(matrix[i][0]);
		}
		return ans1;
	}
	int lastColReached=0,lastRowReached=0,i;
	while( colEnd>=colStart and rowEnd>=rowStart){
		for(i=colStart;i<=colEnd;i++){
			ans.push_back(matrix[rowStart][i]);
		}
		lastColReached = i-1;
		rowStart=rowStart+1;
		for(i=rowStart;i<=rowEnd;i++){
			ans.push_back(matrix[i][lastColReached]);
		}
		colEnd=colEnd-1;
		lastRowReached=i-1; 
		if(colEnd>=colStart and rowEnd>=rowStart){
			for(i=colEnd;i>=colStart;i--){
			ans.push_back(matrix[lastRowReached][i]);
		}
		rowEnd=rowEnd-1;
		lastColReached=i+1;
		for(i=rowEnd;i>=rowStart;i--){
			ans.push_back(matrix[i][lastColReached]);
		}
		colStart=colStart+1; 
		}		

	}

	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){/*
		int r=5,c=4;
		int matrix[][4] = {{1,  2,  3,  4},
           				  { 5,  6,  7,  8},
           				  { 9, 10, 11, 12},
           				  {13, 14, 15, 16},
           				  {17, 18, 19, 20}
           				   };

        */ 
		int r=7,c=10;

		vector<vector<int>> matrix(r,vector<int>(c));
		matrix[0]={72 ,0 ,62 ,0 ,82 ,52 ,1 ,28 ,4 ,88};
		matrix[1]={78 ,27 ,38 ,14 ,85 ,91, 77, 86, 2 ,31};
		matrix[2]={45, 31, 42, 54 ,5  ,78, 44 ,68 ,71, 32};
		matrix[3]={ 2, 96 ,33, 16, 48, 67, 69, 50, 96, 73};
		matrix[4]={90, 74, 52 ,80, 40, 37, 23, 17, 75, 25};
		matrix[5]={48, 73, 57 ,42, 79, 62, 73, 23, 83, 44};
		matrix[6]={ 7, 85, 92 ,40, 53, 41,  8, 22, 43, 56};

		 //7 23 4 3 25 22 12 26 3 28 3 26

		/*int r=3,c=5;

		vector<vector<int>> matrix(r,vector<int>(c));
		matrix[0]={6 ,6 ,2 ,28 ,2};
		matrix[1]={12 ,26 ,3 ,28 ,7};
		matrix[2]={ 22 ,25 ,3 ,4 ,23};*/

	/*int r=6,c=4;
	vector<vector<int>> matrix(r,vector<int>(c));
	matrix[0]={67 ,80 ,44 ,28 }; 
	matrix[1]={17 ,77, 74 ,61 } ;
	matrix[2]={62 ,96 ,70, 57};
	matrix[3]={21 ,12 ,9 ,85 };  
	matrix[4]={51 ,71 ,11 ,86 };
	matrix[5]={83 ,51, 27 ,42};*/


		//5 11 30 5 19 19
		/*int r=2,c=3;
		vector<vector<int>> matrix(r,vector<int>(c));
    	matrix[0]={5 ,11 ,30}; 
		matrix[1]={5 ,19, 19} ;*/



	/*int r=7,c=3;
	vector<vector<int>> matrix(r,vector<int>(c));
	matrix[0]={21 ,26 ,73}; 
	matrix[1]={22 ,72 ,0} ;
	matrix[2]={0  ,90 ,43} ;
	matrix[3]={33 ,46 ,29} ;
	matrix[4]={57, 32 ,74} ;
	matrix[5]={34, 95 ,41} ;
	matrix[6]={25, 74 ,67} ;*/




	vector<int> ans = spirallyTraverse(matrix,r,c);
	cout<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}
	 #ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
