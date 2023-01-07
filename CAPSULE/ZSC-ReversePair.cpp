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
int merge(int start,int mid,int end,vector<int> &A){
	int ANS=0; 
	int p1=start,p2=mid;
	vector<int> merged;
	/*cout<<endl<<"--start to mid-1----|";
	for(int i=start;i<mid;i++){ 
		cout<<A[i]<<" ";
	}
	cout<<endl<<"--mid to end----|";
	for(int i=mid;i<=end;i++){ 
		cout<<A[i]<<" ";
	}
	cout<<endl<<"---------------------|";*/

	while(p1<mid and p2<=end){
		long long int x = (long long int)A[p1];
		long long int y = (long long int)2*(long long int)A[p2];
		if(A[p1]<=A[p2]){
			for(int i=p2;i<=end;i++){
				y = (long long int)2*(long long int)A[i];
				if(x>y){
					ANS++;
				} else{
					break;
				}
			}
			merged.push_back(A[p1]);
			p1++;
		}else{
			for(int i=p1;i<mid;i++){
				x = (long long int)A[i];
				if(x>y){
					ANS+=(mid-i);
					break;
				}
			}

			merged.push_back(A[p2]);
			p2++;
		}
	}
	while(p1<mid){
		merged.push_back(A[p1]); 
		p1++;
	}
	while(p2<=end){
		merged.push_back(A[p2]);
		p2++;
	}
	int m=0;
	//cout<<endl;

	for(int i=start;i<=end;i++,m++){
		A[i]=merged[m];
	//	cout<<A[i]<<" ";
	}
	//cout<<endl;

	return ANS;
}
int mergeSort(int start,int end,vector<int> &A){
	int ans=0;
	if(start<end){
		int mid=(start+end)/2;
		ans+=mergeSort(start,mid,A);
		ans+=mergeSort(mid+1,end,A);
		ans+=merge(start,mid+1,end,A);
		return ans;
	}
	return ans;
}
int solve(vector<int> &A) {
	return mergeSort(0,A.size()-1,A);
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> A={14046, 57239, 78362, 99387, 27609, 55100, 65536, 62099, 40820, 33056, 88380, 78549, 57512, 33137, 81212, 32365, 42276, 65368, 52459, 74924, 25355, 76044, 78056, 45190, 94365, 58869, 20611 };
		//vector<int> A={1, 3, 2, 3, 1};//2
		vector<int> A={769, -71, 599, -1438, -530, -512, 1680, 1907, -301, 492, -844, 1765, -188, 685, -1879, -699, -990, 1022, 459, 528, -930, 1051, 1412, -1598, 245, -480, 1979, 1212, 1177, 447, -509, 881, 1968, -1603, -429, 1165, 405, 426, -1610, 931, -835, -1156, 1273, -143, -940, 199, -1886, -1646, 390, -1349, -256, -256, -103, -135, 637, -605, 55, -1805, -17, -229, 1162, 288, -818, -922, 32, -1032, -1823, -1874, -1650, 146, 721, 1586, 1969, 1720, -993, -1137, -1233, -1629, -879, -277, 444, -1191, -1273, 127, 1785, 1407, -1460, 414, -1578, -1348, 72, -794, 632, 877, 338, 1921, -650, -1314, 1187, -40};//2761
		int ans=solve(A);
		cout<<endl<<"ans="<<ans;
		// int a=-2*1e9;
		// long long int check = 2*(long long int)a;
		//cout<<check;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
