#include<iostream>
using namespace std;
typedef struct nodes{
    int info;
    nodes *next;
}node;

node* ll_getNode(){
    node *newNode;
    cout<<"\n Allocating Memory for a new node\n";
    if((newNode = (node*)malloc(sizeof(node))) == NULL){
        cout<<"\n Not enough Memory ";
        exit(1);
    }
    return newNode;
}

void ll_delNode(node *delNode){
    cout<<"\n Releasing memory for against deleting node\n";
    free(delNode);
}

int main(){
    int ll_menu(); 
    void ll_insert(node *&);// Call by reference 
    void ll_delete(node *&);
    void ll_update(node *);
    void ll_search(node *); //Call by value 
    void ll_display(node *);
    void ll_quit();
    int choice = 0;
    node *start = NULL;
    while(choice != 6){
        choice =ll_menu() ;
        switch (choice)
        {
        case 1:
            ll_insert(start);
            break;
        case 2:
            ll_delete(start);
            break;
        case 3:
            ll_update(start);
            break;
        case 4:
            ll_search(start);
            break;
        case 5:
            ll_display(start);
            break;
        case 6:
            ll_quit();
            break;        
        }
    }
}

int ll_menu(){
    int choice = 0 ;
    while(choice<1 || choice > 6 ){
        cout<<endl<<" M A I N M E N U..........."<<endl;
        cout<<" 1 > INSERT OPERATION"<<endl;
        cout<<" 2 > DELETE OPERATION"<<endl;
        cout<<" 3 > UPDATE OPERATION"<<endl;
        cout<<" 4 > SEARCH OPERATION"<<endl;
        cout<<" 5 > DISPLAY OPERATION"<<endl;
        cout<<" 6 > QUIT OPERATION"<<endl;
        cout<<"--- Please enter your choice ::";
        cin>>choice;
    }
    return choice;
}

void ll_insert(node *&st){
    int newinfo, searchinfo;
    node *ptr, *newNode;
    cout<<endl<<" Please enter info for the new Node : "<<endl;
    cin>>newinfo;
    newNode = ll_getNode();
    newNode->info = newinfo;
    newNode->next = NULL;
    if(st == NULL){
        cout<<endl<<" LInkedlIst does not pre-exist.."<<endl;
        cout<<endl<<"Creating the linkedlist with new node"<<endl;
        st = newNode;
    }else{
        cout<<"LinkedlIst is  pre-existing.."<<endl;
        cout<<endl<<" Please enter the searching info: ";
        cin>>searchinfo;
        ptr = st;
        while(ptr != NULL && ptr->info != searchinfo){
            ptr = ptr->next;
        }
        if(ptr == NULL){
            cout<<endl<<" Unsuccessfull searching !!!"<<endl;
            cout<<endl<<" So the new node will be prepended.."<<endl;
            newNode->next = st;
            st = newNode;
        }else{
            cout<<"\n Successfull Searching!!!!\n";
            newNode->next=ptr->next;
            ptr->next = newNode;
        }        

    }
    cout<<"\n INSERT OPERATION HAS BEEN COMPLETED SUCCESSFULLY!!!\n";
}

void ll_delete(node *&st){
    int searchinfo;
    node *prevptr,*ptr;
    if(st==NULL){
        cout<<"\n LinkedList does not pre-exist \n";
        cout<<"\n Delete opearion cannot be carried out\n";
    }else{
        cout<<"\n LinkedList exists \n";
        cout<<"\n Please enter the info to be searched ::";
        cin>>searchinfo;
        if(st->info == searchinfo){
            cout<<"Searching info matching has been found at the first node ...\n";
            ptr = st;
            st = st->next;
            ll_delNode(ptr);
        }else{
            cout<<"\n Search info has not been found at start node\n";
            prevptr=st;
            ptr=st->next;
            while(ptr!=NULL && ptr->info != searchinfo){
                prevptr=ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL){
                cout<<"\n Search info not found \n";
                cout<<"\n Deletion Operation cannot be carried out \n";                
            }else{
                cout<<"\n Search operation successfull!!\n";
                prevptr->next=ptr->next;
                ll_delNode(ptr);
            }
        }
    }
    cout<<"\n DELETE OPERATION HAS BEEN COMPLETED SUCCESSFULLY!!!\n";
}

void ll_update(node *st){
    int searchinfo,updateinfo;
    node *ptr;
    if(st == NULL){
        cout<<"\n Linked List does not pre-exist\n";
        cout<<"\n Update opeartion cannot be carried out\n";
    }else{
        cout<<"\n Enter the search info\n";
        cin>>searchinfo;
        cout<<"\n Linked List is pre-existing...\n";
        ptr=st;
        while(ptr!=NULL && ptr->info != searchinfo){
            ptr = ptr->next;
        }
        if(ptr == NULL){
            cout << "\n Unsuccessfull searching of the search info";
        }else{
            cout<<"\n Successfull searching against the search\n";
            cout<<"\n updating the search info wiht the update info\n";
            cout<<"\n please enter the updateinfo::";
            cin>>updateinfo;
            ptr->info = updateinfo;
        }
    }
    cout<<"\n UPDATE OPERATIOn COMPLETED SUCCESSFULLY!!!...";
}


void ll_search(node *st){
    int searchinfo,updateinfo;
    node *ptr;
    if(st == NULL){
        cout<<"\n Linked List does not pre-exist\n";
        cout<<"\n Search opeartion cannot be carried out\n";
    }else{
        cout<<"\n Enter the search info\n";
        cin>>searchinfo;
        cout<<"\n Linked List is pre-existing...\n";
        ptr=st;
        while(ptr!=NULL && ptr->info != searchinfo){
            ptr = ptr->next;
        }

        if(ptr == NULL){
            cout << "\n Unsuccessfull searching of the search info";
        }else{
            cout << "Successful searching against the search info..." << endl;
        }
    }
    cout<<"\n UPDATE OPERATIOn COMPLETED SUCCESSFULLY!!!...";
}

void ll_display(node *st) {
    node *ptr;

    if (st == NULL) {
        cout << "Linked list does not pre-exist..." << endl;
        cout << "Display operation can not be carried out..." << endl;
    } else {
        cout << "Linked list is pre-existing..." << endl;
        cout << "Dislaying the current content of the linked list..." << endl;
        ptr = st;
        cout<<endl<<"==============================================================="<<endl;
        while (ptr != NULL) {
            cout << "Node Address: " << ptr << ", Info: " << ptr->info 
                                     << " and Link: " << ptr->next << "..." << endl;
            ptr = ptr->next;
        }
    }
    cout<<"==============================================================="<<endl;
    cout << "DISPLAY operation has been completed successfully..." << endl;     
}

void ll_quit(){
    cout<<"\n End of Porgram ...\n";
    cout<<"\n Goood Byeeee!!";
}
