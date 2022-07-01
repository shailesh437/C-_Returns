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
int repeatedStringPresent(string S,string test,int fromIndex){
	string s1 = S.substr(fromIndex);
	if (s1.find(test) != std::string::npos) {
		return fromIndex+s1.find(test);
	}
	return -1;
}
int getNoOfSyllablesInString(string S){
	string VOW="aeiou";
	int syll=0;
	for(int i=0;i<S.length();i++){
		if(count(VOW.begin(),VOW.end(),S[i])==1){
			syll++;
		}
	}
	return syll;
}
bool solve1(string S){
	//cout<<S<<endl;
	//return false;
	string VOW="aeiou";
	if(S.length()<5) return false;
	if(S.length()==5){
		//all 3 should be vowels
		for(int i=0;i<S.length();i++){
			if(count(VOW.begin(),VOW.end(),S[i])!=1){
				//cout<<
				return false;
			}
		}
		if(S[0]==S[3] and S[1]==S[4]){ 
				return true; 
		}
		return false;
	}
	for(int i=0;i<S.length()-3;i++){
		for(int j=S.length()/2-i-1;j>0;j--){
			cout<<endl<<"i="<<i<<"::i+j="<<(i+j);
			string test=S.substr(i,i+j);
			cout<<"test="<<test<<endl;
			//return false;
			int presentIndex=repeatedStringPresent(S,test,i+j+2) ;
			cout<<"\n present="<<presentIndex;
			cout<<"\n mid-range="<<(i+j)<<"-"<<presentIndex;
			if(presentIndex!=-1 
				and
				getNoOfSyllablesInString(test)>=2
				and 
				getNoOfSyllablesInString(S.substr(i+j+1,presentIndex))>=1){
				return true;
			}
		}
	}
	return false;
}
bool solve(string S){
	//check if S contains less than 5 vowels
	string VOW="aeiou";
	int vowcount=0;
	for(int i=0;i<S.length();i++)
		if(count(VOW.begin(),VOW.end(),S[i])==1)
			vowcount++; 
	if(vowcount<5){
			return false;
	}
	for(int i=0;i<S.length()-4;i++){
		int beginStartIndex=i;
		//cout<<"\n checking with "<<beginStartIndex;
		while(count(VOW.begin(),VOW.end(),S[beginStartIndex])!=1 and (beginStartIndex<S.length()-3))
				beginStartIndex++;

		int beginEndIndex=beginStartIndex+1;

		while(count(VOW.begin(),VOW.end(),S[beginEndIndex])!=1 
			   		and (beginEndIndex<S.length()-2))
			beginEndIndex++;
			//cout<<"\n begin 2nd char at "<<(j);
		string begin=S.substr(beginStartIndex,beginEndIndex-beginStartIndex+1);
			//cout<<"\n begin = "<<begin<<endl;
			//check for middle vowel
		int midStart=beginEndIndex+1;
		while(count(VOW.begin(),VOW.end(),S[midStart])!=1 and (midStart<S.length()-2))
				midStart++;
		if(midStart>=S.length()-2) return false;
		int endIndexPossibleFrom=midStart+1;
		int endIndex=repeatedStringPresent(S,begin,endIndexPossibleFrom);
		if(endIndex!=-1)
			return true;
			//break;
		}
	return false;		
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	int tc=1;
	while(TC--){
		string S;
		cin>>S; 
		bool result=solve(S);
		if(result)
			cout<<"Case #"<<tc++<<": "<<"Spell!"<<endl;
		else
			cout<<"Case #"<<tc++<<": "<<"Nothing."<<endl;

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
