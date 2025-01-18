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

  int countSubstrings(string s) {
    int count=0;
  	for(int i=0;i<s.length();i++){
  		//for odd-lenght()

  		 int l=i;
  		 int r=i;
  		 while(l>=0 and r<s.length() and s[l]==s[r]){
  		 	count++;
  		 	l--;
  		 	r++;
  		 }

  		 //for even-legnth()
  		 l=i;
  		 r=i+1;
		 while(l>=0 and r<s.length() and s[l]==s[r]){
  		 	count++;
  		 	l--;
  		 	r++;
  		 }  		 

  	}
  	return count;
   }

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string s = "aaa";
		int ans = countSubstrings(s);
		cout<<endl<<"ans = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
