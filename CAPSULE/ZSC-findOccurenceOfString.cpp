int Solution::solve(string A) {
    bool valid=true;
	int occ=0;
    string B="bob";
	while(valid){ 
		if(A.find(B)!=string::npos){
			int index=A.find(B);
			occ++;
			A=A.substr(index+B.length());
		}else{
			valid=false;
		}
	}
    return occ;
}
