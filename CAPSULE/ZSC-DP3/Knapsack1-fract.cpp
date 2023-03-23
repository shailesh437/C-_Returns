int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    multimap<double,pair<int,int>,greater<double>> m;
    for(int i=0;i<A.size();i++){
    	m.insert(make_pair(A[i]*1.0/B[i],make_pair(A[i],B[i])));
    }
    int filledCap=0;
    double val=0.0;
    for(auto it:m){ 
    	pair<int,int> p=it.second; 
    	if(filledCap+ p.second<C){
    		val+=(p.first)*1.0;	
    		filledCap+=p.second;
    	}else{
    		int balanceCap=C-filledCap;  
    		double possibleAddition =balanceCap*(1.0/((p.second*1.0)/(p.first*1.0))); 
    		if(possibleAddition>0.0){
    				val+=possibleAddition; 
    		}
    		break;
    	}  
    }
    val*=100;
    return (int)val;
}
