#include<iostream>
#include<set>
using namespace std;
int main(){
    void display(multiset<int> mset);
    multiset<int> mset1,mset2;
    multiset<int> :: iterator it;
    for(int i=1;i<=10;i++){
        mset1.insert(2*i);
    }
    cout<<"\n Displaying contents of mset1 ::";
    display(mset1);
    for(int i=1;i<=10;i++){
        mset2.insert(3*i);
    }
    cout<<"\n Displaying contents of mset2 ::";
    display(mset2);

    cout<<"\n Before erasing count of mset1 = "<<mset1.size();
    mset1.erase(5);
    cout<<"\n after erasing count of mset1 = "<<mset1.size();

    cout << "Performing swap operation on entire sets..." << endl;
	mset1.swap(mset2);
	cout << "Elements of multiset1 after swap operation" << endl;
    display(mset1);
    cout << "Elements of multiset2 after swap operation" << endl;
    display(mset2);
    cout << "Applying clear operation on multiset2..." << endl;
	mset2.clear();
	bool chk = mset2.empty();
	if (chk == 1) {
		cout << "Multiset2 is empty" << endl;
	} else {
		cout << "Multiset2 is not empty" << endl;
	}

    return 0;
}

void display(multiset<int> mset){
 multiset<int> :: iterator it;
 cout<<"\n----------------------------------\n";
 for(it = mset.begin();it!=mset.end();it++){
     cout<<"\t  "<<*it;
 }   
 cout<<"\n----------------------------------\n";
}
