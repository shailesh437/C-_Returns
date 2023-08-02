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

/*
Concept 
1+2+3+...+n = n(n+1)/2

Ex:
15 
1,2,3,4,5
4,5,6
7,8

a+(a+1)+(a+2)+....+(a+L) ...L terms 

therefore 

N = a+(a+1)+(a+2)+....+(a+L)
  = a*(L+1)+L(L+1)/2

a*(L+1) = N - L(L+1)/2
So, a = N/(L+1) - L/2 

if we get a as pure integer then its valid case 
max range of L can be 1+2+3+...number of terms which do not exceed N





*/


int solve(int A) {

	 if(A<=2) return 1;
   int sum=0;
	 int L=0;
	 for(int i=1;i<=A;i++){
	 	sum+=i;
	 	if(sum>A){
	 		break;
	 	}
	 	L++;
	 }
	 int ans=1;
	 for(int l=1;l<L;l++){
	 	double possible_a = A*1.0/((l+1)*1.0) - (l*1.0)/2.0;
	 	if(possible_a==(int)possible_a){
	 		ans++;
	 	} 
	 }

    return ans;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A=100000000;
		int ans = solve(A);
		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
