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

vector<int> maxone(vector<int> &A, int B) {
	int b_count=B;
	cout<<endl<<"b_count="<<b_count;
	int a_start=0,a_end=0;
	int maxLen=INT_MIN;
	int ans_start=0;
	int ans_end=0;
	int b_first_index=-1; 
	while(a_end<A.size() and a_start<A.size()){
		while(A[a_end]==1 and a_end<A.size() and a_start<A.size()){
			a_end++;
			cout<<endl<<" while :a_start="<<a_start<<":a_end="<<a_end<<endl;
		}
		if(b_first_index==-1 and a_end<A.size()){
			b_first_index=a_end;
			cout<<"\n1.b_first_index="<<b_first_index<<endl;
		}
		if(b_count>0){
			b_count--;
			a_end++;
		}else{
			if(a_end-a_start>maxLen){
				maxLen=a_end-a_start;
				ans_start=a_start;
				ans_end=a_end;
				cout<<endl<<"2.. a_end="<<a_end<<endl;
			}
			if(a_end<A.size() and a_start<A.size() and b_first_index>-1){
				a_start=b_first_index+1;
				a_end=a_start;	
				b_first_index=-1;	
			}
			b_count=B;
		}

	}
	cout<<"\n3.. a_end="<<a_end<<":a_start="<<a_start<<":b_count="<<b_count<<endl;
	if(a_end>=A.size()){
		a_end=A.size();
	}
	cout<<"\n3.1. maxLen="<<maxLen<<endl;

	if(a_end-a_start>maxLen){
		maxLen=a_end-a_start+1;
		ans_start=a_start;
		ans_end= a_end;
	}
	vector<int> ans;
	for(int i=ans_start;i<ans_end;i++){
		ans.push_back(i);
	}
	return ans;
}


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
		int B = 2;
		A={1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
		B=1;
		A={1, 0, 0, 0, 1, 0, 1};
		B=2;
		//A={1,1,0};
		//B=2;
		vector<int> ans = maxone(A,B);
		logarr(ans,0,ans.size()-1);

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
