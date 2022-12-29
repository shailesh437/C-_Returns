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
int solve(int A) {
    int ans=0;
    int base=1;
    ans+=A/10;
    ans+=(A%10>0)?1:0;
    int A_copy=A/10;
    while(A_copy){
        base*=10;
        int current=(A/base)%10;
        int L =A/(base*10); 
        int R =A%base;  
        //cout<<endl<<"current="<<current<<":L:"<<L<<":R:"<<R<<endl;
        switch(current){
            case 0:
                  ans+=(L*base);
                  break;  
            case 1:
                  ans+=(L*base)+R+1;
                  break;   
            default:
                  ans+=((L+1)*base);
                  break; 
        } 
        A_copy/=10;
    }
    return ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		cout<<solve(920);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
