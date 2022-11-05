#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int binaryToInt(string s){
    int ans=0;
    int pos=0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='1'){
            ans+=pow(2,pos);
        }
        pos++;
    }
    return ans;
}

string intToBinary(int X){
    string ans="";
    while(X){
        if(X&1)ans+="1";
        else ans+="0";
        X=X>>1;
    }
    int start=0;
    int end=ans.length()-1;
    while(start<end){
        swap(ans[start],ans[end]);
        start++;
        end--;
    }
    return ans;
}
string addBinary(string A, string B) {
    string s1=A.length()>=B.length()?A:B;
    string s2=B.length()<=A.length()?B:A;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    //cout<<"\n s1 = "<<s1<<endl;
    //cout<<s2<<endl;
    int carry=0;
    vector<char> ans;
    for(int i=0;i<s2.length();i++){
    	int dig=(s1[i]-'0')+(s2[i]-'0')+carry;
    	switch(dig){
    		case 0:
    		ans.push_back('0');
    		carry=0;
    		break;
    		case 1:
    		ans.push_back('1');
    		carry=0;
    		break;
    		case 2:
    		ans.push_back('0');
    		carry=1;
    		break;
    		case 3:
    		ans.push_back('1');
    		carry=1;
    		break; 
    	}
    }

    for(int i=s2.length();i<s1.length();i++){
    	int dig=s1[i]-'0'+carry;
    	switch(dig){
    		case 0:
    		ans.push_back('0');
    		carry=0;
    		break;
    		case 1:
    		ans.push_back('1');
    		carry=0;
    		break;
    		case 2:
    		ans.push_back('0');
    		carry=1;
    		break;
    		case 3:
    		ans.push_back('1');
    		carry=1;
    		break; 
    	}
    }
    if(carry) ans.push_back('1');
    string ANSstring(ans.begin(),ans.end());
    reverse(ANSstring.begin(),ANSstring.end());
    return ANSstring;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string A,B;
		cin>>A>>B;
		cout<<"\n=================\n";
		cout<<"Strings=["<<A<<"]:B=["<<B<<"]\n";
		string ANS = addBinary(A,B);
		cout<<endl<<"ANS="<<ANS;
	}

	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
