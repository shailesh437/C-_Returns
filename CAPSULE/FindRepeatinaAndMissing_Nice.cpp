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
bool check(int *arr, int n, int y){
	for(int i=0;i<n;i++){
		if(arr[i]==y)
			return true;
	}
	return false;
}
int *findTwoElement2(int *arr, int n) {
        // code here
	int *ans = new int[2];
	int min_val=INT_MAX;
	int max_val=INT_MIN;
	int sum_given=0;
	int sum_range=0;
	for(int i=0;i<n;i++){
		min_val = min(min_val,arr[i]);
		sum_given += arr[i]; 
	}	
	max_val = min_val + n -1;
	sum_range =  (max_val*(max_val+1))/2;	
	int xor1=min_val;	
	for(int j=min_val+1;j<=max_val;j++){
		xor1=xor1^j;
	}
	int xor2=arr[0];
	for(int i=1;i<n;i++){
		xor2=xor2^arr[i];
	}
	int xor3 = xor1  ^ xor2;

	vector<int> dig_given;
	vector<int> dig_range;
	bool one_present=true;
	int bit_pos=1;
	int bit_count=0;
	while(one_present){ 
		bit_count=0;
		for(int i=0;i<n;i++){
			if(arr[i]&bit_pos){
				bit_count++;
			}
		}
		bit_pos=bit_pos<<1;
		one_present = (bit_count>0)?1:0;
		dig_given.push_back(bit_count);
	}
	bit_pos=1;
	bit_count=0;
	one_present=true;
	while(one_present){ 
		bit_count=0;
		for(int i=min_val;i<=max_val;i++){
			if(i&bit_pos){
				bit_count++;
			}
		}
		bit_pos=bit_pos<<1;
		one_present = (bit_count>0)?1:0;
		dig_range.push_back(bit_count);
	} 
	int inter_ans=0;
	if(sum_range<sum_given){
		for(int i=0;i<dig_range.size();i++){
			if((dig_range[i] | dig_given[i]) == 0) continue;
			//cout<<dig_range[i]<<"-"<<dig_given[i]<<endl;
			
			int x = (dig_range[i]<dig_given[i])?1:0;
			inter_ans = (inter_ans<<1)|x;
			//cout<<x<<"-"<<endl;
			//inter_ans = (inter_ans<<1)|(dig_range[i]-dig_given[i]>0)?1:0;
		}
	}else{
		for(int i=dig_range.size()-1;i>=0;i--){
			if((dig_range[i] | dig_given[i]) == 0) continue;
			//cout<<dig_range[i]<<"-"<<dig_given[i]<<endl;
			
			int x = (dig_range[i]>dig_given[i])?1:0;
			inter_ans = (inter_ans<<1)|x;
			//cout<<x<<"-"<<endl;
			//inter_ans = (inter_ans<<1)|(dig_range[i]-dig_given[i]>0)?1:0;
		}	
	}

		//cout<<inter_ans<<endl; 
		//cout<<xor3<<endl; 
	int repeating = xor3 ^ inter_ans;
	int missing = repeating^xor3; 

	ans[0]=repeating;
	ans[1]=missing;
	return ans;
}



int *findTwoElement(int *arr, int n) {
        // code here
	int *ans = new int[2];
	int min_val=1;
	int max_val=n;  	
	int xor1=1;	//xor1- distinct range
	for(int j=2;j<=n;j++){
		xor1^=j;
	}
	int xor2=arr[0];
	for(int i=1;i<n;i++){
		xor2^=arr[i];
	}
	int xor3 = xor1  ^ xor2;

	int repeating ,missing; 
	vector<int> temp(n+1,-1);
	for(int i=0;i<n;i++){
		temp[arr[i]]=arr[i];
	}	

	for(int i=min_val;i<=max_val;i++){
		if(temp[i]==-1){
			missing = i;	
			break;
		}
	}	
	//cout<<xor3<<endl;	
	ans[0]=missing^xor3;
	ans[1]=missing;
	return ans;
}


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int *ans;
		int n;
		cin>>n;
		int *arrr;
		arrr=new int[n];
		for(int i=0;i<n;i++){
			cin>>arrr[i];
		}
		ans=findTwoElement(arrr,n);
		for(int i=0;i<2;i++){
			cout<<ans[i];
		}
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
