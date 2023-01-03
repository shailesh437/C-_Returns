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
bool validParenthesis(string X){
	stack<char> S; 
	for(int i=0;i<X.length();i++){
		if(X[i]=='('){
			S.push(X[i]);
		}else{
			if(S.empty())
				return false;
			S.pop();
		}
	}
	return S.size()==0?true:false;
}
void generateParenthesis( int nO,
						  int nC,
						  string result,
						  vector<string> &results){
	if(!nO and !nC){
		results.push_back(result);
		return;
	}
	if(nO)
	generateParenthesis(nO-1,nC,result+"(",results);
	if(nC>nO)
	generateParenthesis(nO,nC-1,result+")",results);

}
vector<string> generateParenthesis(int A) {
	vector<string> ANS;
	generateParenthesis(A,A,"",ANS); 
	return ANS;    
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<string> ANS = generateParenthesis(5);
		cout<<endl<<"size of ANS = "<<ANS.size();
		for(string x:ANS){			 
				cout<<endl<<"::::"<<x;
		}
		 //cout<<validParenthesis("((()()))");

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
