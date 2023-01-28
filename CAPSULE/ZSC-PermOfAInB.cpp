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

int solve(string A, string B) {
	map<char,int> mA;
	int val=1;
	for(char ch='a';ch<='z';ch++,val++){
		//if(val%2)
		//mA[ch]=val*A.length()*-1*pow(2,val%10);
		//else
		mA[ch]=val*A.length()*pow(26,val%5);		
	}
	for(auto it=mA.begin();
		it!=mA.end();
		it++){
		cout<<endl<<it->first<<":"<<it->second;
}
int startBIndex=0;
int endBIndex=A.length()-1;
	    //cal B 1st string 
int Aval=0;
int BvalSS=0;
for(int i=0;i<=A.length()-1;i++){
	Aval+=mA[A[i]];
	BvalSS+=mA[B[i]];
}
int count=0;
if(BvalSS==Aval){
	count++;
}
while(endBIndex<B.length()-1){
	BvalSS-=mA[B[startBIndex]];
	startBIndex++;
	endBIndex++;
	BvalSS+=mA[B[endBIndex]];
	if(BvalSS==Aval){
		cout<<endl<<count<<":"<<BvalSS<<":"<<Aval<<":"<<B.substr(startBIndex,endBIndex-startBIndex+1);
		count++;
	}	
}
return count;
}


int countPermutationOfA_In_B(string A,string B){
	vector<int> currFreqArr(26,0);
	vector<int> reqdFreqArr(26,0);
	for(char c:A){
		reqdFreqArr[c-'a']++;
	}
	for(int i=0;i<A.length();i++){
		currFreqArr[B[i]-'a']++;
	}
	for(int i=0;i<reqdFreqArr.size();i++){
		if(reqdFreqArr[i]>0)
			cout<<endl<<"reqdFreqArr["<<i<<"]=["<<reqdFreqArr[i]<<"]";
	}
	for(int i=0;i<currFreqArr.size();i++){
		if(currFreqArr[i]>0)
			cout<<endl<<"currFreqArr["<<i<<"]=["<<currFreqArr[i]<<"]";
	}
	int ans=0;
	int need=A.length();
	for(int i=0;i<A.length();i++){
		if( reqdFreqArr[B[i]-'a']>0 and 
			currFreqArr[B[i]-'a']>=reqdFreqArr[B[i]-'a'])
			need--;
	} 
	if(need==0){
		ans++;
	} 
	int sW=1;
	int eW=A.length();
	while(eW<B.length()){
		
		if(B[sW] != B[eW]){
			if(currFreqArr[B[sW]-'a'] <= reqdFreqArr[B[sW]-'a'])
				need++;
			if(currFreqArr[B[eW]-'a'] < reqdFreqArr[B[eW]-'a'] )
				need--; 
			currFreqArr[B[sW]-'a']--;
			currFreqArr[B[eW]-'a']++;	
		}
		
		if(need==0) ans++;
		sW++;
		eW++;
	}
	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//string A = "qab";
		//string B = "cpaapcqqappdcobpoodaqqaee";
		
		string A = "abc";
		string B = "bcaabcaccab";
		

		int ANS = solve(A,B);
		
		cout<<endl<<"ANS = "<<ANS<<endl;
		ANS=countPermutationOfA_In_B(A,B);
		cout<<endl<<"ANS = "<<ANS<<endl;

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
