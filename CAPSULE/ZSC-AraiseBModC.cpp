int Solution::solve(int A, int B, int C) {
     long ans=1;
    for(int i=1;i<=B;i++){
        ans=(ans*A)%C;
        ans%=C;
    }
    return (int)ans;
}
