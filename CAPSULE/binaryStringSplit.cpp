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
int getCountOfSplitString(string str){
	stack<char> zeroOneStack;
	int ans=0;
	for(int i=0;i<str.length();i++){
		if(zeroOneStack.empty() or zeroOneStack.top()==str[i]){
			zeroOneStack.push(str[i]);
		}else{
			int startcount=i;
			while(i<str.length()-1 and str[i]==str[i+1]){
				i++;
			}
			if(i-startcount+1 >= zeroOneStack.size()){
				ans++;
			}
			i=startcount-1+zeroOneStack.size();
			while(!zeroOneStack.empty()) zeroOneStack.pop();
			
		}
	}
	if(ans==0) return -1;
	return ans;

}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string str="0000000000";
		cout<<getCountOfSplitString(str);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
