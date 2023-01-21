int Solution::solve(vector<int> &A) {
    map<int,int> m;
    m[A[0]]=1;
    int ans=INT_MAX;
    for(int i=1;i<A.size();i++){
        if(A[i]==A[i-1]) return 1;
        if(m[A[i]] != 0 ){
            ans=min(ans,i+1-m[A[i]]);
        }else{
            m[A[i]]=i+1;
        }
    }  
    if(ans==INT_MAX) return -1;
    return ans; 
}
