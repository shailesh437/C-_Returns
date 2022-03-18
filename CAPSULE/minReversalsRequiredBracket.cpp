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
int countRev(string s){
	if (s.length() & 1)
		return -1;
	int ans=0;
	if(s[0]=='}'){
		s[0]='{';
		ans=1;
	}
	if(s[s.length()-1]=='{'){
		ans+=1;
		s[s.length()-1]='}';
	}	
	stack<char> stack;
	for(int i=0;i<s.length();i++){
		if(s[i]=='}'){
			if(stack.empty()){
				stack.push('{');
				ans++;
			}else{
				if(stack.top()=='{')
					stack.pop();
			}
		}else{
			stack.push(s[i]);
		}
	}
	ans += stack.size()/2;
	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//cout<<countRev("}{{}}{{{");
		//cout<<countRev("{{}{{{}{{}}{{");
		cout<<countRev("}}}}}}{}{}}}{{}}}}{}}{{{}{}{}{}}{{{{}}}{}}");
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
