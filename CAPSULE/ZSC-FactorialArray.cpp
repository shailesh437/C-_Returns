int getPrimeCountTill(int X,
                      int rangeStart, 
                      vector<bool> &isPrime,
                      int ppc
                      ){
     int val=0;
     for(int i=rangeStart;i<=X;i++)
        if(isPrime[i])
            val++;
     return val+ppc;  
}
int powMod(int base,int power,int MOD){
    if(power==1) return base;
    if(power==0) return 1;
    int comm=powMod(base,power/2,MOD);
    long long int ans=1;
    ans=(comm%MOD*comm%MOD)%MOD;
    ans%=MOD;
    if(power & 1){
        ans*=base;
        ans%=MOD;
    }
    return (int)ans;
} 
int Solution::solve(vector<int> &A) {
     //max A = 1000000
    vector<bool> isPrime(1000000+1,true);
    for(int i=2;i<=sqrt(1000000);i++){
        for(int j=i*i;j<=1000000;j+=i){
            isPrime[j]=false;
        }
    }

    int maxELem=INT_MIN;
    int MOD=1e9+7;
    for(int i=0;i<A.size();i++){
        if(A[i]>maxELem){
            maxELem=A[i];
        }
    } 
    map<int,int> m; 
    sort(A.begin(),A.end());
    int startRange=2;
    int prevPrimeCount=0;
    for(int i=0;i<A.size();i++){
        int primesCount=getPrimeCountTill(A[i],
                                          startRange,
                                          isPrime,
                                          prevPrimeCount); 
        m[primesCount]++;
        startRange=A[i]+1;
        prevPrimeCount=primesCount;
    } 
    int ANS=0;
    //cout<<endl<<"------------------\n";
    int cnt_1=0;
    for(auto it=m.begin();it!=m.end();it++){           

            if(it->second==0 or it->first ==0 ) continue;
            if(it->second==1) {
                ANS++;
                ANS%=MOD;
                cnt_1++;
                continue;    
            } 
            ANS+=(powMod(2,it->second,MOD)-1); 
            ANS%=MOD;
            //ANS-=1;    
                
    } 
    return ANS;
}
