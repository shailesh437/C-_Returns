#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


string solve(string A) {
    stack<char> operatorStack;
    vector<char> ansV;
    map<char,int> operatorPrecedence;
    operatorPrecedence['^']=3;
    operatorPrecedence['*']=2;
    operatorPrecedence['/']=2;
    operatorPrecedence['-']=1;
    operatorPrecedence['+']=1;
    for(int i=0;i<A.length();i++){
        if(A[i]<='z' and A[i]>='a'  ){
            ansV.push_back(A[i]);
        }else{
            if(operatorStack.empty()){
                operatorStack.push(A[i]);
            }else{
                if(A[i]=='('){
                    operatorStack.push(A[i]);
                }else if(A[i]==')'){
                    while(operatorStack.top()!='('){
                        ansV.push_back(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                } else if(operatorPrecedence[A[i]] <= 
                 operatorPrecedence[operatorStack.top()]){
                    while(!operatorStack.empty() and operatorPrecedence[A[i]] <= 
                     operatorPrecedence[operatorStack.top()]){
                    ansV.push_back(operatorStack.top());
                operatorStack.pop();
                if(!operatorStack.empty() and 
                    operatorPrecedence[A[i]] == 
                    operatorPrecedence[operatorStack.top()]){
                    ansV.push_back(operatorStack.top());
                operatorStack.pop();
            }
        }

        operatorStack.push(A[i]);  
    }else{
       operatorStack.push(A[i]);   
   }
}
}
}
while(!operatorStack.empty()){
    ansV.push_back(operatorStack.top());
    operatorStack.pop();
}
string ANS(ansV.begin(),ansV.end());
return ANS;
}



int main(){
    clock_t begin = clock();
    file_i_o();
    int TC=1;
	//cin>>TC;
    while(TC--){
		//string A = "q+(c*t)*o+(g*g)+q*(i-a)*p-(i*l)";
        string A = "p*(s*b^c)/q-(r-g-d)/b^(a-j)-a*(w/z)";
        string ans = solve(A);
        cout<<endl<<ans;
    }
	 #ifndef ONLINE_JUDGE 
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
