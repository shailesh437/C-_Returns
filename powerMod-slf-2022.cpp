ll powMOD(ll base,ll power){
	//cout<<endl<<base<<"---"<<power<<endl;
	if(power==0){
		return 1;
	}
	if(power==1){
		return base;
	}
	ll ans=1;
	if(power&1){
		ans=base;
	}
	base = (base%MOD*base%MOD)%MOD;
	return (ans * powMOD(base,power/2))%MOD; 
}
