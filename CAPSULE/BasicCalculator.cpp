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

map<int,pair<int,int>> startEndPosValue;
stack<pair<int,char>> bracketStack;

void evaluate(string s,int startPos, int endPos){
	int i=startPos;
	int postToUpdateInstartEndPosValue=startPos-1;
	int result=0;
	while(i<=endPos){

		if(startEndPosValue.find(i)!=startEndPosValue.end()){
			result+=startEndPosValue[i].second;
			i=startEndPosValue[i].first+1;
			continue;
		}

		if(s[i]=='-' and startEndPosValue.find(i+1) !=startEndPosValue.end()){
			startEndPosValue[i+1].second*=-1;
			result+=startEndPosValue[i+1].second;
			i=startEndPosValue[i+1].first+1;
			continue;
		}
		if(s[i]=='+'){
			result+=startEndPosValue[i+1].second;
			i=startEndPosValue[i+1].first+1;
			continue;	
		}
		i++;
	}
	startEndPosValue[postToUpdateInstartEndPosValue].first=endPos;
	startEndPosValue[postToUpdateInstartEndPosValue].second=result;
}

int calculate(string inp){

	vector<char> inp_vec_no_space;
	inp_vec_no_space.push_back('(');
	for(int i=0;i<inp.length();i++){
		if(inp[i]==' '){
			continue;
		}
		inp_vec_no_space.push_back(inp[i]);
	}
	inp_vec_no_space.push_back(')');

	string s(inp_vec_no_space.begin(),inp_vec_no_space.end());
	 //numbers extrascted

	for(int i=0;i<s.length();i++){
		if(s[i]>=48 and s[i]<=57){
			int startPos=i;
			stack<int> createNumberStack;
			int j=i;
			int lenOfNum=0;
			while(s[j]>=48 and s[j]<=57){
				createNumberStack.push(s[j]-'0');
				j++;
				lenOfNum++;
			}
			int endPos=startPos+createNumberStack.size()-1;
			int multiplier=1;
			int value=0;
			while(!createNumberStack.empty()){
				value+=createNumberStack.top()*multiplier;
				createNumberStack.pop();
				if(multiplier==1000000000) break;
				multiplier*=10;
			}
			startEndPosValue[startPos]=make_pair(i+lenOfNum-1,value);	
			i=endPos+1;
		}
	} 

	 //bracket----
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')
			bracketStack.push(make_pair(i,'('));

		if(s[i]==')'){
			pair<int,char> lastbracket=bracketStack.top();
			bracketStack.pop();
		//	cout<<endl<<"calling evaluate:"<<lastbracket.first+1<<":"<<i-1;

			evaluate(s,lastbracket.first+1,i-1);
		}

	}

	return startEndPosValue[0].second;

}

int calculate2(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st;

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                long long int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if(s[i] == '('){
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            else if(s[i] == '-'){
                sign = -1 * sign;
            }
        }
        return sum;
    }


int calculate3(string s){
	long long int sum=0;
	int sign=1;
	long long int num=0;
	stack<pair<int,int>> stak;
	for(int i=0;i<s.length();i++){
		num=0;
		if(isdigit(s[i])){
			num=s[i]-'0';
			i++;
			while(i<s.length() and isdigit(s[i])){
				num=num*10+(s[i]-'0');
				i++;
			}
			i--;
			sum+=num*sign;
			sign=1;
		}else if(s[i]=='-'){
			sign*=-1;
		}else if (s[i]=='('){
			stak.push({sum,sign});
			sum=0;
			sign=1;
		}else if(s[i]==')'){
			sum=stak.top().first + (stak.top().second*sum);
			stak.pop();
		}
	}
	return sum;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//string s ="(1+(4+5+2)-3)+(6+8)";
		string s ="1-2+3";
		s="1-(4+8-2)+100-(900+50)";
		s ="((1+(4+5+2)-3)+(6+8))";
		//s="2147483647";
		int result = calculate3(s);
		cout<<endl<<"Result = "<<result<<endl;
 

	char x = '9';
	int y = x;
	cout<<y;
}
	 #ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
