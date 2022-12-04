vector<int> Solution::flip(string A) {
   vector<int> ANS;
    if(A.length()==0) return ANS;
    map<char,int> m;
    for(int i=0;i<A.length();i++){
        m[A[i]]++;
    }
    if(m['0']==0) return ANS;
    int startPointer=-1;  
    int ansStartPointer=-1; 
    int ansEndPointer=-2; 
    int sum=0;
    int maxSum=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='1'){
            sum-=1;
        }else{
            sum+=1;
            if(startPointer==-1){

                startPointer=i;
                //cout<<endl<<"startPointer="<<startPointer;
            }
        }
        if(sum<0){
            sum=0;
            startPointer=-1;
        }
        if(startPointer!=-1){
           // cout<<endl<<"sum->"<<sum<<"::maxSum->"<<maxSum;
            if(sum>maxSum){
                maxSum=sum;
                //if((ansEndPointer-ansStartPointer)<(i-startPointer)){
                    ansStartPointer=startPointer;
                    ansEndPointer=i;  
                  //  cout<<endl<<"ansStartPointer->"<<ansStartPointer<<"::ansEndPointer->"<<ansEndPointer; 
                //}
            }
        }
    }
    if(ansEndPointer-ansStartPointer+1>0){
        ANS.push_back(ansStartPointer+1);
        ANS.push_back(ansEndPointer+1);
    } 
    return ANS;
    
}
