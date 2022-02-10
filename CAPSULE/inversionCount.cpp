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

int doMerge(int arr[],int start, int mid, int end){
int n1 = mid-start+1;
int n2 = end-mid;
int Left[n1+1];
int Right[n2+1];
int l_ic=0;
for(int i=0;i<n1;i++){
	Left[i]=arr[start+i];
}
for(int i=0;i<n2;i++){
	Right[i]=arr[mid+i+1];
}  
Left[n1] = 1e18;
Right[n2]= 1e18; 
int i=0,j=0; 
for(int k=start;k<=end;k++){ 
	if(Left[i] <= Right[j]){
		arr[k]=Left[i];
		i++; 
	}else{
		arr[k]=Right[j];
		j++; 
		l_ic+=(n1-i);
	}
	
}
logarr(arr,start,end);
return l_ic;
}
void doMergeSort(int arr[],int start, int end, int &ic){
	//int l_ic;
	if(start < end){
		int mid = (start+end)/2;
		doMergeSort(arr,start,mid,ic);
		doMergeSort(arr,mid+1,end,ic);
		ic += doMerge(arr,start,mid,end);
	}
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
			/*int arr[]={1024,9,8,7,6,5,4,41};
			int N=7;*/
			
			/*int arr[]={47,4,3,2,1,2,12,120};
			int N=7;
			*/
			int arr[]={5,4,3,2,1};
			int N=4;
			int ic=0;
			doMergeSort(arr,0,N,ic);
			cout<<"ANS=====\n";
			logarr(arr,0,N);
			cout<<endl<<ic<<" "<<"|";
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
