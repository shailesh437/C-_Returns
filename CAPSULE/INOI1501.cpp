//CC 
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define ARR_SIZE 6
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


int getMaxSubArraySum(vector<int> &V){

	int ans = INT_MIN;
	int c_s=0;
	int c_e=0;
	int b_s=0;
	int b_e=0;
	int sumSoFar=V[c_s];

	for(;c_e<V.size();c_e++){
		if(V[c_e]+sumSoFar>V[c_e]){
			//current element is greater than sumSoFar
			sumSoFar+=V[c_e];

		}else{
			c_s=c_e;
			sumSoFar=V[c_e];
		}
		if(sumSoFar>ans){
			b_s=c_s;
			b_e=c_e;
			ans=sumSoFar;
		}
		if(c_e-c_s==V.size()/2){
			c_s++;
			sumSoFar-=V[c_s];
		}
	}
	cout<<"Bestansrange="<<b_s<<" ----- "<<b_e;
	return ans;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		
		int N;
		cin>>N;
		vector<long long int> A(ARR_SIZE,0);
		vector<long long int> B(ARR_SIZE,0);
		vector<long long int> Case1(ARR_SIZE,0);
		vector<long long int> Case2(ARR_SIZE,0);

		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			A[i]=a;
		}

		for(int i=0;i<N;i++){
			int b;
			cin>>b;
			B[i]=b;
		}
		logarr(A,0,A.size()-1);
		logarr(B,0,B.size()-1);
		Case1[0]=A[0];

		Case2[0]=B[0]-A[0];
		 
		for(int i=1;i<N;i++){
			Case1[i]=max(Case1[i-1]+B[i],A[i]);
			Case2[i]=min(Case2[i-1],-A[i])+B[i];
		}


		long long int ans=INT_MIN;
		for(int i=1;i<N;i++){
			ans=max(ans,Case1[i-1]+A[i]);
		}
		cout<<endl<<"1.ans = "<<ans<<endl;
		long long int Bsum=0;
		for(int i=0;i<B.size();i++){
			Bsum+=B[i];
		}
		for(int i=0;i<N-1;i++){
			ans=max(ans,Bsum-(Case2[i]-A[i+1]+B[i+1]));
		}
		cout<<ans;


		/*
		int N;
		vector<int> a,b;
		cin>>N;
		for(int i=0;i<N;i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		for(int i=0;i<N;i++){
			int x;
			cin>>x;
			b.push_back(x);
		}
		//logarr(a,0,a.size()-1);
		//logarr(b,0,b.size()-1);
		vector<int> dp(a.size()+1,0);
		vector<int> dp1(a.size()+1,0);
		dp[0]=a[0];
		dp1[0]=b[0]-a[0];
		int ans=INT_MIN;
		for(int i=1;i<N;i++){
			dp[i]=max(dp[i-1]+b[i],a[i]);
			ans=max(ans,dp[i-1]+a[i]);
		}
		cout<<"\nans = "<<ans; //i<j

		int sum = 0;
		for(int x:b) sum += x; 

		for(int i=1;i<N;i++){
			dp1[i]=min(dp[i-1],-a[i])+b[i];
			ans=max(ans,sum-(dp1[i]-a[i]+b[i]));
		}

		cout<<endl<<ans;
		*/
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
