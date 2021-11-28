/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
vector<bool> getBinary(int x){
    vector<bool> ans;
    while(x){
        bool dig=x&1;
        //cout<<dig;
        ans.push_back(dig);
        x=x>>1;
    }
    for(int i=ans.size();i>=0;i--){
        cout<<ans[i];
    }
    return ans;
}

vector<bool> getReverseBinary(vector<bool> ans){
    vector<bool> ansRev;
    for(int i=ans.size()-1;i>=0;i--){
        bool dig=ans[i];
        ansRev.push_back(dig);
    }
    for(int i=0;i<ansRev.size();i++){
        bool dig=ans[i];
        cout<<dig;
    }
    return ansRev;
}

int getDecimal(vector<bool> ans){
    int dec=0;
    for(int i=0;i<ans.size();i++){
            dec+=ans[i]<<i;
    }
    return dec;
}

int main()
{
    int x;
    cin>>x;
    cout<<"\n Number in Decimal :"<<x;
    cout<<"\n Number in Binary :";
    vector<bool> ans = getBinary(x);    
    cout<<"\n Number in Binary Reverse:";
    ans = getReverseBinary(ans);
    cout<<"\n Number in Decimal :"<<getDecimal(ans);
    return 0;
}
