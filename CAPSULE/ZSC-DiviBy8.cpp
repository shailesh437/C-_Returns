int Solution::solve(string A) {
   int ans=0;
   if(A.length()==1){
        if(A=="8" or A=="0") ans =  1;
   }else if(A.length()==2){
       int u = A[A.length()-1]-'0';
       int t = A[A.length()-2] - '0';
       if((t*10+u)%8==0) ans =  1;
   }else{
            int u1 = A[A.length()-1]-'0';
            int t1 = A[A.length()-2] - '0';
            int h1 = A[A.length()-3] - '0';
            if((h1*100+t1*10+u1)%8==0) ans =  1;
       
   } 
    return ans; 
}
