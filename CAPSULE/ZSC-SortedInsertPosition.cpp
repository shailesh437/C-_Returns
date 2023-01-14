int bsearch(int start,int end,int val,vector<int> &A){
    int possiblePosition=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(val==A[mid]) return mid;
        if(A[mid]<val){
            start=mid+1;
            possiblePosition=mid+1;
        }else{
            end=mid-1;
            possiblePosition=mid-1;
        }
    }
    if(possiblePosition<=end and possiblePosition>=start)
    return possiblePosition;
    if(possiblePosition>=end)
    return end+1;
    return -1;
}
int Solution::searchInsert(vector<int> &A, int B) {
    return bsearch(0,A.size()-1,B,A);
}
