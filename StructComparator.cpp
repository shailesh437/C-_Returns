#include<bits/stdc++.h>
using namespace std;
typedef struct Student{
int prelim_marks;
int final_marks;
}student;
bool compare(student s1,student s2){
    int s1_tot = s1.final_marks+s1.prelim_marks;
    int s2_tot = s2.final_marks+s2.prelim_marks;
    if(s1_tot<=s2_tot){
        return false;
    }
    return true;
}
int main(){
    student s[5];
    for(int i=0;i<5;i++){
        s[i].prelim_marks = (i+1)*10;
        s[i].final_marks = (i+1)*20;
    }
    sort(s,s+5,compare);
    cout<<endl<<"After sorting ==="<<endl;
    for(int i=0;i<5;i++){
        cout<<endl<<s[i].prelim_marks<<" "<<s[i].final_marks;
    }
    return 0;
}
