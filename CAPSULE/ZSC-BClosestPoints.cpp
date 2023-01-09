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
vector<vector<int>>  solve(vector<vector<int> > &A, int B) {
	map<int,vector<int>> m;
	for(int i=0;i<A.size();i++){
		int x1=A[i][0];
		int y1=A[i][1];
		long long int distance=x1*x1+y1*y1;
		int d = sqrt(distance);
		m[d].push_back(x1);
		m[d].push_back(y1);
	}
	vector<vector<int>> ANS;
	int b=0;
	for(auto it=m.begin();it!=m.end() and b<B;it++){
		vector<int> p = it->second;
		int eleInP=p.size();
		for(int i=0;i<eleInP and b<B ;i+=2){
			vector<int> pp;
			pp.push_back(p[i]);
			pp.push_back(p[i+1]);
			ANS.push_back(pp);
			pp.clear();
			b++;
		} 

	}
	return ANS;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<vector<int>> A = 
		{
			{-762, 643}
			,{693, -1004}
			,{-1026, 680}
			,{722, -1092}
			,{-875, 630}
			,{787, -860}
			,{-807, 999}
			,{1015, -788}
			,{-760, 889}
			,{990, -642}
			,{-1098, 1044}
			,{863, -614}
			,{-744, 651}
			,{959, -898}
			,{-905, 926}
			,{808, -725}
			,{-730, 809}
			,{871, -908}
			,{-993, 957}
			,{658, -924}
			,{-927, 872}
			,{735, -821}
			,{-1069, 1018}
			,{839, -777}
			,{-957, 786}
			,{853, -942}
			,{-865, 955}
			,{705, -1072}
			,{-717, 940}
			,{922, -618}
			,{-1013, 802}
			,{1065, -884}
			,{-638, 1063}
			,{654, -882}
			,{-722, 718}
			,{703, -870}
			,{-837, 1059}
			,{723, -747}
			,{-869, 620}
			,{951, -625}
			,{-890, 693}
			,{1043, -927}
			,{-745, 636}
			,{976, -951}
			,{-1055, 711}
			,{658, -867}
			,{-1011, 1049}
			,{867, -624}
			,{-685, 1018}
			,{1018, -962}
			,{-1070, 885}
			,{954, -798}
			,{-1005, 1095}
			,{-370, 81}
			,{156, -484}
			,{-286, 228}
			,{476, -87}
			,{-450, 114}
			,{86, -315}
			,{-89, 466}
			,{383, -447}
		};
		/*vector<vector<int>> Solution=solve(A,8);
		for(int i=0;i<Solution.size();i++){
			cout<<endl<<Solution[i][0]<<":"<<Solution[i][1];
		}
		*/
		vector<int> T = {-100000,-100000};
		/*long long int  x=100000;
		long long int  y=-100000;*/
		long long int  x=T[0];
		long long int  y=T[1];
		long  double d = x*x+y*y;
		cout<<endl<<d;
		d=sqrtl(d*1.0);
		cout<<endl<<d;
		map<long  double,vector<int>> m;
		m[d].push_back(T[0]);
		m[d].push_back(T[1]);
		int b=0;
		int B=1;
		vector<vector<int>> ANS;
		for(auto it=m.begin();it!=m.end() and b<B;it++){
			vector<int> p = it->second;
			int eleInP=p.size();
			for(int i=0;i<eleInP and b<B ;i+=2){
				vector<int> pp;
				pp.push_back(p[i]);
				pp.push_back(p[i+1]);
				ANS.push_back(pp);
				pp.clear();
				b++;
			} 
		}
		cout<<endl<<ANS[0][0]<<":"<<ANS[0][1];
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
