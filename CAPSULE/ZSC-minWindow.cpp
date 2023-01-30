string Solution::minWindow(string A, string B) {
    if(A==B) return A;
     if (A.find(B) != std::string::npos) {
     return B;
    }
   int need = B.length();//this many matches are required
    map<char,int> reqdFreq; 
    map<char,int> currFreq;  
    for(char c:B){
        reqdFreq[c]++;
    }
    int idx_A=0;
    int minWindowSize=INT_MAX;
    while(need>0 and idx_A<A.length()){

      if(reqdFreq[A[idx_A]]>0 and  
         currFreq[A[idx_A]] <
         reqdFreq[A[idx_A]] ) 
        need--; 
        currFreq[A[idx_A]]++;   
        idx_A++;
    }
    if(need>0) return "";
    minWindowSize=min(minWindowSize,idx_A);
    int si=0;
    int ei=idx_A-1; 
    int ans_si=0;
    int ans_ei=0; 
    while(si<ei and ei<A.length()){
        while(si<ei and need<1){
             si++;
           currFreq[A[si-1]]--; 
           if(reqdFreq[A[si-1]]>0 and 
              currFreq[A[si-1]]<reqdFreq[A[si-1]])
              need++;   
              if(need==0 and 
                   (ei-si+1) < minWindowSize){ 
                    minWindowSize=ei-si+1;  
                ans_ei=ei;
                ans_si=si;
                } 
        }
         while(ei<A.length() and  need>0 ){
            ei++;
            if(reqdFreq[A[ei]]>0 and 
             currFreq[A[ei]]<reqdFreq[A[ei]])
                need--;
            currFreq[A[ei]]++; 
            if(need==0 and 
           (ei-si+1) < minWindowSize){ 
                minWindowSize=ei-si+1;  
                ans_ei=ei;
                 ans_si=si;
             } 
         } 
        if((ei-si+1) < minWindowSize){
            minWindowSize=ei-si+1; 
            cout<<endl<<A.substr(si,ei-si+1);
        }
    } 
        if(si==ei) return "";
        return A.substr(ans_si,ans_ei- ans_si  +1);
}
