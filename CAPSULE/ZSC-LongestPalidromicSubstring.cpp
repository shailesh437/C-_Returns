string expand(string A,int start, int end){ 
    int p1=0,p2=0;
    while(start>=0 and end<A.length() and A[start]==A[end]){
        p1=start;
        p2=end;
        start--;
        end++;        
    } 
   return A.substr(p1,p2-p1+1);
}
string Solution::longestPalindrome(string A) {
     if(A.length()==1) return A;
    string ANS="";
     for(int i=0;i<A.length();i++){
            string oAns = expand(A,i,i);
            string eAns = expand(A,i,i+1);
            if(oAns.length()>ANS.length()){
                ANS=oAns;
            } 
            if(eAns.length()>ANS.length()){
                ANS=eAns;
            }         
     }
     return ANS;
}
