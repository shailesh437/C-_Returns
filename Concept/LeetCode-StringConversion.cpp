#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/string-transforms-into-another-string 
bool checkIfCanBeTransformed(string s1,string s2){
	if(s1==s2){
		return true;
	}
	if(s1.length() != s2.length()){
		return false;
	}
	unordered_map<char,char> charMap;
	for(int i=0;i<s1.length();i++){
		if(charMap.find(s1[i])!=charMap.end() and s1[i]!=s2[i]){
			return false;
		}
		charMap[s1[i]]=s2[i];
	}

	return charMap.size()<26;
}

int main(){
	 string s1,s2;
   	 cin>>s1>>s2;
	 cout<<checkIfCanBeTransformed(s1,s2); 
	return 0;
}
