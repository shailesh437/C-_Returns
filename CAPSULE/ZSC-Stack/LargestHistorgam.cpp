int Solution::largestRectangleArea(vector<int> &A) {
    if(A.size()==1) return A[0];
vector<int> nsli(A.size(),-1);
vector<int> nsri(A.size(),-1);
nsli[0]=-1;
stack<int> S;
S.push(0);
for(int i=1;i<A.size();i++){
    while(!S.empty() and A[S.top()]>=A[i]) S.pop();
    if(S.empty()) nsli[i]=-1;
    else
    nsli[i]=S.top();
    S.push(i);
}
while(!S.empty()) S.pop();
nsri[A.size()-1]=A.size();
S.push(A.size()-1);
for(int i=A.size()-2;i>=0;i--){
    while(!S.empty() and A[S.top()]>=A[i]) S.pop();
    if(S.empty()) nsri[i]=A.size();
    else
    nsri[i]=S.top();
    S.push(i);
}
long long int ans=0;
for(int i=0;i<A.size();i++){
    ans=max(ans,
            (long long int)A[i]* 
            (long long int)
            (nsri[i] -nsli[i] -1 ));
}
return (int)ans;
}
