string Solution::solve(string A) {
    stack<char> S;
    S.push(A[0]);
    for(int i=1;i<A.length();i++){
        if(S.size()>0 and  A[i]==S.top())
            S.pop();
        else S.push(A[i]);    
    }
    vector<char> ansV;
    while(!S.empty()){
        ansV.push_back(S.top());
        S.pop();
    }
    reverse(ansV.begin(),ansV.end());
    string ans(ansV.begin(),ansV.end());    
    return ans;
}
