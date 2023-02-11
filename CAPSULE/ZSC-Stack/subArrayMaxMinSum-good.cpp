int Solution::solve(vector<int> &A) {
    vector<int> nsl(A.size(),-1);
    vector<int> nsr(A.size(),-1);
    stack<int> S;
    S.push(0);
    nsl[0]=-1;
    for(int i=1;i<A.size();i++){
        while(!S.empty() and A[S.top()]<=A[i]) S.pop();
        if(S.empty()) nsl[i]=-1;
        else nsl[i]=S.top();
        S.push(i);
    }
    while(!S.empty()) S.pop();
    S.push(A.size()-1);
    nsr[A.size()-1]=A.size();
    for(int i=A.size()-2;i>=0;i--){
        while(!S.empty() and A[S.top()]<=A[i]) S.pop();
        if(S.empty()) nsr[i]=A.size();
        else nsr[i]=S.top();
        S.push(i);
    }

    long long int maxElemContribution=0;
    long long int MOD=1000000007;
    for(int i=0;i<A.size();i++){
        maxElemContribution+=
        ((long long int)A[i]%MOD)*
        (long long int)(i-nsl[i]) *
        (long long int)(nsr[i]-i);
        maxElemContribution%=MOD;
    }
    while(!S.empty()) S.pop();

    vector<int> ngl(A.size(),-1);
    vector<int> ngr(A.size(),-1);
    
    S.push(0);
    ngl[0]=-1;
    for(int i=1;i<A.size();i++){
        while(!S.empty() and A[S.top()]>=A[i]) S.pop();
        if(S.empty()) ngl[i]=-1;
        else ngl[i]=S.top();
        S.push(i);
    }
    while(!S.empty()) S.pop();
    S.push(A.size()-1);
    ngr[A.size()-1]=A.size();
    for(int i=A.size()-2;i>=0;i--){
        while(!S.empty() and A[S.top()]>=A[i]) S.pop();
        if(S.empty()) ngr[i]=A.size();
        else ngr[i]=S.top();
        S.push(i);
    }

    long long int minElemContribution=0; 
    for(int i=0;i<A.size();i++){
        minElemContribution+=
        ((long long int)A[i]%MOD)*
        (long long int)(i-ngl[i]) *
        (long long int)(ngr[i]-i);
        minElemContribution%=MOD;
    }
    long long int ans = (maxElemContribution%MOD-minElemContribution%MOD)%MOD;
    if(ans<0) ans+=MOD;
    return (int)ans;

}
