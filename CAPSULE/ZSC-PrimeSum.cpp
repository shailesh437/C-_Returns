vector<int> Solution::primesum(int A) {
 
vector<bool> prime(A+1,true);
for(int i=2;i<=sqrt(A);i++){
    if(prime[i]){
        for(int j=i*i;j<=A;j+=i)
            prime[j]=false;
    }
}

map<int,int> M;
vector<int> ANS;
for(int i=2;i<=A;i++){
    if(prime[i] and prime[A-i]){ 
         ANS.push_back(i);
         ANS.push_back(A-i);
         return ANS;
    }
} 
return ANS;
}
