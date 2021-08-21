#include<bits/stdc++.h>
using namespace std;
int main(){
    int TC;
    cin>>TC;
    while(TC--){
        string N;
        cin>>N;
        reverse(N.begin(),N.end());
        int i=0;
        while(N[i]=='0'){
            i++;
        }
        for(;i<N.length();i++){
            cout<<N[i];
        }
        cout<<endl;
    }
    return 0;
}
