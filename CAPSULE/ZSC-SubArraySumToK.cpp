vector<int> Solution::solve(vector<int> &A, int B) {
    int sum=0;
    int start=0;
    int end=0;
    bool found=false;
    vector<int> ANS;
    for(int i=0;i<A.size();i++){
        sum+=A[i]; 
        while(sum>B){
            start++;
            sum-=A[start-1];
        }
        if(sum==B){
            found=true;
            end=i;
            break;
        } 
    } 
    if(found){
        for(int i=start;i<=end;i++){
            ANS.push_back(A[i]);
        }
    }else{
        ANS.push_back(-1);
    }
    return ANS;
}
