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
int getLastIndexOfCharInString(int &wsptr,
							   string w,
							   string p, 
							   int psptr){
	char x = w[wsptr];
	string tmp = p.substr(psptr);
	//
    if(w[wsptr]=='?'){
    	if(wsptr>0 and w[wsptr-1]=='*') //*? atleast 1 should match	
    		{
    			size_t li;
    			if(wsptr<w.length()){
    				li = tmp.find_last_of(w[wsptr+1]);
    				wsptr++;	
    			}else{    				
    				return tmp.length()-1;	
    			}
    			return li;
    		}else{
    			//cout<<"\n---"<< wsptr <<"-"<<psptr;
    			if(wsptr == w.length()-1 
    				and psptr>=p.length()){
    				return -1;
    			}
    		}
    }
	if(x=='?') return 0;
	size_t li = tmp.find_last_of(x);
	if(li ==  string::npos)	{
		return -1;
	}
	return li;
	 for(int j=tmp.length()-1;j>=0;j--){
		if(tmp[j]==x){
			return tmp.length()-j;
		}
	}
	return -1;
}
bool match(string wild, string pattern)
{
	int wsptr=0,psptr=0;
	while(psptr<pattern.length()){
		//if(psptr==2) return 0;
		//cout<<"\n after wile :"<<wsptr<<"-"<<psptr<<endl;
		while(wild[wsptr]!='*' and wsptr<wild.length()){
			if(wild[wsptr] != pattern[psptr] 
				and wild[wsptr] != '?'){ 
				return false;
				}
			wsptr++;psptr++;
			if(wild[wsptr]=='*') continue;
			if(wsptr<wild.length() and psptr>=pattern.length()){
				return false;
			}
			//cout<<"\n 4 wsptr reached "<<wsptr<<"-"<<psptr;
		} 
	while(wild[wsptr]=='*' and wsptr<wild.length()){
		wsptr++;
	}
	if(wsptr>=wild.length() and psptr<pattern.length() 
		and wild[wild.length()-1]!='*'){
		return false;
	}
	if(wsptr>=wild.length()){
			//cout<<"\n====2.00 returning true"<<wsptr<<"::"<<psptr;
			return true;	
	} 
	//cout<<"\n wsptr after * = "<<wsptr<<":: and psptr = "<<psptr<<endl;
	int li=-1;
	li = getLastIndexOfCharInString(wsptr,
								    wild,
									pattern,
									psptr);

	//cout<<endl<<" li = "<<li<<endl;
	if( li != -1){
		//cout<<"\n psptr => "<<psptr<<endl;
		psptr=psptr+li ;

		//cout<<"\n psptr => "<<psptr<<endl;
		//return 0;
	}else{
		//cout<<"\n1.1 returning false \n";
		return false;
	}

} //EOW
//cout<<"\nwhilover wsptr = "<<wsptr<<endl;
if(wsptr<wild.length()){
	string tmp = wild.substr(wsptr);
	for(int i=0;i<tmp.length();i++){
		if(tmp[i]!='*')
			return false;
	}
}
return true;
}


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		string wild,pattern;
		cin>>wild>>pattern;
		
		cout<<wild<<" | "<<pattern;
		//cout<<match(wild,pattern);
		bool FINAL_ANS = match(wild,pattern);
		cout<<endl<<endl<<"FINAL_ANS:"<<FINAL_ANS<<"====\n";
		//cout<<getLastIndexOfCharInString('e',"efgefgefg",3);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
