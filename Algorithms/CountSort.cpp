#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int *a = new int[N+1];
    int max=-1000000;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        if(max<a[i]){
            max=a[i];
        }
    }
    int *res=new int[max+1];
    for(int i=1;i<=max;i++){
        res[i]=0;
    }
    for(int i=1;i<=N;i++){
        res[a[i]] =res[a[i]] +1 ;
    }
    cout<<endl;
    for(int i=1;i<=max;i++){
        for(int j=1;j<=res[i];j++){
            cout<<i<<" ";
        }
    }    
    return 0;
}
