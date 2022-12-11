vector<int> Solution::solve(vector<int> &A) {
    int overallXor=0;
    for(int i=0;i<A.size();i++){
        overallXor^=A[i];
    }
    int s1=0,s2=0;
    int setBitPos=0;
    for(int i=0;i<32;i++){
        if(overallXor & (1<<i)){
            setBitPos=i;
            break;
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i] & (1<<setBitPos)){
            s1^=A[i];
        } else{
            s2^=A[i];
        }
    }
    vector<int> ANS;
    if(s1<s2){
        ANS.push_back(s1);
        ANS.push_back(s2);
    }else{
        ANS.push_back(s2);
        ANS.push_back(s1);       
    }
    return ANS;
}
