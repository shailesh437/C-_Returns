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
vector<int> solve(vector<int> &A, int B) {
 vector<long long int> pSum(A.size());
    pSum[0]=(long long int)A[0];
    int X;
    bool singleEle=false;
    for(int i=1;i<A.size();i++){
        pSum[i]=pSum[i-1]+(long long int)A[i];
        if(A[i]==B) {
         singleEle=true;
         X=A[i];
        }
        if(pSum[i] == (long long int)B){
        	vector<int> ANS;
            for(int k=0;k<=i;k++)
                ANS.push_back(A[k]); 
            return ANS;
        }
    }

    int i=1;
    int j=2;
    while(j<A.size()){
        long long int check = pSum[j]-pSum[i-1];
        if(check==(long long int)B) {
            vector<int> ANS;
            for(int k=i;k<=j;k++)
                ANS.push_back(A[k]); 
            return ANS;
        }
        if(check>B){
            i++;
        }else{
            j++;
        }
    }
     
    vector<int> ANS;
    if(singleEle){
        ANS.push_back(X);
    }else
    ANS.push_back(-1);
    return ANS;    	
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A = {1, 2, 3, 4, 5};
		int  B = 9;
		vector<int> ans = solve(A,B);
		logarr(ans,0,ans.size()-1); 
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
