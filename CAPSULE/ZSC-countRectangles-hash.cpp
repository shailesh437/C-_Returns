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
int solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> points;
    map<pair<int,int>,int> m;
    for(int i=0;i<A.size();i++){
        points.push_back(make_pair(A[i],B[i]));
        m[make_pair(A[i],B[i])]++;
    }
    int ans=0;
    for(int i=0;i<A.size();i++){
    	for(int j=i+1;j<A.size();j++){
    		if(
    			(points[j].first > points[i].first 
    			and  
    			points[j].second > points[i].second)
    			or
    			(points[j].first < points[i].first 
    			and  
    			points[j].second < points[i].second)    
    			){

    			if(m[make_pair(points[i].first,points[j].second)]
    				and 
    			  m[make_pair(points[j].first,points[i].second)] 	
    				){
    				ans++;
    			}
    		}
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
		//vector<int> A = {1, 1, 2, 2, 3, 3 };
 		//vector<int> B =  {1, 2, 1, 2, 1, 2 };
 		//vector<int> A = {1, 1, 2, 2 };
 		//vector<int> B =  {1, 2, 1, 2 };
 		vector<int> A = {38, 36, 48, 42, 36, 56, 38, 48, 40, 24, 48, 32, 22, 54, 22, 42, 34, 54, 52, 36, 52, 38, 36, 30, 30, 44, 46, 58, 56, 52, 48, 34, 36, 42, 50, 34, 28, 44, 44, 60, 56, 32, 48, 22, 56, 38, 42};
 		vector<int> B =  {58, 42, 30, 60, 50, 42, 40, 24, 54, 28, 52, 54, 28, 32, 42, 54, 38, 38, 54, 24, 30, 60, 44, 40, 26, 56, 28, 60, 34, 50, 48, 28, 56, 34, 48, 26, 30, 22, 52, 36, 24, 50, 42, 58, 54, 54, 48};
 		int ans = solve(A,B);
 		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
