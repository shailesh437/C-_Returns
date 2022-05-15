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
bool isPalindrome(string s){
	int L = s.length()-1;
	for(int i=0,j=L; i<=L and j>=0; i++,j--){
		if(s[i] != s[j]){
			return false;
		}
	}
	return true;
}
int naiveMethod(string s){
	bool flag;
	string orig_s = s;
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if(isPalindrome(s)){
			flag=1;
			break;
		}
		cnt++;
		s.erase(s.begin()+s.length()-1);		
	}

	if(flag) {
		return cnt;
	}
	return orig_s.length()-1;
}
int KMP_method(string s){

	string reversedStr = s;
	reverse(reversedStr.begin(),reversedStr.end());
	string newConcatenatedString = s+"$"+reversedStr;
	cout<<"\n newConcatenatedString = "<<newConcatenatedString<<endl;
	int len = 0;
	string s2 = newConcatenatedString;
	vector<int> lps(s2.length(),0);
	lps[0]=0; // lps[0] is always 0
	int i=1;
	while(i<s2.length()){
		if(s2[i]==s2[len]){
			len++;
			lps[i]=len;
			i++;			
		}else{
			if(len !=0){
				len = lps[len-1];
				//NO CHANGE IN i
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
	/*int lps_at_lastIndex  = lps[s2.length()-1];
	return s.length() - lps_at_lastIndex;*/
	return s.length()-lps.back();
} 

vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);
 
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int getMinCharToAddedToMakeStringPalin(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
 
    // Get concatenation of string, special character
    // and reverse string
    string concat = str + "$" + revStr;
 
    //  Get LPS array of this concatenated string
    vector<int> lps = computeLPSArray(concat);
 
    // By subtracting last entry of lps vector from
    // string length, we will get our result
    cout<<endl<<lps.back()<<endl;
    return (str.length() - lps.back());
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	cin>>TC;
	while(TC--){
		string s = "AACECAAAA";
		//int minChars = naiveMethod(s); 
		//cout<<"\nFinal Ans = "<A<minChars;
		int minChars = KMP_method(s);
		cout<<"\nFinal Ans = "<<minChars;
		//cout << getMinCharToAddedToMakeStringPalin(s);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
