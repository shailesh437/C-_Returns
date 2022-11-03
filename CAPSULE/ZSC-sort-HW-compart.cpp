bool compare(int a, int b)
{
    //if(a<10) a*=10;
    //if(b<10) b*=10;
    if( (a%100)/10 <  (b%100)/10 ) return true;
    if( (a%100)/10  == (b%100)/10 and a>b) return true;
    return false; 
}
vector<int> Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end(),compare);
    return A;
}
