int gcd(int A,int B){
    if(B==0) return A;
    return gcd(B,A%B);
}

map<int,int> getPrimeFactorsOnly(int inp){
    int freq=0;
    map<int,int> factors;
    while(!(inp%2)){
        inp=inp/2;
        freq++;
    }
    if(freq>0)
        factors[2]=freq;
    for(int i=3;i<=sqrt(inp);i++){
        freq=0;
        while(!(inp%i)){
            inp=inp/i;
            freq++;
        }
        if(freq>0)
            factors[i]=freq;
    
    }
    if(inp>2)
        factors[inp]=1;
    return factors;    
}

int Solution::cpFact(int A, int B) {
    if(gcd(A,B)==1) return A;
    map<int,int> af = getPrimeFactorsOnly(A);
    map<int,int> bf = getPrimeFactorsOnly(B);
     
    vector<int> afactV; 
    for(auto it=af.begin();it!=af.end();it++){
        if(it->second>0)
        afactV.push_back(it->first);
    }
    reverse(afactV.begin(),afactV.end());
    int ans=1;
    for(int i=0;i<afactV.size();i++){
        auto it = bf.find(afactV[i]);
        if(it==bf.end()){
            ans*= pow(afactV[i],af[afactV[i]]);
        }
    }
    return ans;
}
