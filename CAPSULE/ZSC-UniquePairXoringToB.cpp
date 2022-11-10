int Solution::solve(vector<int> &A, int B) {
    int ANS=0;
    map<int,int> m;
    m[A[0]]++;
    for(int i=1;i<A.size();i++){
         int b=A[i]^B;
         if(m[b]>0){
            ANS++;  
         }
         m[A[i]]++;
    }
    return ANS;
}
