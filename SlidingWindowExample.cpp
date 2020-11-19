#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int calculateMaxLengthSubStringByReplacingOneChar(string s,int k){
	if(k>=s.length()){
		return s.length();
	}
	int cnt_a=0;
	int cnt_b=0;
	int start_window=0;
	int end_window=0;
	int max_freq=0;
	int max_length=0;
	for(;end_window<s.length();end_window++){
		if(s[end_window]=='a'){
			cnt_a++;
		}
		if(s[end_window]=='b'){
			cnt_b++;
		}
		max_freq=max(max_freq,cnt_a);
		max_freq=max(max_freq,cnt_b);
		if(end_window-start_window+1-max_freq>k){
			if(s[start_window]=='a'){
				cnt_a--;
			}
			else if(s[start_window]=='b'){
				cnt_b--;
			}
			start_window++;
		}
		max_length=max(max_length,end_window-start_window+1);
	}
	return max_length;

}

int main(){
	int k;
	cin>>k;
	string s;
	cin>>s;
	cout<<calculateMaxLengthSubStringByReplacingOneChar(s,k);
	return 0;
}
