long Solution::subarraySum(vector<int> &A) {
    long ANS;
    for(int i=0;i<A.size();i++){
        ANS += A[i]*(i+1)*(A.size()-i);
    }
    return ANS;
}
