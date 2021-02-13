#include<iostream>
using namespace std;
int subArrayMaxSum(int a[],int asize){
	int dp[100]={0};
	dp[0]=a[0]<0?0:a[0];
	int max_so_far = dp[0];
	for(int i=1;i<asize;i++){
		dp[i]=dp[i-1]+a[i];
		if(a[i]<0){
			dp[i]=0;
		}
		max_so_far = max(max_so_far,dp[i]);
	}
	return max_so_far;
}

int subArrayMaxSum_2(int a[],int asize){
	//int dp[100]={0};
	int prev_sum,curr_sum;
	prev_sum=a[0]<0?0:a[0];
	int max_so_far = prev_sum;
	for(int i=1;i<asize;i++){
		curr_sum=prev_sum+a[i];
		if(a[i]<0){
			curr_sum=0;
		}
		max_so_far = max(max_so_far,curr_sum);
		prev_sum=curr_sum;
	}
	return max_so_far;
}

int main(){
	int a[]={7,8,-2,10,20};
	cout<<"Max sum of subarray = "<<subArrayMaxSum(a,sizeof(a)/sizeof(int));
	cout<<"\nMax sum of subarray = "<<subArrayMaxSum_2(a,sizeof(a)/sizeof(int));
	return 0;
}
