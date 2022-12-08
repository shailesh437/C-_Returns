int Solution::trap(const vector<int> &A) {
    vector<int> maxLeft(A.size());
    vector<int> maxRight(A.size());
    maxLeft[0]=0;
    maxRight[A.size()-1]=0;
    for(int i=1;i<A.size();i++){
        maxLeft[i]=max(maxLeft[i-1],A[i-1]);
    }
    for(int i=A.size()-2;i>=0;i--){
        maxRight[i]=max(maxRight[i+1],A[i+1]);
    }
    int ans=0;
    for(int i=0;i<A.size();i++){
        int minVal=min(maxLeft[i],maxRight[i]);
        if(minVal>A[i])
        ans+= minVal-A[i];   
    }
    return ans;
}
