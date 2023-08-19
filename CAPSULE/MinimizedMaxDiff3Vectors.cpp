/*
Array 3 pointers 
You are given 3 sorted arrays A, B and C.

Find i, j, k such that : max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).
*/

int Solution::minimize(const vector<int> &A, 
                       const vector<int> &B, 
                       const vector<int> &C) {


                            int a=A.size()-1;
    int b=B.size()-1;
    int c=C.size()-1;
    int ans=INT_MAX;
    while(a>=0 and b>=0 and c>=0 ){

        ans=min(ans,max(max(abs(A[a]-B[b]),abs(B[b]-C[c])),
            abs(A[a]-C[c])));

        if(A[a]>=B[b] and A[a]>=C[c] ){
            a--;
        }else if(B[b]>=A[a] and B[b]>=C[c] ){
            b--;
        }else if(C[c]>=A[a] and C[c]>=B[b] ){
            c--;
        }
        
        if(ans==0){
            break;
        }         
    } 
    return ans;
}
