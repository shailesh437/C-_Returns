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

ll solve(int s1_arr[],
	int s2_arr[],
	int s1,
	int s2){
	vector<int> ce;
	int s1ptr=0,s2ptr=0;

	while(s1ptr<s1 and s2ptr<s2){
		if(s1_arr[s1ptr]==s2_arr[s2ptr]){
			ce.push_back(s1_arr[s1ptr]);
			s1ptr++;s2ptr++;
		}
		while(s1_arr[s1ptr]<s2_arr[s2ptr] and s1ptr<s1)
		s1ptr++;
		while(s2_arr[s2ptr]<s1_arr[s1ptr] and s2ptr<s2)
		s2ptr++;
	}
	s2ptr=s2-1;
	s1ptr=s1-1;
	ll commele[ce.size()][2];
	ll maxSum=0;
	for(int j=ce.size()-1;j>=0;j--){
		ll tmpsum2=0;
		while(s2_arr[s2ptr]!=ce[j] and s2ptr>=0){
			tmpsum2+=s2_arr[s2ptr];
			s2ptr--;
		}
		ll tmpsum1=0;
		while(s1_arr[s1ptr]!=ce[j] and s1ptr>=0){
			tmpsum1+=s1_arr[s1ptr];
			s1ptr--;
		} 
		maxSum += max(tmpsum1,tmpsum2); 
	} 
	ll tmpsum1=0;
	while(s1ptr>=0) tmpsum1+=s1_arr[s1ptr--];
	ll tmpsum2=0;
	while(s2ptr>=0) tmpsum2+=s2_arr[s2ptr--];
	maxSum += max(tmpsum1,tmpsum2);

	ce.clear();
	return maxSum; 
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	int s1=1,s2=0; 
	while(1){		
		cin>>s1;	
		if(s1==0) break;
		int s1_arr[s1];
		for(int i=0;i<s1;i++)
			cin>>s1_arr[i];
		cin>>s2;
		int s2_arr[s2];
		for(int i=0;i<s2;i++)
			cin>>s2_arr[i];
		ll ans = solve(s1_arr,s2_arr,s1,s2);
		cout<<ans<<endl;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
