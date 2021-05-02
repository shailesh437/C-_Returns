#include<iostream>
#include<map>
using namespace std;
int main(){
    void display(map<int,int>);
    map<int,int> map1;
    map<int,int> :: iterator it;
    for(int i=0;i<=5;i++){
        map1.insert(pair<int,int>(i,i*10));
    }
    display(map1);
    it=map1.begin();
    map1.insert(it,pair<int,int>(900,90000));
    cout<<" After having  iterator at beginning and inserting the largest key";
    display(map1);
    it=map1.end();
    cout<<" After having  iterator at End and inserting the smallest key";
    map1.insert(it,pair<int,int>(1,1));
    display(map1);
}
void display(map<int,int> mapp){
    map<int,int> :: iterator it;
    cout<<"\n-------DISPLAY START-----------------------------\n";
    for(it=mapp.begin();it!=mapp.end();it++){
        cout<<"\n Key =["<<it->first<<"] Value = ["<<it->second<<"]";
    }
    cout<<"\n-----------DISPLAY END-------------------------\n";
}
