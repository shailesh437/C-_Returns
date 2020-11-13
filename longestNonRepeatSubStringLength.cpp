#include<iostream>
#include<cstring>
#include<map>
using namespace std;


int lengthOfLongestSubstring(string s) {
	int occuredSet[256]={0};
	int longestLength=0;
	int localLength=0;
	int curr_pointer=1;
	int start_ptr=0;
	for(int i=0;i<s.length();i++,curr_pointer++){
		if(occuredSet[(int)s[i]] == 0){
			localLength++;
		}else{
			longestLength=max(longestLength,localLength);
			if(start_ptr>occuredSet[(int)s[i]]){
				localLength =  curr_pointer - start_ptr;	
			}else{
				localLength =  curr_pointer -  occuredSet[(int)s[i]];	
			}
			start_ptr = curr_pointer-localLength;
		}
		occuredSet[(int)s[i]] = curr_pointer;
	}
	return max(longestLength,localLength);
}

int main(){
	string S;
	cin>>S;
	int ans = 	lengthOfLongestSubstring(S);
	cout<<endl<<"ANS = "<<ans;
	return 0;
}
