int count(vector<vector<int> > &A,int row,int col,int lastRow,int lastCol){

    if(row>lastRow or col>lastCol) return 0;

    if(A[row][col]==1) return 0;

    if(row==lastRow and col ==  lastCol) return 1;

    return count(A,row+1,col,lastRow,lastCol) +  
           count(A,row,col+1,lastRow,lastCol);
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    return count(A,0,0,A.size()-1,A[0].size()-1);
}
