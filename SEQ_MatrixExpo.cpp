#include<iostream>
#include<vector>
#define MOD 1000000000
#define ll long long int
using namespace std;
ll n,k,t;
vector<ll> a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> MAT_A,vector<vector<ll>> MAT_B){
vector<vector<ll>> MAT_C(k+1,vector<ll>(k+1));
for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
        for(int x=1;x<=k;x++){
            MAT_C[i][j]=(MAT_C[i][j]+(MAT_A[i][x]*MAT_B[x][j])%MOD)%MOD;
        }
    }
}
return MAT_C;
}

vector<vector<ll>> Pow(vector<vector<ll>> A,int powerValue){
    if(powerValue==1)
        return A;
    if(powerValue & 1)
        return multiply(A,Pow(A,powerValue-1));
    vector<vector<ll>> X = Pow(A,powerValue/2);
        return multiply(X,X);
}

ll compute(ll n){
if(n<=k)
    return b[n-1];
vector<vector<ll>> T(k+1,vector<ll>(k+1));
for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
        if(i<k){
            if(j==i+1)
                T[i][j]=1;
            else
                T[i][j]=0;
        continue;
        }
        T[i][j]=c[k-j];
    }
}
T=Pow(T,n-1);
ll res=0;
for(int i=1;i<=k;i++){
    res= (res + (T[1][i]*b[i-1])%MOD)%MOD;
}
return res;
}

int main(){
int TC;
cin>>TC;
while(TC--){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>t;
        b.push_back(t);
    }
    for(int i=0;i<k;i++){
        cin>>t;
        c.push_back(t);
    }
    cin>>n;
    cout<<compute(n)<<endl;
    b.clear();
    c.clear();
}

return 0;
}

