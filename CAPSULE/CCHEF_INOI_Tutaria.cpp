#include<bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	    long long int N;
		cin>>N;
		vector<pair<long long int,long long int>> vii;
		for(int i=0;i<N;i++){
			long long int C,V,D;
			cin>>C>>V>>D;
			vii.push_back(make_pair(V+D,C));
		}
		sort(vii.rbegin(),vii.rend());
		/*for(int i=0;i<N;i++){
			cout<<endl<<vii[i].first<<"-"<<vii[i].second;
		}*/
		long long int time_spent_fc=0;
		long long int time_needed_fo=0;
		time_spent_fc=vii[0].second;
		time_needed_fo=time_spent_fc+vii[0].first;

		for(int i=1;i<N;i++){
			time_spent_fc+=vii[i].second;
			time_needed_fo=max(time_needed_fo,time_spent_fc+vii[i].first);
			//cout<<endl<<time_spent_fc<<"----"<<time_needed_fo;			
		}
		cout<<time_needed_fo;
	return 0;
}
