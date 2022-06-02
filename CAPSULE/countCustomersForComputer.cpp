
/*https://www.codingninjas.com/codestudio/problems/count-customers-who-did-not-get-a-computer_1115775?leftPanelTab=0*/

#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define MAX_PERSONS 100005
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
}/*
int runCustomerSimulation(int n,string SEQ){
	map<char,int> m;
	map<char,int> me;

	for(int i=0;i<SEQ.length();i++){
		if(m.size()==n ){
			if(m[SEQ[i]]==0)
				me[SEQ[i]]++; 
			m.erase(SEQ[i]);
		}else if(m[SEQ[i]]==1)
			m.erase(SEQ[i]);
		else
			m[SEQ[i]]=1;		
	}
	return me.size();
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		int n;
		string SEQ;
		cin>>n>>SEQ;
		cout<<runCustomerSimulation(n,SEQ);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}*/

	int runCustomerSimulation_CDGNJA(	vector<int> &SEQ,  
		int K){
	//cout<<"\n K = "<<K<<"|"<<SEQ.size()<<endl;

		if(SEQ.size()/2 <= K) {
		//cout<<"\n RETURNING ---0";
			return 0;
		}
		map<int,int> m;
		map<int,int> me;

		for(int i=0;i<SEQ.size();i++){
		//cout<<".dd.";	
		//cout<<m.size()<<"--"<<me.size()<<"-"<<SEQ[i]<<endl;
			if(m.size()==K ){
				if(m[SEQ[i]]==0)
					me[SEQ[i]]++; 
				m.erase(SEQ[i]);
			//cout<<".a.";
			}else if(m[SEQ[i]]==1){
				m.erase(SEQ[i]);
			//cout<<".b.";
			}else {
				m.erase(SEQ[i]);
				if(me[SEQ[i]]==0){
					m[SEQ[i]]=1;
					me.erase(SEQ[i]);
			//cout<<".c.";		
				}
			}

		}
		return me.size();
	}
	int countCustomers( vector<int> &SEQ,  
		int K){
		short status[MAX_PERSONS]={0};
	//0 not entered....1...entered 2...PC allocated
		int ans=0;
		int PC_alloted=0;
		for(int i=0;i<SEQ.size();i++){
			//
			if(status[SEQ[i]]==2){
				PC_alloted--;
			}else{
				if(status[SEQ[i]]!=1){
					if(PC_alloted < K){
						PC_alloted++;
						status[SEQ[i]]=2;	
					}	else{
						status[SEQ[i]]=1;
						ans++;
					}
				}
			}		
		}
		return 	ans;
	}
	int main(){
		clock_t begin = clock();
		file_i_o();
		int TC=1;
		cin>>TC;
		while(TC--){
			int N,K;
			cin>>N>>K;
		//cout<<"\n N = "<<N<<": K = "<<K<<endl;
			vector<int> ARR(2*N);
			ARR.clear();
			for(int i=0;i<(2*N);i++){ 
			//cout<<ARR.size();
				int x;
				cin>>x;
				ARR.push_back(x);
			}
		//cout<<endl<<" b4 calling "<<ARR.size();
			//cout<<runCustomerSimulation_CDGNJA(ARR,K)<<endl;
			cout<<countCustomers(ARR,K)<<endl;
		}
	 #ifndef ONLINE_JUDGE 
		clock_t end = clock();
		cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
		return 0;
	}
