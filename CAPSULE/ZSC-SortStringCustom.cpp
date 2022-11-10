map<char,int> m;
bool compare(string s1,string s2){
   int pointer=min(s1.length(),s2.length());
    int c=0; 
    if(m[s1[0]]<m[s2[0]]) return true;
    if(m[s1[0]]==m[s2[0]]) {
    	for(int i=1;i<pointer;i++){
    		if(m[s1[i]]>m[s2[i]]) return false;
    	}
    	return true;
    }
    return false;
}
int Solution::solve(vector<string> &A, string B) {
    for(int i=0;i<B.length();i++){
        m[B[i]]=i+1;
    }
    vector<string> A_copy(A.begin(),A.end());
    sort(A_copy.begin(),A_copy.end(),compare);
     /*for(int i=0;i<A.size();i++){
        cout<<endl<<A_copy[i];
    }*/
    for(int i=0;i<A.size();i++){
        if(A[i]!=A_copy[i]) return 0;
    }
    return 1;
}
