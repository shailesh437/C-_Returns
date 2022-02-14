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

bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here 
    map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[A[i]]++;
    }
    for(int i=0;i<n-2;i++){
        int X_2 = X-A[i];
        for(int j=i+1;j<n-1;j++){
            int X_1=X_2-A[j];
            if(mp[X_1]){
                return true;
            }
        }
    }
    return false;
    }
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int n = 6, X = 13;
		int arr[] = {1 ,4 ,45 ,6 ,10 ,8};
		if(find3Numbers(arr, n, X)){
			cout<<"1";
		}else{
			cout<<"0";
		}			
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
