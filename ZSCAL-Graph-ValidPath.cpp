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
void reachable(int currentX,int currentY,
               int A,
               int B,
               vector<vector<int>> &blocked,
               vector<vector<bool>> &visited,
               bool &ans){


    if(currentX<0 or currentX>A or currentY<0 or currentY>B or 
        blocked[currentX][currentY]>0 or 
        visited[currentX][currentY]){
        return;
    }

    visited[currentX][currentY]=true;
    if(currentX==A and currentY==B){
        ans=true;
        return;
    }

    int dx[]={1,1,0,-1,-1,-1,0,1};
    int dy[]={0,1,1,1,0,-1,-1,-1};
    for(int k=0;k<8;k++){
        reachable(currentX+dx[k],
                  currentY+dy[k],
                   A,
                   B,
                   blocked,
                   visited,
                   ans); 
    }                 

}
 


string solve(int A, int B, int C, 
int D, 
vector<int> &E, 
vector<int> &F) {
    vector<vector<int>> blocked(A+1,vector<int>(B+1,0));
    vector<vector<bool>> visited(A+1,vector<bool>(B+1,false));
    for(int i=0;i<=A;i++){
            for(int j=0;j<=B;j++){
                for(int k=0;k<C;k++){
                    int dist = pow((E[k] - i), 2)+
                               pow((F[k] - j), 2);
                    if(dist<=D*D){
                        blocked[i][j]=1;
                    }
                }
            }
        }     
    /*  for(int i=0;i<=A;i++){
    	cout<<endl;
    	for(int j=0;j<=B;j++){
    		cout<<blocked[i][j];
    	}
    }*/
  
    bool ans = false;
    reachable(0,0,A,B,blocked,visited,ans);
    
    if(ans) return "YES";
    return "NO";
}


int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A,B,C,D;
		cin>>A>>B>>C>>D;
		vector<int> circle_x;
		vector<int> circle_y;
		for(int i=0;i<C;i++){
			int x;
			cin>>x;
			circle_x.push_back(x);
		} 
		for(int i=0;i<C;i++){
			int x;
			cin>>x;
			circle_y.push_back(x);
		} 
		string ans =  solve(A,B, C, 
							D, 
							circle_x, 
							circle_y);

		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
