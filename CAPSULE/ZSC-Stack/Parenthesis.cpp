int Solution::solve(string A) {
    stack<char> S;
    map<char,char> m;
    m['}']='{';
    m[')']='(';
    m[']']='[';
    for(char x:A){
        if(x=='{' or x=='[' or x=='(')
            S.push(x);
        else if(S.size()>0 and S.top()==m[x])S.pop();    
              else return 0;  
    }
    return S.size()==0;
}
