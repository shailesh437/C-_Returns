#include<bits/stdc++.h>
using namespace std;
/* Take a input number N
   Print count of numbers <=N divisible by {2,3,5}
*/

int getCountOfSetBits(int n){
	int count =0 ;
	while(n){
		n = n& (n-1);
		count++;
	}
	return count;
}
int main(){
	int p[] = {2,3,5};
	/* Approach : to find the count of numbers divisible by 2,3,5 
	   we need to check how many numbers are divisible by 2 + 
	   numbers divisible by 3  + numbers divisble by 5 
	   - [count of numbers divisble by (2,3) + (2,5) + (3,5) ]
       + [count of numbers divisible by all 3 i.e LCM of 2,3,5]
	    */
	int inp_Number;
	cout<<endl<<"Enter the upper limit: ";
	cin>>inp_Number;
	int n_prime = sizeof(p)/sizeof(p[0]);
	int subSets = (1<<n_prime) - 1;
	int ss = 1;
	int answer = 0;
	while(ss <= subSets){
		int denom = 1 ;
		int j=0;
		while(j<n_prime){
			if(1<<j & ss){
				denom*=p[j];
			}
			j++;
		}
		int countOfSetBits = getCountOfSetBits(ss);
		if(countOfSetBits & 1 ) {
			answer += inp_Number / denom; 
		}else{
			answer -= inp_Number / denom;
		}
		ss++;
	}
	cout<<endl<<"ANswer = "<<answer;
	return 0;
}
