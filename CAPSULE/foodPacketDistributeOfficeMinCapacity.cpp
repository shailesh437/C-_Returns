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

int minCapacityMaximized(vector<int> &A,
						int officeRequired){
	long long int FULL_SUM=0;
     for(int x:A)  FULL_SUM+=x;
     if(FULL_SUM<B) return 0;
	 sort(A.begin(),A.end());
     if(officeRequired==A.size()) return A[0];
     if(officeRequired<A.size()){
         int diff = officeRequired-A.size();
         return A[diff-1];
     } 
     int lb=0;
     int ub=A[0]*2;//atleast this much office can provide
     int capacity_aka_mid=A[0];
     int POSSIBLE_ANS=capacity_aka_mid;
     //cout<<"lb="<<lb<<":ub="<<ub<<endl;
     while(lb<=ub ){ 
     	//cout<<"SOW:lb="<<lb<<":ub="<<ub<<endl;
     	int check=lb+(ub-lb)/2;
     	if(check==0) check=1;
     	//cout<<"INSIDE";
     	//assume that this is qty that every office 
     	//must provide 
     	//SO now check what is the office count that comes
     	int totOffcPossible=0;
     	//cout<<"check:"<<check<<endl;
     	bool valid=true;	
     	for(int i=0;i<A.size();i++){
     		if(A[i]/check == 0){
     			valid=false;
     			break;
     		}
     		totOffcPossible+=A[i]/check;
     	}
     	if(valid)
     	capacity_aka_mid=check;
     	//cout<<"totOffcPossible:"<<totOffcPossible<<"with capacity_aka_mid="<<capacity_aka_mid<<endl;
     	if(totOffcPossible==officeRequired) return capacity_aka_mid;
     	if(totOffcPossible<officeRequired) //decrease the qty still further 
     	{
     		ub=capacity_aka_mid-1;
     	}else{
     		POSSIBLE_ANS=capacity_aka_mid;
     		lb=capacity_aka_mid+1;
     	}	
     	
     	//cout<<"EOW:lb="<<lb<<":ub="<<ub<<":capacity_aka_mid="<<lb+(ub-lb)/2<<endl; 
     }
     if(capacity_aka_mid==0){
     	//check if  1 is possible
     	int SUM=0;
     	for(int i=0;i<A.size();i++){
     		SUM+=A[i];
     		if(SUM>=officeRequired)
     			return 1;
     	}
     }
     return POSSIBLE_ANS;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int cityCount;
		cin>>cityCount;
		vector<int> A;
		for(int i=0;i<cityCount;i++){
			int x;
			cin>>x;
			A.push_back(x);
		}
		int officeRequired;
		cin>>officeRequired;
		cout<<minCapacityMaximized(A,officeRequired);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
