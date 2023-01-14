int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    //fix row
    int startRow=0;
    int endRow=A.size()-1;

    while(startRow<=endRow){
        int mid=(startRow+endRow)/2;
        if(A[mid][0] == B) return 1;
        if(A[mid][0] < B){
            startRow=mid+1;
        }else{
            endRow=mid-1;
        }
    }
    int rowFixed=endRow;
    if(rowFixed<0 or rowFixed>=A.size()) return 0;
    int startCol=0;
    int endCol=A[0].size()-1;
    while(startCol<=endCol){
        int mid=(startCol+endCol)/2;
        if(A[rowFixed][mid]==B) return 1;
        if(A[rowFixed][mid]<B) startCol=mid+1;
        else endCol=mid-1;
    }
    return 0;
}
