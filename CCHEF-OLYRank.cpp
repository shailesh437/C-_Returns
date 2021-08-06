#include<iostream>
using namespace std;
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		if((a+b+c) > (d + e + f))
			cout<<"1\n";
		else
			cout<<"2\n";
	}
	return 0;
}
