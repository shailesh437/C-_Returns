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
 
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
   bool areIsomorphic(string str1, string str2)
    {
        
        
        // Your code here
        if(str1.length() != str2.length()) return 0;
       // unordered_map<char,int> m1,m2;
        int m1[256]={0},m2[256]={0}; 
        for(int i=0;i<str1.length();i++)
            m1[str1[i]] += (1+i);
        for(int i=0;i<str2.length();i++)
            m2[str2[i]] += (1+i);    
        //if(m1.size()!=m2.size()) return 0;
        for(int i=0;i<str1.length();i++){
            if(m1[str1[i]] != m2[str2[i]]){
            	cout<<"m1[str1[i]] = "<<m1[str1[i]]<<endl;
            	cout<<"m2[str2[i]] = "<<m2[str2[i]]<<endl;
            	cout<<"str1[i] = "<<str1[i]<<endl;
            	cout<<"str2[i] = "<<str2[i]<<endl;

            	cout<<"returning ZERO\n";
                return 0;
            }
        }
        return true;         
    }
};

int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	string s1,s2;
	while(TC--){
			cin>>s1;
			cin>>s2;
			Solution obj;
			cout<<obj.areIsomorphic(s1,s2)<<endl; 
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
