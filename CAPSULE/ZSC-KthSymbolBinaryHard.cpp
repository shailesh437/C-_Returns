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
int solve1(int A,long B){
	if(A==1) return 0;
	if(A>64){
		return solve1(A-1,B);
	}
	long centerOfMirror =   (1<<(A-1))/2;
	if(centerOfMirror<=B){
		if(A%2==0)
		return !solve1(A/2,B-centerOfMirror);
		else
		return !solve1(A-1,B-centerOfMirror);	
	}

	return (A%2==0)?solve1(A/2,B):solve1(A-1,B);
	//return solve1(A-1,B);
}
int solve(int A,long B){
	int a = log2(B)+1;
	if(A>a){
		return !solve(A-1,B); 
	}
	return solve1(A,B);
}

int  solve3(int A, long B) {
if(A==1) return 0;
	if(A>64) return solve3(64,B);
	int centerOfMirror = pow(2,A-1)/2;
	if(centerOfMirror<=B){
		return !solve3(A-1,B-centerOfMirror);
	}
	return solve3(A-1,B);
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		/*cout<<solve3(6,20);
		cout<<solve3(6,21);
		cout<<solve3(6,22);
		cout<<solve3(6,23);
		*/
		cout<<solve3(277,887);
		/*
		cout<<solve3(649,690);
		cout<<solve3(649,691);
		cout<<solve3(649,692);
		cout<<solve3(649,693);
		cout<<solve3(649,694);
		cout<<solve3(649,695);
		*/
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
