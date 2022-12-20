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
int getCountOfDivisors(vector<int> &SPF,int X){ 
     map<int,int> M;
     int cnt=0;
     while(X>1){
         M[SPF[X]]++;
         X=X/SPF[X];
     }
     int ans=1;
     for(auto it=M.begin();it!=M.end();it++){
         ans*=(it->second+1);
     }
    return ans;
}

vector<int> solve(vector<int> &A) {
    int maxElem=INT_MIN;
    for(int i=0;i<A.size();i++){
        maxElem=max(maxElem,A[i]);
    }
    vector<int> SPF(maxElem+1);//smallest primt factor
    for(int i=0;i<=maxElem;i++){
        SPF[i]=i;
    }

    for(int i=2;i<=sqrt(maxElem);i++){
        if(SPF[i]==i){
            for(int j=i*i;j<=maxElem;j+=i){
                if(SPF[j]==j){
                    SPF[j]=i;
                }
            }
        }
    }
    cout<<"\n SPF[5]="<<SPF[5]<<endl;
    vector<int> ANS(A.size()); 
    for(int i=0;i<A.size();i++){ 
        int countOfDivisors=getCountOfDivisors(SPF,A[i]);
        ANS[i]=countOfDivisors;
    }
    
    return ANS;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A= {2, 3, 4, 5};
		 vector<int> ANS=solve(A);
		 cout<<endl<<"---------------------\n";
		 for(int i=0;i<ANS.size();i++)
		 	cout<<ANS[i]<<" ";
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
