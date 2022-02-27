//https://leetcode.com/problems/count-and-say/submissions/
class Solution {
public:
    string countAndSay(int n) {
     if(n==1){
			return "1";
		}
		if(n==2){
			return "11";
		}
		if(n==3){
			return "21";
		}
		if(n==4){
			return "1211";
		}
		string ans="1211";
		stack<char> eleStack;
		stack<int> countStack;
		int cnt=0;
		string ans1="";
		for(int i=5;i<=n;i++){
			eleStack.push(ans[ans.length()-1]);
			countStack.push(1);
			cnt=1;
			for(int i=ans.length()-2;i>=0;i--){
				if(eleStack.top() != ans[i]){
					eleStack.push(ans[i]);
					cnt=1;
				}else{
					cnt++;
					countStack.pop();				
				}
				countStack.push(cnt);
			}
			ans1="";
			//cout<<endl;
			//cout<<eleStack.size();
			//cout<<countStack.size();
			//cout<<endl;
			while(eleStack.size()>0){
				string ans2 = to_string(countStack.top());
				ans1 += ans2;
				ans1 += eleStack.top();
				//cout<<endl<<ans1;
				countStack.pop();
				eleStack.pop();
			}	
			ans=ans1;
			//cout<<endl<<ans1;
			while(!countStack.empty())
			countStack.pop();
			while(!eleStack.empty())
			
			eleStack.pop();
		}
        return ans1;
         
    }
};
