int Solution::solve(vector<int> &A, int B) {
    long ans=0;
    long placeValue=1;
    for(int i=A.size()-1;i>=0;i--){
        ans+=(A[i]%B*placeValue)%B;
        placeValue=(placeValue*10)%B;
    }
    return ans%B;
}
