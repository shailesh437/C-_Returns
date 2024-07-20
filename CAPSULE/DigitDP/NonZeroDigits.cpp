

int MOD=1000000007;
int dp[18][2][40000];
map<string,int> m1;
int find(string S,int position,int isSmaller,int count){
	if(count>3) return 0;
	if(position==S.length()){
		if(count<=3){
			return 1;
		}
		return 0;
	}
	if(dp[position][isSmaller][count]!=-1){
		return dp[position][isSmaller][count];
	}
	int maxLimit=9;
	if(isSmaller==0){
		maxLimit=S[position]-'0';
	}
	int ans=0;
	for(int i=0;i<=maxLimit;i++){
        if(count>3){
            continue;
        }
		int newIsSmaller=isSmaller;
		if(isSmaller==0 and i<S[position]-'0'){
			newIsSmaller=1;
		}
		int newCount=count;
		if(i!=0) newCount++;
		if(newCount>3 ){
			ans+=0;
		}else{
			ans+=find(S,position+1,newIsSmaller,newCount);
			ans%=MOD;
		}
	}
	return dp[position][isSmaller][count]=ans;
}



string subtractOne1(string inp){
	vector<int> num(inp.size(),0);
	int string_len = inp.length()-1;
	for(int i=string_len;i>=0;i--)
	{
		num[string_len-i]=inp[i]-'0';
	} 
	int deduct=0;
	if(num[0]>0){
		num[0]-=1;
	}else{
		num[0]=9;
		deduct=1;
	} 
	for(int i=1;i<=string_len;i++){
		if(num[i]-deduct>=0){
			num[i]-=deduct;
			deduct=0;
		}else{
			num[i]=9;
		}
	}
	if(deduct>0){
		num[string_len]=0;
	}
    //logarr(num,0,num.size()-1);

	while(num[string_len]==0 and string_len>0){
		string_len--;
	}
	vector<char> result;
    //logarr(num,0,num.size()-1);
	for(int i=string_len;i>=0;i--)
	{
		result.push_back(num[i]+'0');
	}
    //logarr(result,0,result.size()-1);

	string result_s(result.begin(),result.end());
	return result_s;
}

vector<int> Solution::solve(vector<string> &A) {

    	vector<int> ans;
	for(int i=0;2*i<A.size()-1;i++){
		string L=A[2*i];
		string R=A[2*i+1];
		memset(dp,-1,sizeof dp);
		int ans1;
        if(m1[R]!=0){
            ans1=m1[R];
        }else{
            ans1=find(R,0,0,0);
            m1[R]=ans1;
        }
       
		L=subtractOne1(L);
		memset(dp,-1,sizeof dp);
        int ans2;
        if(m1[L]!=0){
            ans2=m1[L];
        }else{
           ans2=find(L,0,0,0);
            m1[L]=ans2;
        }
        
		//cout<<"ans1="<<ans1<<endl;
		//cout<<"ans2="<<ans2;
        
        
		int x = (ans1%MOD-ans2%MOD+MOD)%MOD;
		ans.push_back(x);
	}
	return ans;
}
