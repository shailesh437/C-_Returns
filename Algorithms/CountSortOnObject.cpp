#include<bits/stdc++.h>
using namespace std;
typedef struct student{
    int score;
    string name;
};
vector<student> occArr[1000];
void CountSortOnObject(student arr[],int start,int end){
    int mx = -10000;
    for(int i=start;i<=end;i++){
        mx=max(mx,arr[i].score);
    }
    
    for(int i=start;i<=end;i++){
        occArr[arr[i].score].push_back(arr[i]);
    }
    int idx=start;
    for(int i=0;i<=mx;i++){
        for(int j=0;j<occArr[i].size();j++){
                arr[idx]=occArr[i][j];
                idx++;
        }
    }

}
int main(){
    student arrStudent[4]={{4,"FOUR"},{3,"THREE"},{2,"TWO"},{1,"ONE"}};
    CountSortOnObject(arrStudent,0,3);
    for(int i=0;i<4;i++){
        cout<<endl<<arrStudent[i].score<<" : "<<arrStudent[i].name;
    }
    return 0;
}
