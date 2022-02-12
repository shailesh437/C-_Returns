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
vector<int> factorial(int N){
        // code here 
        vector<int> ans;
        ans.push_back(1);
        int cp=0,carry=0,lp=0;
        for(int i=2;i<=N;i++){
        	cp=0;carry=0;
        	do{
        		int p=(ans[cp]*i)+carry;
        		ans[cp]=p%10;
        		carry=p/10;
        		cp++;
        	}while(cp<=lp);
        	while(carry){
        		ans.push_back(carry%10);
        		lp++;
        		carry /= 10;
        	}
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> ans = factorial(9);
		cout<<endl;
		for(int x: ans){
			cout<<x<<" ";
		}
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
