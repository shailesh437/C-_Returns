#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC;
    cin>>TC;
    while(TC--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>=b && a>=c){
            cout<<max(b,c);
        }else if(b>=a && b>=c){
            cout<<max(a,c);
        }else if(c>=a && c>=b){
            cout<<max(a,b);
        }
        cout<<endl;
    }
	return 0;
}
