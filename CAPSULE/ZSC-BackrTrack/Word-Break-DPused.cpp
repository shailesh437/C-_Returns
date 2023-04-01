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
bool Bcontainsleft(vector<string> &B,
	string left){
	for(string s:B){
		if(s==left){
			return true;
		}
	}
	return false;
}
void possibleSegments(string A,
	vector<string> &segments,
	vector<string> &B){
	if(A.length()==0){
		return;
	} 	
	for(int i=0;i<A.length();i++){
		string left=A.substr(0,i+1);
		if(Bcontainsleft(B,left)){
			segments.push_back(left);
			string right=A.substr(i+1);
			possibleSegments(right,segments,B);
		}
	}
}

int wordBreak(string A, vector<string> &B) {
	vector<string> segments;
	possibleSegments(A,segments,B);
	for(int i=0;i<segments.size();i++){
		cout<<endl<<segments[i];
	}
	sort(B.begin(),B.end());
	sort(segments.begin(),segments.end());
	return B==segments; 
}


int wordBreak_dp(string A, vector<string> &B) {
	vector<int> dp(A.size(),0);
	map<string,int> m;
	for(string s:B){
		m[s]++;
	}
	for(int i=0;i<dp.size();i++){
		for(int j=0;j<=i;j++){
			string word=A.substr(j,i+1-j); 
			if(m[word]>0){
				if(j==0){
					dp[i]=1;
				}else{
					//cout<<endl<<":"<<(i-j)<<endl;
					dp[i]=dp[j-1]+1;
				}
			}else{
				m.erase(word);
			}
		}
	}
	//logarr(dp,0,dp.size()-1);

	return dp[A.size()-1]==B.size(); 
}



bool Bcontainsleft11(vector<string> &B,
	string left){
	for(string s:B){
		if(s==left){
			return true;
		}
	}
	return false;
} 
int wordBreak11(string A, vector<string> &B) {
/*vector<string> segments;
possibleSegments(A,segments,B); 
sort(B.begin(),B.end());
sort(segments.begin(),segments.end());
return B==segments;*/
	vector<bool> dp(A.size()+1,false); 
	map<string,int> m;
	int maxStringLength=B[0].length();
	for(string s:B) {
		m[s]++;
		int len=s.length();
		maxStringLength=max(maxStringLength,len);
	}
		for(int i=0;i<=dp.size();i++){
		 /*if(dp[i]==false and Bcontainsleft(B,A.substr(0,i))){
                dp[i]=true;
            }*/
			if(dp[i]==false){
				string chk = A.substr(0,i); 
				if(m[chk]){
					dp[i]=true;
				}else{
					m.erase(chk);
				}
			}    
			if(dp[i]){
				if (i == A.size())
					return true;
				for(int j=i;j<=A.size();j++){
             /*if(dp[j+1]==false and Bcontainsleft(B,A.substr(i,j-i+1))){
                    dp[j+1]=true;
                }   */
					if(dp[j+1]==false and maxStringLength>=(j-i)) {
						string chk = A.substr(i,j-i+1); 
						if(m[chk]){
							dp[j+1]=true;
						}else{
							m.erase(chk);
						} 
					}    
					if(j==A.size() and dp[j]){
						return true;
					}   
				}    
			}    
		} 
		logarr(dp,0,dp.size()-1);
		return false; 

	}

	int main(){
		clock_t begin = clock();
		file_i_o();
		int TC=1;
	//cin>>TC;
		while(TC--){
		//string A = "ilovecodingz";
		//vector<string> B={"i","love","coding"};
			string A="myinterviewtrainer";
			vector<string> B={"interview", "my", "trainer"};
			//A="aabbbaabaaaaaababbabaabbaababbaaaaaaabbababbabaabaabababaabbababababbbbbbbbaabbbaaabbbaaaaaabaaaabbabbaaaabaaaabaaabbababbbbabbbababbbbaaababbbbbbabbbaabaabbbbabbabaababaaaabbbbaaaaabaaaabbbaaaaababaaaabbaabababbbabbbababbabbbbbbaaaabaaaabbababbbaabaaaaaaaababbaaaaabbaaaabaaaabbbbbaababaabbababbbbbbbbbbabaabbabaaaaabbaabbbaababbbabbaaabbaaabbbbaaaabbbbbabbbbbabaaabababbabbbbbababbbbaabaabbbaabaabaababbaaabbbabbbabaabbbbabbaabbabbaaaabbbbbababaaaaaaaabbbaaababbbbababaabbaaabbbabbbbaaabbabbbbbbaaaaabbbbabababbabaabbabababbabaabaabbbaaabbabaabaaabbbbbbbaabaaabbabbabbabbbbabbaabbabaaaabbabbbabbabbbaababbabbbbaaaababbabbbbbbabbbbabbaaabaa";
			//B={"aabaa", "aaab", "bbb", "aaabaaa", "babaabb", "babba", "bababab", "bbabb", "abaabaaabb", "ababb", "baaab", "babaabbaab", "ab", "b", "a", "aa", "babbbb", "babbaaba", "aaba", "aabbb", "ab", "aaaabbbba", "baa", "ab", "aaaabb", "babab", "bbb", "bbbbbaba", "aaabb", "abbbbaabb", "ab", "abbbbb", "aba", "aababbbab", "ba", "aab", "ababaabaab", "ba", "baabbaaaa", "a", "babbbaab", "bababbbb", "babaab", "aaaabbaa", "babbbb", "bbba", "abaabb", "abbb", "babaaabab", "bababbab", "bbbab", "a", "aabaabbbba", "abbba", "babbbb", "bbaaabbaa", "bbaa", "ababbbba", "aaababaaa", "ba", "a", "bbaababbaa", "babba", "abbaabbaa"};
		//vector<string> B={"abbbabaa", "baabaaaab", "babaaaaaba", "b", "b", "bbaaaab", "aaabbb", "aabbbbbab", "abbb", "abaa", "aaababaab", "aabbabaa", "bab", "bbbbaabbb"};

		//int ans = wordBreak_dp(A,B);
			int ans = wordBreak11(A,B);
			cout<<"ANS = "<<ans;
		}
	 #ifndef ONLINE_JUDGE 
		clock_t end = clock();
		cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
		return 0;
	}
