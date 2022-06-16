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

bool findPair(int arr[], int size, int n){
    //code
    vector<int> range(100004,-1);
    if(n==0){ //some number has to come 2wice
    	for(int i=0;i<size;i++){
    		if(range[arr[i]]!=-1){
    			return 1;
    		}
        	range[arr[i]] = arr[i];
    	}	
    	return 0;
    }
   
    for(int i=0;i<size;i++){
        range[arr[i]] = arr[i];
    }
 return 1;
    for(int i=0;i<size;i++){
        if(range[abs(n-arr[i])] !=-1){
        	cout<<endl<<arr[i]<<endl;
            return 1;
        } 
    }
    return 0;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
			int size,n;
			cin>>size>>n;
			int arr[size];
			for(int i=0;i<size;i++)
				cin>>arr[i];
			if(findPair(arr,size,n))
				cout<<1<<endl;
			else
				cout<<"-1"<<endl;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}		
