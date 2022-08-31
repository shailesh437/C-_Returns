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
 
vector<int> solve(int A, int B, vector<int> &C) {
	vector<int> capacity(A,0);
	vector<int> ANS;
	for(int i=0;i<C.size();i++){
		int available = upper_bound(capacity.begin(),capacity.end(),C[i]) 
		- capacity.begin()-1;
		if(available>0){
			capacity.erase(capacity.begin());
			capacity.push_back(C[i]+B);
		}else{
			available=0;
		}
		ANS.push_back(available);                
	}
	return ANS;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A, B, csize;
		cin>>A>>B>>csize;
		vector<int> C;
		for(int i=0;i<csize;i++){
			int data;
			cin>>data;
			C.push_back(data);
		}
		vector<int> ANS;
		ANS=solve(A,B,C);
		cout<<endl<<"----------------\n";
		for(int i=0;i<A;i++) cout<<ANS[i]<<" ";
	}
	 #ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
