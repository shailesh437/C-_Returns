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
int setBitCount(int X){
	int sbc=0;
	while(X){
		if(X&1){
			sbc++;
		}
		X=X>>1;
	}
	return sbc;
}
int sortcolIndex=0;
bool sortcol(const vector<int> &V1,const vector<int> &V2){
	return V1[sortcolIndex]<V2[sortcolIndex];
}
vector<vector<int>> combine(int A, int B) 
{
	vector<vector<int>> ANS;
	vector<int> subAns;
	if(B>A) return ANS;
	if(B==1){
		for(int i=1;i<=A;i++){
			subAns.clear();
			subAns.push_back(i);
			ANS.push_back(subAns);
		}
		return ANS;
	}
	if(B==A){
		subAns.clear();
		for(int i=1;i<=A;i++){
			subAns.push_back(i);
		}            
		ANS.push_back(subAns);
		return ANS;
	}
 
	int minVal = (1<<B)-1;
	int maxVal = minVal<<(A-B);  
	set<vector<int>> S;
	for(int val=minVal;val<=maxVal;val++){
		if(setBitCount(val)==B){
			int digPlace=1;
			vector<int> digPlaces(B);
			int temp=val;
			digPlaces.clear();	
			while(temp){
				 	if(temp&1){
    					digPlaces.push_back(digPlace);
					}
					digPlace++;
					temp=temp>>1;
				} 
				S.insert(digPlaces);
			}
		} 
		vector<vector<int>> ANS1(S.begin(),S.end()); 

		return ANS1;
	}
	int main(){
		clock_t begin = clock();
		file_i_o();
		int TC=1;
	//cin>>TC;
		while(TC--){
		//vector<vector<int>> ANS=combine(4,2);
		//vector<vector<int>> ANS=combine(3,2);
		//vector<vector<int>> ANS=combine(1,1);
		//vector<vector<int>> ANS=combine(2,1);
		//vector<vector<int>> ANS=combine(3,2);
			vector<vector<int>> ANS=combine(5,3);
		//vector<vector<int>> ANS=combine(4,3);
			cout<<endl<<"-----------------------------\n";
			for(int i=0;i<ANS.size();i++){
				for(int j=0;j<ANS[0].size();j++){
					cout<<ANS[i][j]<<" ";
				}
				cout<<endl;
			}
		}
	 #ifndef ONLINE_JUDGE 
		clock_t end = clock();
		cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
		return 0;
	}
