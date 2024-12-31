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

void fillMat(int center_x,int center_y,int radii,
	vector<vector<int>> &mat,
	int A,
	int B){
	int lowerBottom_x = max(0,center_x-radii);
	int lowerBottom_y = max(0,center_y-radii);

	int topRight_x=min(A,center_x+radii);
	int topRight_y=min(B,center_y+radii);

	cout<<lowerBottom_x<<":"<<lowerBottom_y<<endl;
	cout<<topRight_x<<":"<<topRight_y;
	//return ;
	for(int i=lowerBottom_y;i<=topRight_y;i++){
		for(int j=lowerBottom_x;j<=topRight_x;j++){
			mat[i][j]=1;
		}
	}

}

class Solution{
public:
	string solve(int A, 
		int B, 
		int C, 
		int D, 
		vector<int> &E, 
		vector<int> &F);	
};

bool checkPathExists(vector<vector<int>> &mat,
	int curr_x,int curr_y,
	int dest_x,int dest_y,
	vector<vector<bool>> &visited){
	cout<<endl<<curr_x<<"::"<<curr_y<<":"<<dest_x<<":"<<dest_y;;
	if(curr_x==dest_x and curr_y==dest_y){
		return true;
	}
	if(curr_x>dest_x or curr_y>dest_y){
		return false;
	}
	if(curr_x<0 or curr_y<0){
		return false;
	}
	if(mat[curr_x][curr_y]==1){
		return false;
	}
	if(visited[curr_x][curr_y]){
		return false;
	}
	if(mat[curr_x][curr_y]==-1){
		return false;
	}
	visited[curr_x][curr_y]=true;
	vector<int> dx={1 ,1 , 0, -1, -1, -1, 0, 1};
	vector<int> dy={0 ,1 , 1,  1,  0, -1,-1,-1};
	bool ans=false;
	for(int i=0;i<8;i++){
		if( curr_x+dx[i]>=0 and curr_x+dx[i] <=dest_x and 
			curr_y+dy[i]>=0 and curr_y+dy[i] <=dest_y and 
			mat[curr_x+dx[i]][curr_y+dy[i]]!=-1  and 
			!visited[curr_x+dx[i]][curr_y+dy[i]]
			)  
		ans=ans||checkPathExists(mat,curr_x+dx[i],
			curr_y+dy[i],
			dest_x,dest_y,visited);

	}
	return ans;
}

bool pointInCircle(int center_x,int center_y,int radii,int checkPoint_x,int checkPoint_y){

	if(
	(
	(checkPoint_x - center_x)*(checkPoint_x - center_x) + 
	(checkPoint_y - center_y)*(checkPoint_y - center_y)
	)<=radii*radii
	)
		return true;
	return false;
}

string Solution::solve(int A, 
	int B, 
	int C, 
	int D, 
	vector<int> &E, 
	vector<int> &F) {


	vector<vector<int>> mat(A+1,vector<int>(B+1,0));
	 if(mat[A][B]==1){
		return "NO";
	}

	for(int i=0;i<=A;i++){
		for(int j=0;j<=B;j++){
			for(int k=0;k<C;k++){
				if(pointInCircle(E[k],F[k],D,i,j)){
					mat[i][j]=-1;
					break;
				}
			}
		}
	}




	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			cout<<mat[i][j]<<"";
		}
		cout<<endl;
	}
	vector<vector<bool>> visited(A+1,vector<bool>(B+1,0));

	return checkPathExists(mat,0,0,A,B,visited)?"YES":"NO";
}



int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Solution *s = new Solution();
		int x=41;
		int y=67;
		int N=5;
		int R=0;
		vector<int> A={17,16,12,0,40};
		vector<int> B={52,61,61,25,31};
		string ans = s->solve(x,y,N,R,A,B);
		cout<<endl<<"ans = "<<ans; 
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
