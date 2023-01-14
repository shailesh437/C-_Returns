int Solution::solve(vector<int> &A) {
    int start=0;
    int end=A.size()-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(A[mid]!=A[mid-1] and A[mid]!=A[mid+1]) return A[mid];
        if(A[mid]==A[mid-1]){
            if((mid-1)%2==0)
            start=mid+1;
            else
            end=mid-2;
        }else{
            if( mid%2==0 )
            start=mid+2;
            else
            end=mid-1;
        }
    }
    return -1;
}
