// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int getCountOfDiffChar(string s1,string s2){
    int ans=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    return ans;
}
int minFlips (string S)
{
    // your code here
    string op1 = "";
    for(int i=0;i<S.length();i++){
        op1+= (i & 1)?'0':'1';
    }
    int c1 = getCountOfDiffChar(op1,S);
    op1="";
    for(int i=0;i<S.length();i++){
        op1+= (i & 1)?'1':'0';
    }
    int c2 = getCountOfDiffChar(op1,S);
    return min(c1,c2);
}
