void dfs(vector<string> &A,int i,int j,
         vector<vector<bool>> &visited){
   visited[i][j]=true;
   int dx[]={-1,0,1,0};           
   int dy[]={0,-1,0,1};
   for(int k=0;k<4;k++){
       int ni=i+dx[k];
       int nj=j+dy[k];
       if(ni>=0 and ni<A.size() and nj>=0 and nj<A[0].size() 
       and visited[ni][nj]==false and A[ni][nj]=='X'){
           dfs(A,ni,nj,visited);
       }
   }           

}
int Solution::black(vector<string> &A) {
    int ans =0;
    vector<vector<bool>> visited(A.size(),vector<bool>(A[0].size(),false));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]=='X' and !visited[i][j]){
                dfs(A,i,j,visited);
                ans++;
            }
        }
    }
    return ans;
}
