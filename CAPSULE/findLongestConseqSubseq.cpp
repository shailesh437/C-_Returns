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
int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      map<int,int> m;
      for(int i=0;i<N;i++){
          m[arr[i]]++;
      }
      int main_ans=1;
      int cur_ans=1;
      auto it = m.begin();
      int prev_key = it->first;
      for(; it!=m.end();it++){
          int curr_key = it->first;
          //cout<<endl<<curr_key<<" - "<<prev_key<<"=="<<cur_ans;
          if(curr_key-prev_key == 1){
              cur_ans++;
          }
          else if(curr_key == prev_key){
              continue;
          }else{
              cur_ans=1;
          }
          prev_key = curr_key;
          main_ans=max(main_ans,cur_ans);
      }
      return main_ans;
    }
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int arr[] = {2 ,6 ,1 ,9 ,4 ,5 ,3};
		int N=7;
		cout<<findLongestConseqSubseq(arr,N);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
