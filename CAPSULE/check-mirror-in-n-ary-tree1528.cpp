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


int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
	unordered_map<int,stack<int>> m;
	for(int i=0;i<2*e;i+=2){
		//cout<<endl<<"For "<<A[i]<<": pushing "<<A[i+1];
		m[A[i]].push(A[i+1]);
	}  
	for(int i=0;i<2*e;i+=2){
		if(m.count(B[i])==0) {
			cout<<"\n----44---";
			return 0;
		}
    		//cout<<endl<<"comparing for "<<B[i+1];
		if(m[B[i]].top()==B[i+1]){
			m[B[i]].pop();
    			//cout<<endl<<"Size for "<<A[i]<<":"<<m[A[i]].size();
		} else
		return 0;
	} 
	cout<<"\n====================\n";
	for(auto it=m.begin();it!=m.end();it++){
		if(!it->second.empty()) return 0;
	} 
	return 1;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
/*		int n=3,e=2;
		int A[4] = {1, 2, 1, 3};
		int B[4] = {1, 3, 1, 2};
*/
		//int n=8,e=7;
		//int A[] = {1,2,2,3,3,4,3,7,3,8,4,5,5,6};
	//	int B[] = {1,2,2,3,3,8,3,7,3,4,4,5,5,6};

		int n=12,e=11;
		int A[]={1 ,2 ,1 ,3 ,1 ,4 ,4,7, 4, 8, 4, 9, 3, 6, 2, 5, 6, 10, 6, 11, 6, 12};
		int B[]={1 ,4 ,1 ,3 ,1 ,2 ,4 ,9 ,4 ,8 ,4 ,7 ,3 ,6 ,6 ,12, 6, 11 ,6 ,10 ,2 ,5};

		cout<<checkMirrorTree(n,e,A,B);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
