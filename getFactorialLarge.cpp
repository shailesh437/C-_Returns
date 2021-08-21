#include<bits/stdc++.h>
using namespace std;
vector<int> multiply(string s1,string s2){
	vector<int> ans;
	int carry=0;
	for(int i=s1.length()-1;i>=0;i--){
		int p = stoi(s2)*(s1[i]-'0')+carry;
		int ans_d = p%10;
		carry = p/10;
		ans.push_back(ans_d);		
	}
	if(carry){
		ans.push_back(carry);	
	}
	return ans;
}
string getFactorialLarge(int N){
	string ans="1";
	for(int i= 1;i<=N;i++){
		vector<int> v = multiply(ans,to_string(i));
		ans="";
		for(int i=v.size()-1;i>=0;i--){
			ans+=to_string(v[i]);
		}
	}
	return ans;
}
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		cout<<getFactorialLarge(N)<<endl;
	}
	return 0;
}
