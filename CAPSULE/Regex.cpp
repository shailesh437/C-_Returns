
bool isMatch2(const string s,const string p,int i,int j){
	vector<vector<int>> dpp(2,vector<int>(s.length(),-1));
	bool charFirstMatched=false;
	if(s[0]==p[0] or p[0]=='?' or p[0]=='*'){
		if(s[0]==p[0] or p[0]=='?'){
			charFirstMatched=true;
		}
		dpp[0][0]=1;
	}else{
		dpp[0][0]=0;
	}
	for(int i=1;i<s.length();i++){
		if(p[0]=='*'){
			dpp[0][i]=1;
		}else{
			dpp[0][i]=0;
		}
	}
	int flag=1;
	for(int i=1;i<p.length();i++){
		if(p[i]=='*'){
			dpp[flag][0]=dpp[1-flag][0];
		}else if (( p[i]=='?') and !charFirstMatched){
			dpp[flag][0]=dpp[1-flag][0];
			charFirstMatched=true;
		}else{
			dpp[flag][0]=0;
		}
		for(int j=1;j<s.length();j++){
			if(p[i]==s[j] or p[i]=='?'){
				dpp[flag][j]=dpp[1-flag][j-1];		
			}else if(p[i]=='*'){
				dpp[flag][j]=dpp[flag][j-1] | dpp[1-flag][j]; 
			}else{
				dpp[flag][j]=0;
			}
		}
		flag=1-flag;
	}
	if(p.length()%2){
		return dpp[0][s.length()-1];
	}
	return dpp[1][s.length()-1]; 
}

int Solution::isMatch(const string A, const string B) {
    
    int countOfAsterisk=0;
    for(int i=0;i<B.length();i++){
        if(B[i]=='*'){
            countOfAsterisk++;
        }
    }
    if(B.length()-countOfAsterisk>A.length()) return 0;
    int ans = isMatch2(A,B,0,0);
	return ans;
}
