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

ll doMerging(ll arr[],ll start,ll mid,ll end){
	ll leftSize=mid-start+1;
	ll rightSize=end-mid;
	ll leftArr[leftSize+1];
	ll rightArr[rightSize+1];
	for(ll i=0;i<leftSize;i++){
		leftArr[i]=arr[start+i];
	}
	for(ll i=0;i<rightSize;i++){
		rightArr[i]=arr[mid+1+i];
	}
	ll i = 0;
	ll j = 0;
	ll ic=0;
	leftArr[leftSize]=1e18;
	rightArr[rightSize]=1e18;
	for(ll k=start;k<=end;k++){
		if(leftArr[i]<=rightArr[j]){
			arr[k]=leftArr[i];
			i++; 
		}else{
			arr[k]=rightArr[j];
			j++;
			ic += leftSize-i; 
		}	
	}
	return ic;
}
void mergeSorting(ll arr[],ll start,ll end,ll &ic){
	 if(start<end){
		ll mid = start+(end-start)/2;
		mergeSorting(arr,start,mid,ic);
		mergeSorting(arr,mid+1,end,ic);
		ic += doMerging(arr,start,mid,end);	
	} 
}
long long int inversionCount(long long int arr[], 
	long long int N)
{
	ll ic=0;
	mergeSorting(arr,0,N-1,ic);
	return ic;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		ll N;
		cin>>N;
		ll arr[N];
		for(ll i=0;i<N;i++)
			cin>>arr[i];
		ll ans = inversionCount(arr,N);	
		cout<<ans;	
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
