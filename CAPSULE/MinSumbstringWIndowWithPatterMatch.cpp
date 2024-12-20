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

string getSubstringHavingPattern(string pattern,string source){
	map<char,int> patternMap;
	map<char,int> sourceMap;
	for(int i=0;i<pattern.length();i++){
		patternMap[pattern[i]]++;
	}
	for(int i=0;i<source.length();i++){
		sourceMap[source[i]]++;
	}

	for(auto it=patternMap.begin();it!=patternMap.end();it++){
		if(sourceMap[it->first]<patternMap[it->first]){
			cout<<endl<<it->first<<":"<<sourceMap[it->first]<<"::";
			cout<<patternMap[it->first]<<"::";
			return "";
		}
	} 
	int i=0;int j=source.length()-1;
	int start=0;
	int end = source.length()-1;
	
		while(sourceMap[source[i]]>patternMap[source[i]]){
			sourceMap[source[i]]--;
			i++; 
		}
		while(sourceMap[source[j]]>patternMap[source[j]]){
			sourceMap[source[j]]--;
			j--; 
		} 
	 
 	return source.substr(i,j-i+1);
}

string getMinimumWindowSubstringhavingPattern(string pattern, string source){
    map<char,int> patternMap;
    map<char,int> sourceMap;
    for(int i=0;i<pattern.length();i++){
        patternMap[pattern[i]]++;
    }
    for(int i=0;i<source.length();i++){
        sourceMap[source[i]]++;
    }
    for(auto it=patternMap.begin();it!=patternMap.end();it++){
        if(sourceMap[it->first]<patternMap[it->first]){
            return "";
        }
    }
    int i=0;
    int j=source.length()-1;
    while(sourceMap[source[i]]>patternMap[source[i]]){
        sourceMap[source[i]]--;
        i++;
    }
    while(sourceMap[source[j]]>patternMap[source[j]]){
        sourceMap[source[j]]--;
        j--;
    }
    return source.substr(i,j-i+1);
}


string getSubstringHavingPattern2(string pattern,string source){
	map<char,int> patternMap;
	map<char,int> sourceMap;
	int startWindow=0;
	int endWindow  =0;
	int matchedCharacters=0;
	int requiredCharacters=pattern.length();
	int i=0;
	
	for(int i=0;i<pattern.length();i++){
		patternMap[pattern[i]]++;
	}
	for(int i=0;i<source.length();i++){
		sourceMap[source[i]]++;
	}
	for(auto it=patternMap.begin();it!=patternMap.end();it++){
		if(sourceMap[it->first]<patternMap[it->first]){
			return "";
		}
	}
	sourceMap.clear();
	while(matchedCharacters<requiredCharacters and endWindow<source.length()){
		if(sourceMap[source[endWindow]]<patternMap[source[endWindow]]){
			matchedCharacters++;
		}
		sourceMap[source[endWindow]]++;
		endWindow++;
	}
	endWindow--; 
	int ans_start=startWindow;
	int ans_end=endWindow;
	int ans_length=ans_end-ans_start+1;

	while(startWindow<=source.length() - requiredCharacters){
		char removedChar=source[startWindow];
		sourceMap[source[startWindow]]--;
		if( patternMap[source[startWindow]]>sourceMap[source[startWindow]]){
			matchedCharacters--;
		} 
		startWindow++;
		while(endWindow<source.length() and 
		  matchedCharacters<requiredCharacters){
			endWindow++;
			sourceMap[source[endWindow]]++;
			if(source[endWindow]==removedChar){
				matchedCharacters++;
			}
		}
		if(matchedCharacters==requiredCharacters){
			if(endWindow - startWindow +  1 <ans_length){
				ans_length=endWindow - startWindow +  1;
				ans_start=startWindow;
				ans_end=endWindow;
			}
		}
	}

 	return source.substr(ans_start,ans_end-ans_start+1);
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		string A = "xiEjBOGeHIMIlslpQIZ6jERaAVoHUc9Hrjlv7pQpUSY8oHqXoQYWWll8Pumov89wXDe0Qx6bEjsNJQAQ0A6K21Z0BrmM96FWEdRG69M9CYtdBOrDjzVGPf83UdP3kc4gK0uHVKcPN4HPdccm9Qd2VfmmOwYCYeva6BSG6NGqTt1aQw9BbkNsgAjvYzkVJPOYCnz7U4hBeGpcJkrnlTgNIGnluj6L6zPqKo5Ui75tC0jMojhEAlyFqDs7WMCG3dmSyVoan5tXI5uq1IxhAYZvRQVHtuHae0xxwCbRh6S7fCLKfXeSFITfKHnLdT65K36vGC7qOEyyT0Sm3Gwl2iXYSN2ELIoITfGW888GXaUNebAr3fnkuR6VwjcsPTldQSiohMkkps0MH1cBedtaKNoFm5HbH15kKok6aYEVsb6wOH2w096OwEyvtDBTQwoLN87JriLwgCBBavbOAiLwkGGySk8nO8dLHuUhk9q7f0rIjXCsQeAZ1dfFHvVLupPYekXzxtWHd84dARvv4Z5L1Z6j8ur2IXWWbum8lCi7aErEcq41WTo8dRlRykyLRSQxVH70rUTz81oJS3OuZwpI1ifBAmNXoTfznG2MXkLtFu4SMYC0bPHNctW7g5kZRwjSBKnGihTY6BQYItRwLUINApd1qZ8W4yVG9tnjx4WyKcDhK7Ieih7yNl68Qb4nXoQl079Vza3SZoKeWphKef1PedfQ6Hw2rv3DpfmtSkulxpSkd9ee8uTyTvyFlh9G1Xh8tNF8viKgsiuCZgLKva32fNfkvW7TJC654Wmz7tPMIske3RXgBdpPJd5BPpMpPGymdfIw53hnYBNg8NdWAImY3otYHjbl1rqiNQSHVPMbDDvDpwy01sKpEkcZ7R4SLCazPClvrx5oDyYolubdYKcvqtlcyks3UWm2z7kh4SHeiCPKerh83bX0m5xevbTqM2cXC9WxJLrS8q7XF1nh";
		string B = "dO4BRDaT1wd0YBhH88Afu7CI4fwAyXM8pGoGNsO1n8MFMRB7qugS9EPhCauVzj7h"; 
		

		//A="ADOBECODEBANC";
		//B="ABC";
		A="w";
		B="o";
		string ans = getSubstringHavingPattern(B,A);
		cout<<endl<<"Ans = "<<ans; 
		ans = getMinimumWindowSubstringhavingPattern(B,A);
		cout<<endl<<"Ans = "<<ans; 
		ans = getSubstringHavingPattern2(B,A);
		cout<<endl<<"Ans = "<<ans; 
		
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
