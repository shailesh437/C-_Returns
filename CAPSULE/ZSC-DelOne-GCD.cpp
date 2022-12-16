int getGcd(int A,int B){
    if(B==0) return A;
    return getGcd(B,A%B);
} 
int Solution::solve(vector<int> &A) {
   vector<int> pgcd(A.size()); 
   vector<int> sgcd(A.size());
   pgcd[0]=A[0];
   sgcd[A.size()-1]=A[A.size()-1];
   for(int i=1;i<A.size();i++){
       pgcd[i]=getGcd(pgcd[i-1],A[i]);
   }
   for(int i=A.size()-2;i>=0;i--){
       sgcd[i]=getGcd(sgcd[i+1],A[i]);
   } 
   int ans=INT_MIN;
   for(int i=0;i<A.size();i++){
       if(i==0){
           ans=max(ans,sgcd[1]);
           continue;
       }
       if(i==A.size()-1){
           ans=max(ans,pgcd[A.size()-2]);
           break;
       }
       ans=max(ans,getGcd(pgcd[i-1],sgcd[i+1]));
   }
   return ans;
}
