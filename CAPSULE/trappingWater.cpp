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

long long trappingWater(int arr[], int n){
   // code here
	int i=0;
	while(arr[i]<=0) i++;
	pair<int,int> left;
	pair<int,int> right;
	left.first=i;
	left.second=arr[i];

	right.first=left.first+1;
	right.second=arr[left.first+1];
	
	int remaining=n-2;
	long long collection=0;
	while(remaining>0){
		for(int i=left.first+1;i<n;i++){
			if(right.second<arr[i]){
				right.second = arr[i];
				right.first = i;
			} 
			if(right.second>left.second){
				break;
			}
		}
		/*cout<<endl<<"left= "<<left.first<<"::right = "<<right.first<<endl; 
		cout<<endl<<"left.sec= "<<left.second<<"::right = "<<right.second<<endl; 
		cout<<endl<<min(left.second,right.second)<<endl;
*/
		for(int i=left.first+1;i<right.first;i++){
			collection += 
			(min(left.second,right.second)- arr[i]);
		}

   	remaining=n-right.first-2;//n-1-right-1
   	if(remaining>0){   	
   		left.first=right.first;
   		left.second=right.second;
   		right.second=INT_MIN;	
   	}
   }
   return collection;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
  	//cin>>TC;
	while(TC--){
		//int arr[] = {3,0,0,2,0,4}; //
		//int N = 6;
		int arr[] = {7,4,1,9}; //
		int N = 4;
		cout<<trappingWater(arr,N);	
	}
  	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
      #endif 
	return 0;
}
