#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	cout<<endl;for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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
int solve(string A1, string B) {
    string A = B+"$"+A1;
    cout<<endl<<A;
    vector<int> Z_arr(A.size());
    int L=0;
    int R=0;
    int j=0,k=0;
    Z_arr[0]=A.length();
    for(int i=1;i<A.length();i++){
        //i not in segment
        if(i<L or i>R){
            k=0;
            j=i;
            while(j<A.length() and k<=B.length() and A[j]==A[k]){
                j++;
                k++;
            }
            Z_arr[i]=k;
            L=i;
            R=j-1;
        }else{
            if(Z_arr[i-L] < R-i+1){
                Z_arr[i]=Z_arr[i-L];
            }else{
                j=R+1;
                k=R-i+1;
                while(j<A.length() and k<=B.length() and A[j]==A[k]){
                    j++;
                    k++;
                }   
                Z_arr[i]=Z_arr[i-L]+(j-R-1);
                L=i;
                R=j-1;
            }
        }
    }
    int ans=0;
    logarr(Z_arr,0,Z_arr.size()-1);
    for(int i=B.length();i<A.length();i++){
        if(Z_arr[i]==B.length()){
            ans++;
        }
    }
    return ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string A = "ccccba";
		string B = "cc";
		int ans = solve(A,B);
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
