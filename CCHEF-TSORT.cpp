#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int N;
	list<int> l;
	for(int i=0;i<t;i++){
		cin>>N;
		l.push_back(N);
	}
	l.sort();
	for(int x:l){
		cout<<x<<endl;
	}
	return 0;
}
