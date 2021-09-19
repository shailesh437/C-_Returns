#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N1,N2;
	cin>>N1>>N2;
	int ans=(N1>N2)?(N1-N2):(N1+N2);
	cout<<ans;
	return 0;
}
