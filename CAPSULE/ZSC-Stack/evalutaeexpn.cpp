
int Solution::evalRPN(vector<string> &A) { 
    if(A.size()==1) return stoi(A[0]);
stack<int> operandStack;
int result;
for(int i=0;i<A.size();i++){
 if(A[i]!="+" and A[i]!="-" and A[i]!="*" and A[i]!="/"){
     operandStack.push(stoi(A[i]));
 }else{
     int y = operandStack.top();
     operandStack.pop();
     int x = operandStack.top();
     operandStack.pop();
     if(A[i]=="+"){
         result=x+y;
     }else if(A[i]=="-"){
         result=x-y;
     }else if(A[i]=="*"){
         result=x*y;
     }else if(A[i]=="/"){
         result=x/y;
     }
     operandStack.push(result);
 }
}
return result;
}

