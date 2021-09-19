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

int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	//int mat[]={40,20,30,10,30}; //ANS=26000
	//int mat[]={10, 20, 30, 40, 30} ; //ANS = 30000
	int mat[]={ 1, 2, 3, 4 };
	int matsize=sizeof(mat)/sizeof(mat[0]);
	int c[matsize+1][matsize+1];
	/*for(int i=0;i<=matsize;i++){
		c[i][i]=0;
	}*/
	memset(c,0,sizeof(c));
	for(int L=1;L<matsize;L++){
		int j = L;
		for(int i=0;i<matsize&&j<matsize;i++,j++){
				c[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				c[i][j]=min(c[i][j],
							c[i][k]+c[k+1][j]+mat[i-1]*mat[k]*mat[j]);
			}
		}
	}
	cout<<endl;
	for(int i=0;i<matsize;i++){
		for(int j=0;j<matsize;j++){
			cout<<setw(8)<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\nFINAL ANS = "<<c[1][matsize-1];

	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
