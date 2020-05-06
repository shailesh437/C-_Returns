#include<iostream>
#include<vector>
#define ll int
using namespace std;
vector<ll> b,c,Sn;
ll k,mod;
vector<vector<ll>> multiply(vector<vector<ll>> &A,vector<vector<ll>> &B)
{
    vector<vector<ll>> AB(k+2,vector<ll>(k+2));
    for(int i=1; i<=k+1; i++)
    {
        for(int j=1; j<=k+1; j++)
        {
            AB[i][j]=0;
            for(int x=1; x<=k+1; x++)
            {
                AB[i][j]=(AB[i][j]+(A[i][x]*B[x][j])%mod)%mod;
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
    if(n<=k)
        return Sn[n-1];

    vector<vector<ll>> T(k+2,vector<ll>(k+2));
    vector<ll> F1(k+2);
    F1[1]=Sn[k-1];
    for(int i=1; i<=k; i++)
    {
        F1[i+1]=b[i-1];
    }
    for(int i=1; i<=k+1; i++)
    {
        for(int j=1; j<=k+1; j++)
        {
            if(i==1 && j==1)
            {
                T[i][j]=1;
                continue;
            }
            if((i==1 || i==k+1) && j>1)
            {
                T[i][j]=c[k+1-j];
                continue;
            }
            if(j==i+1)
            {
                T[i][j]=1;
                continue;
            }
            T[i][j]=0;
        }
    }
//display(T);
    T=powr(T,n-k);
//display(T);
    ll res=0;
    for(int i=1; i<=k+1; i++)
    {
        //ll temp = (T[1][i] * F1[i]) % mod;
        ll temp = ((T[1][i]%mod) * (F1[i]%mod))%mod ;
        //res = (res + temp)%mod;
        res = res + temp;
    }
    return res;
}


int main()
{
    int tc,t;
    long long  m,n;
    cin>>tc;
    while(tc--)
    {
        cin>>k;
        ll sum=0;
        for(int i=1; i<=k; i++)
        {
            cin>>t;
            b.push_back(t);
            sum+=t;
            Sn.push_back(sum);
        }
        for(int i=1; i<=k; i++)
        {
            cin>>t;
            c.push_back(t);
        }
        cin>>m>>n>>mod;
        //ll result= ( compute(n)-compute(m-1) ) % mod
        ll result=  compute(n)-compute(m-1) ;
        if(result<0)
        {
            result=(result+mod)%mod;
        }
        cout<<result<<"\n";
        b. clear();
        c.clear();
        Sn.clear();
    }

    return 0;
}
