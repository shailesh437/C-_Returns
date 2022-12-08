
int Solution::solve(vector<vector<int>> &A, int B) {
    if(A.size()==1){
        for(int i=0;i<A[0].size();i++){
            if(A[0][i]==B) return 1009+i+1;
        }
        return -1;
    }
    int col=A[0].size();
    int row=A.size();
    int r=0,c=col-1;
    int ans=-1;
    int prev_ans=INT_MAX;
    while(c>=0 and r<row){
        if(A[r][c]==B){
            ans= min(prev_ans,(r+1)*1009+(c+1));
            prev_ans=ans;
        }
        if(r<row-1 and A[r+1][c]>B){
            c--;
        }
        else if(c>=1 and A[r][c-1]<B){
            r++;
        }else{
        	c--;
        }
    }   
    return ans;
}
