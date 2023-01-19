int gcd(int X,int Y){
    if(Y==0) return X;
    return gcd(Y,X%Y);
}
long long int getRankOfAttempted(long long int attempt,
                       int B,int C ){

long long int lcm= (long long int)B*(long long int)C;
lcm/=(long long int) gcd(B,C);

return attempt/(long long int)B+
       attempt/(long long int)C-
       attempt/(long long int)lcm;

}
int Solution::solve(int A, int B, int C) {
long long int rangeEnd=(long long int)A*
                       (long long int)min(B,C);
long long int rangestart = 1;
long long int possibleAns = 1;
while(rangestart <= rangeEnd){
    long long int attempt = rangestart +(rangeEnd-rangestart)/2;
     long long int rankOfAttempted = 
                    getRankOfAttempted(attempt,B,C);
     if(rankOfAttempted==A){
         rangeEnd=attempt-1;
         possibleAns = attempt;
     } else if(rankOfAttempted < A){
         rangestart=attempt+1;
     } else{
         rangeEnd=attempt-1;
     }             

}
return possibleAns%(1000000007);
}
