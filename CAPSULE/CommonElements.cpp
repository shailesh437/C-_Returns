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
 vector <int> commonElements (int A[], 
                                    int B[], 
                                    int C[],
                                    int n1, 
                                    int n2, 
                                    int n3)
        {
            //code here.
            vector<int> ans; 
            map<int,int> Amap;
            map<int,int> Bmap;
            map<int,int> Cmap;
            for(int i=0;i<n1;i++){
            	Amap[A[i]]++;
            }
            for(int i=0;i<n2;i++){
            	Bmap[B[i]]++;
            }
            for(int i=0;i<n3;i++){
            	Cmap[C[i]]++;
            }

            for(int i=0;i<n1;i++){
            	if(Amap[A[i]] and 
            		Bmap[A[i]] and 
            		Cmap[A[i]]){
            		ans.push_back(A[i]);
            		Amap[A[i]]=0;
            	}
            }

            return ans;
        }	

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int n1 = 6; 
		int A[] = {1, 5, 10, 20, 40, 80};
		int n2 = 5; 
		int B[] = {6, 7, 20, 80, 100};
		int n3 = 8; 
		int C[] = {3, 4, 15, 20, 30, 70, 80, 120}; 
		vector<int> ans = commonElements(A,B,C,n1,n2,n3);
		//logarr(ans,0,ans.size()-1);
		cout<<endl;
		for(int x: ans) cout<<x<<" ";
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
