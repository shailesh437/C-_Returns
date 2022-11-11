bool isPalindrome(string A,int s,int e){
    if(s>=e) return true;
    if(A[s]==A[e]){ 
                 return isPalindrome(A,s+1,e-1);
    }
    return false;
}
int Solution::solve(string A) {
    if(A.length()<=200){
        if(!isPalindrome(A,0,A.length()-1)){
        return 0;
        }
    }else{
         int startPointer = 0;
         int endPointer=A.length()-100;
         string B = A.substr(startPointer,100)+
                    A.substr(endPointer,100);
         while(startPointer<endPointer){
             if(!isPalindrome(B,0,B.length()-1)){
                return 0;
             }
             startPointer+=100;
             endPointer-=100;
         }            
    } 
    return 1;
}
