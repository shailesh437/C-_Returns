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
int printAllSubSequences(string s){
	int len=s.length();
	int n = pow(2,len)-1;
	for(int i=0;i<=n;i++){
		int x=i;
		int j=0;
		vector<char> v;
		while(x){
			if(x&1){
				v.push_back(s[j]);
			}
			x=x>>1;
			j++;
		}
		string ss(v.begin(),v.end());
		cout<<ss<<endl;
	}
	return n;
}

void printAllSubSequencesRec(string prob,string solnTillNow){
	 if(prob=="" or prob.length()==0){
	 	cout<<solnTillNow<<endl;
	 	return ;
	 }	 
	 printAllSubSequencesRec(prob.substr(1),solnTillNow+prob[0]);
	 printAllSubSequencesRec(prob.substr(1),solnTillNow);
	 
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//cout<<printAllSubSequences("abcd");
		printAllSubSequencesRec("abcd","");
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
