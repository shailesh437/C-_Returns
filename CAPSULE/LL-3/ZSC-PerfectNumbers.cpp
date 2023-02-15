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
string solve(int A) {
	if(A==1) return "11";
	if(A==2) return "22";
	queue<string> Q1;
	queue<string> Q2;
	Q1.push("11");
	Q1.push("22");
	int count=2;
	while(count<A){
		int q1Size=Q1.size();
		for(int i=0;i<q1Size;i++){
			Q1.push("1"+Q1.front()+"1");
			count++;
			if(count==A) return Q1.back();
			Q2.push(Q1.front());
			Q1.pop();
		}
		while(!Q2.empty()){
			Q1.push("2"+Q2.front()+"2");
			count++;
			if(count==A) return Q1.back();
			Q2.pop();
		}	
	}
	 
	return "";
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//for(int i=1;i<=100000;i++)
			cout<<endl<<solve(100000);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
