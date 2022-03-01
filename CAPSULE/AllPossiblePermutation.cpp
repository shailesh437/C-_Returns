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

void Perm1(const string &prob,
	const string &soln){
	if(prob=="" or prob.length()==0){
		cout<<soln<<endl;
	}
	for(int i=0;i<prob.length();i++){
		string childProb(prob);
		childProb.erase(i,1);
		Perm1(childProb,soln+prob[i]);
	}
}


void generatePerm(const  string &prob,const string &soln,vector<string> &ansV){
	if(prob=="" or prob.length()==0){
		cout<<soln<<endl;
		ansV.push_back(soln);
		return;
	}
	for(int i=0;i<prob.length();i++){
		string newProb(prob);
		newProb.erase(i,1);
		generatePerm(newProb,soln+prob[i],ansV);
	}
}

vector<string> find_permutation(string S)
{
		    // Code here there
	vector<char> v(S.begin(),S.end());
	sort(v.begin(),v.end());
	string qn(v.begin(),v.end());
	vector<string> Ans;
	string soln="";
	generatePerm(qn,soln,Ans); 

	return Ans;

}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string test="DABC";
		vector<char> v_c(test.begin(),test.end());
		sort(v_c.begin(),v_c.end());
		string prob(v_c.begin(),v_c.end());
		string soln="";
		//Perm1(prob,soln);
		vector<string> ANS = find_permutation(prob);

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
