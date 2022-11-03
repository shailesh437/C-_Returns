int getFactors(int X){
    int ans=2;
    for(int i=2;i<=sqrt(X);i++){
        if(X%i==0) ans+=2;
    }
    return ans;
}
bool compare(int a,int b){
    int fact_a_count=getFactors(a);
    int fact_b_count=getFactors(b);
    if(fact_a_count < fact_b_count) return true;
    if(fact_a_count == fact_b_count and a<b) return true;
    return false;
}
vector<int> Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end(),compare);
    return A;
}
