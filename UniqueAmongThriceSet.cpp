#include<iostream>
#include<math.h>
using namespace std;
int getUnique(int x[],int n){
	int result_bit_pos[64]={0};
	int ptr_result_bit_pos=0;
	for(int i=0;i<n;i++){
		int temp = x[i];
		ptr_result_bit_pos=0;
		while(temp){
			result_bit_pos[ptr_result_bit_pos]+=temp&1;
			temp=temp>>1;
			ptr_result_bit_pos++;
		}
	}

	while(ptr_result_bit_pos>=0){
			result_bit_pos[ptr_result_bit_pos]%=3;
			ptr_result_bit_pos--;
	}
	int final_ans=0;
	for(int i=0;i<=63;i++)
        if(result_bit_pos[i])
            final_ans+=result_bit_pos[i]*pow(2,i);
	return 	final_ans;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<getUnique(a,n);
	return 0;
}

