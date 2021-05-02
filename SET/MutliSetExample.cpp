#include<iostream>
#include<set>
using namespace std;
int main(){
    void display(multiset<int>);
    multiset<int> mset;
    multiset<int> ::iterator it;
    cout<<"\n Adding 1 to 5 in Multiset::\n";
    for(int i=0;i<6;i++){
        mset.insert(i*10);
    }
    cout<<"\n----------MAIN------------\n";
    for(it=mset.begin();it!=mset.end();it++){
        cout<<"\t "<<*it;
    }
    cout<<"\n----------------------\n";
    display(mset);
    cout<<endl<<"Trying to add 50 again....";
    mset.insert(50);
    display(mset);
    cout<<"\n Size of MultiSet==="<<mset.size();
    cout<<"\n MAX-Size of MultiSet==="<<mset.max_size();
    bool checkEmpty = mset.empty();
    if(checkEmpty==1){
        cout<<"\n MultiSet is Empty\n";
    }else{
        cout<<"\n MultiSet is Non-Empty\n";
    }

    //assigning elements to another multiset
    multiset<int> mset2(mset.begin(),mset.end());

    //showing elelments of copied multiset
    cout<<"\n Elements of new multiset::";
    for(it = mset2.begin();it!=mset2.end();it++){
        cout<<"\t "<<*it;
    }
    cout<<endl;
    return 0;
}

void display(multiset<int> mset){
    multiset<int> ::iterator it;
    it = mset.begin();
    cout<<"\n------DISPLAY FUNCTION----------------\n";
    for(;it!=mset.end();it++){
        cout<<"\t "<<*it;
    }
    cout<<"\n--------------------------------------------\n";
}
