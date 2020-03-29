#include<iostream>
using namespace std;
int main () {
	int x,y;
	cin>>x>>y;
	int x_xor_y = x^y;
	int msb=0;
	while(x_xor_y){
        x_xor_y=x_xor_y>>1;
        msb++;
	}
	int ans = (1<<(msb))-1;
	cout<<ans;
	return 0;
}

