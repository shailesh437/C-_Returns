#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
int main(){
	string s;
	cin>>s;
	//int *arr = new int[26];
	int arr[26]={0};
	int max= INT_MIN;
	int char_;
	for(string::iterator it = s.begin();it!=s.end();++it){
		char x = *it;
		int index= tolower(x)-97;
		arr[index]+=1;
		if(arr[index]>max){
			max=arr[index];
			char_=index;
		}

	}
	char ans = 97+char_;
	cout<<ans;
}
