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
int solve(vector<int> &A, int B) {
	vector<int> LTR_sum(A.size());
	vector<int> RTL_sum(A.size());
	LTR_sum[0]=A[0];
	for(int i=1;i<A.size();i++){
		LTR_sum[i]=LTR_sum[i-1]+A[i];
	}
	RTL_sum[0]=A[A.size()-1];
	for(int i=A.size()-2,j=1;i>=0;i--,j++){
		RTL_sum[j]=RTL_sum[j-1]+A[i];
	} 
	//1st B count SUM
	int lastIndex=A.size()-1;
	int frontPtr=0;
	int backPtr=A.size()-1;
	int ANS=-1e9;
	for(int c=1;c<B;c++){
		cout<<endl<<"c=["<<c<<"]:LTR_sum[c-1]+RTL_sum[B-c]:"<<LTR_sum[c-1]+RTL_sum[B-c-1];
		ANS=max(ANS,LTR_sum[c-1]+RTL_sum[B-c-1]);
	}
	cout<<endl<<"---------["<<ANS;
	ANS=max(ANS,LTR_sum[B-1]);
	cout<<endl<<"----LTR-----["<<LTR_sum[B-1];
	ANS=max(ANS,RTL_sum[B-1]);
	cout<<endl<<"----RTL-----["<<RTL_sum[B-1];
	return ANS;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int N,B;
		cin>>N>>B;
		vector<int> V;
		for(int i=0;i<N;i++){
			int x;
			cin>>x;
			V.push_back(x);
		}
		int ANS = solve(V,B);
		cout<<endl<<"------ANS = ["<<ANS<<"]";
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
