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
int countWays(vector<vector<int> > &A,
              int src_row_pos,
              int src_col_pos,
              int tgt_row_pos,
              int tgt_col_pos,
              int cells_in_path,
              int non_block_cells){
// cout<<endl<<"Entered with "<<src_row_pos<<":"<<src_col_pos<<endl;
 
if(src_row_pos==tgt_row_pos and src_col_pos==tgt_col_pos 
    ){
    cout<<endl<<"cells_in_path="<<cells_in_path<<endl;
}

 if(src_row_pos==tgt_row_pos and src_col_pos==tgt_col_pos 
    and cells_in_path==non_block_cells) return 1;
    if(src_row_pos==tgt_row_pos and src_col_pos==tgt_col_pos 
    and cells_in_path!=non_block_cells) return 0;
 if(src_row_pos<0 or src_row_pos>=A.size()) return 0;                 
 if(src_col_pos<0 or src_col_pos>=A[0].size()) return 0;  
 if(A[src_row_pos][src_col_pos]==-1) return 0;
 
 A[src_row_pos][src_col_pos]=-1;
 //cells_in_path++;
 int ans =  
        countWays(A,src_row_pos+1,src_col_pos,tgt_row_pos,tgt_col_pos,cells_in_path+1,non_block_cells)+
        countWays(A,src_row_pos-1,src_col_pos,tgt_row_pos,tgt_col_pos,cells_in_path+1,non_block_cells)+
        countWays(A,src_row_pos,src_col_pos+1,tgt_row_pos,tgt_col_pos,cells_in_path+1,non_block_cells)+
        countWays(A,src_row_pos,src_col_pos-1,tgt_row_pos,tgt_col_pos,cells_in_path+1,non_block_cells);

  A[src_row_pos][src_col_pos]=0;
  //cells_in_path--;
  return ans;
}

int solve(vector<vector<int> > &A) {
    int one_row_pos=0;
    int one_col_pos=0;
    int two_row_pos=0;
    int two_col_pos=0;
    int non_block_cells=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==1){
                one_row_pos=i;
                one_col_pos=j;
            }else if(A[i][j]==2){
                two_row_pos=i;
                two_col_pos=j;
            }else{
                if(A[i][j]==0)
                non_block_cells++;
            }
        }
    } 
    int cells_covered=-1;
    cout<<endl<<non_block_cells;
    int ans = countWays(A,one_row_pos,one_col_pos,
                          two_row_pos,two_col_pos,cells_covered,non_block_cells);
    return ans;                      
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<vector<int>> A = {{ 1, 0, 0, 0}
        					      ,{ 0, 0, 0, 0}
        						  ,{ 0, 0, 2, -1}};

      /*  A={{0,1},
           {2,0}};  
      */  /*A ={{2,-1},
            {0,0},
            {-1,1}};      
        */int ans = solve(A);
        cout<<endl<<"ANS = "<<ans;						  
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
