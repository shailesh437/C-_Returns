#include<iostream>
using namespace std;
int main () {
	int x,y;
	cin>>x>>y;
	int b=max(x,y);
	int a=min(x,y);
	int maxVal=0;
	for(int i=a;i<=b;i++){
		for(int j=i+1;j<=b;j++)
			maxVal=max(maxVal,i^j);
	}
	cout<<maxVal;
	return 0;
}
