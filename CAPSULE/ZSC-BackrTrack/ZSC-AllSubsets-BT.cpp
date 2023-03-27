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
void printAllSubsets(vector<int> A,
	int a_index,
	vector<int> &B,
	int b_index,
	vector<vector<int>> &ANS){
	if(a_index>=A.size()){
		//logarr(B,0,b_index);
		vector<int> C;
		C.clear();
		for(int i=0;i<=b_index;i++)
			C.push_back(B[i]);
		sort(C.begin(),C.end());
		vector<int> vc(C.begin(), C.end());
		ANS.push_back(vc);
		return;
	}
	B.push_back(A[a_index]);
	b_index++;
	printAllSubsets(A,a_index+1,B,b_index,ANS);
	b_index--;
	B.pop_back();
	printAllSubsets(A,a_index+1,B,b_index,ANS);
		//cout<<ANS.size();
	

}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A={1,-4,2,-3};
		vector<int> B;
		vector<vector<int>> ANS;
		printAllSubsets(A,0,B,-1,ANS);
		cout<<ANS.size();
		cout<<endl;
		sort(ANS.begin(),ANS.end());
		for(int i=0;i<ANS.size();i++){
			if(ANS[i].size()>0)
				logarr(ANS[i],0,ANS[i].size()-1);
			cout<<endl;		
		}
		
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
