vector<int> Solution::dNums(vector<int> &A, int B) {
     vector<int> ANS;
    if(B>A.size()) return ANS;
    map<int,int> m;
  
    int start=0;
    int end=B;
    for(int i=start;i<end;i++){
        m[A[i]]++;
    }
    ANS.push_back(m.size());
    while(end<A.size()){
        start++;
        if(m[A[start-1]]<=1){
            auto it = m.find(A[start-1]);
            m.erase(it);
        }else{
            m[A[start-1]]--;
        }
        m[A[end]]++; 
        ANS.push_back(m.size());
        end++;
    }
    return ANS;
}
