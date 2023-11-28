#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1000000,INT_MIN);

int getmaxrc(vector<int> &values,int pos,vector<int> &fc){
	
	 if(dp[pos]!=INT_MIN){
		return dp[pos];
	}
	if(pos>=values.size()){
		return INT_MIN;
	}

	if(pos==(values.size()-1)){
		return fc[pos];
	}

	if(pos==(values.size()-2)){
		return max(fc[pos],
				values[pos]+fc[pos+1]);
	}


	return dp[pos] = max(fc[pos],
			   values[pos] + max(getmaxrc(values,pos+1,fc),
			   	   				 getmaxrc(values,pos+2,fc)	
			    				)
			   );
}

 
int main() {
	// your code goes here
	int N,k;
		cin>>N>>k;
		vector<int> values;
		for(int i=0;i<N;i++){
			int x;
			cin>>x;
			values.push_back(x);
		}
	    if(k==1){
	        
	    }
        vector<int> fc(values.size()+5,0);
		fc[k-1]=0;
		fc[k]=values[k];
		
		for(int i=k+1;i<values.size();i++){
			fc[i]=values[i]+max(fc[i-1],fc[i-2]);
		} 

		for(int i=k-2;i>=0;i--){
			fc[i]=values[i]+max(fc[i+1],fc[i+2]);
		} 
		int ans = values[0]+max(getmaxrc(values,1,fc),
								   getmaxrc(values,2,fc)); 	
	    if(k==1 and ans<0){
	        ans=0;
	    }
		cout<<endl<<ans;
		return 0;
}
