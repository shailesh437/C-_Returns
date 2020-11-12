#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1;
	cin>>s1;
	string::iterator it=s1.begin();
	char prev=*it;
	++it;
	cout<<prev;
	for(; it!=s1.end();++it){
		char next=*it;
		cout<<next-prev<<next;
		prev=next;
	}
	return 0;
}
