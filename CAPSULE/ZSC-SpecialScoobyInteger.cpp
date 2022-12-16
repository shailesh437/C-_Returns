int gcd(int A,int B){
    if(B==0) return A;
    return gcd(B,A%B);
}
int Solution::solve(int A, int B, int C) {
    long long  LCM=B*C/gcd(B,C);
    if(LCM>A) return 0;
    else return A/LCM;
}
