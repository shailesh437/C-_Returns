vector<vector<int>> dp;
int getMinDistance(string A,string B,int a_index, int b_index){
    if(a_index==A.length() and b_index==B.length()){
        return 0; 
    }
    if(a_index==A.length() and b_index<B.length()){
        return B.length()-b_index;
    }
    if(b_index==B.length() and a_index<A.length()){
        return A.length()-a_index;
    }   
    if(dp[a_index][b_index]!=-1){
        return dp[a_index][b_index];
    }
    int ans=0;
    if(A[a_index]==B[b_index]){
        ans=getMinDistance(A,B,a_index+1,b_index+1);
    }else{
        ans=1+ 
        min(
        min(
            getMinDistance(A,B,a_index+1,b_index+1),
            getMinDistance(A,B,a_index,b_index+1)
           ),
           getMinDistance(A,B,a_index+1,b_index)
        );
    }
    return dp[a_index][b_index]=ans;
}

int Solution::minDistance(string A, string B) {
    string C=A;
    string D=B;
    dp=vector<vector<int>>(A.size(),vector<int>(B.size(),-1));         
    return getMinDistance(C,D,0,0);
}
