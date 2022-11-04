bool compare(int a,int b){
  string a_str=to_string(a);
	 string b_str=to_string(b);
	 if(stol(a_str+b_str)>stol(b_str+a_str))
	 	return true;
	return false;
}
string Solution::largestNumber(const vector<int> &A) {
     vector<int> B;
     bool allzero=true;
     for(int i=0;i<A.size();i++){
         if(A[i]==0) continue;
         allzero=false;
     }
     if(allzero) return "0";
     for(int i=0;i<A.size();i++){
         B.push_back(A[i]);
     }
     sort(B.begin(),B.end(),compare);
     string ans="";
     for(int i=0;i<B.size();i++)
        ans+=to_string(B[i]);
     return ans;   
}
