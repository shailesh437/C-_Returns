#include<iostream>
#include<vector>
#define ll long long int
#define MOD 1000000007
using namespace std;
vector<vector<ll>> multiply(vector<vector<ll>> &A,vector<vector<ll>> &B)
{
    vector<vector<ll>> AB(2,vector<ll>(2));
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            AB[i][j]=0;
            for(int x=0; x<2; x++)
            {
                AB[i][j]=(AB[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return AB;
}


vector<vector<ll>> powr(vector<vector<ll>> &A,int powerValue)
{
    if(powerValue==1)
        return A;
    if(powerValue & 1)
    {
        auto it = powr(A,powerValue-1);
        return multiply(A,it);
    }
    vector<vector<ll>> X = powr(A,powerValue/2);
    return multiply(X,X);
}

ll compute(long long n)
{
    if(n<=1)
        return 1;

    vector<vector<ll>> T(2,vector<ll>(2));
    T[0][0]=1;
    T[0][1]=1;
    T[1][0]=1;
    T[1][1]=0;
//display(T);
    T=powr(T,n-1);
//display(T);
    return T[0][0];
}


int main()
{
    int tc;
    long long  m,n;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        ll result=  compute(m+2)-compute(n+1) ;
        if(result<0)
        {
            result=(result+MOD)%MOD;
        }
        cout<<result<<"\n";
    }

    return 0;
}
