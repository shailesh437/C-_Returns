//Product of any subaraay should not repeat

int colorful(int A) {
     vector<int> A_digits;
    while(A){
        int d=A%10;
        A_digits.push_back(d);
        A=A/10;
    }
    map<int,int> m;
    reverse(A_digits.begin(),A_digits.end());
    /*cout<<endl;
    for(int x: A_digits) cout<<x<<" ";
    cout<<endl;*/
    
    for(int i=0;i<A_digits.size();i++){
        m[A_digits[i]]++;
        int x=A_digits[i];
        for(int j=i+1;j<A_digits.size();j++){
            x*=A_digits[j];
            m[x]++;
        }
    }
    //cout<<endl;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>1) return 0;
    }
    return 1;

}
