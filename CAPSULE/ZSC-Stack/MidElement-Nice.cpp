#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
}


struct Node {
	int val;
	Node *prev,*next;
	Node(int x) {
		val = x;
		prev = next = NULL;
	}
};
vector<int> solve(vector<vector<int> > &A) {
	vector<int>  ans;
	Node *HEAD=new Node(-1);
	Node *TAIL=new Node(-1);
	HEAD->next = TAIL;
	TAIL->prev = HEAD;
	Node *MIDDLE = HEAD;
	int size=0;
	for(int i=0;i<A.size();i++){
		if(A[i][0]==1){
			Node * newNode = new Node(A[i][1]); 
			newNode->prev=TAIL->prev;
			TAIL->prev->next=newNode;
			newNode->next = TAIL;
			TAIL->prev=newNode;
			size++;
			if(size<=2){
				MIDDLE = newNode;
			}else if (size%2==0){
				MIDDLE=MIDDLE->next;
			}
         } else if(A[i][0]==2){ // pop the top elemtn and return it
         	if(size==0 or HEAD->next == TAIL){
         		ans.push_back(-1);
         	}else{
         		ans.push_back(TAIL->prev->val);
         		Node* tmp = TAIL->prev->prev;
         		TAIL->prev=tmp;
         		tmp->next=TAIL;
         		size--;
         		if(size==1) MIDDLE=HEAD->next;
         		if(size==2) MIDDLE=HEAD->next->next;

         		if(size>2 and size%2!=0)
         			MIDDLE=MIDDLE->prev;
         	}
         } else if(A[i][0]==3){ // return middle eelem 
         	if(size==0 ){
         		ans.push_back(-1);
         	}else{

         		if(i==86)
         			cout<<"\n size = "<<size<<":"<<TAIL->prev->val;
         		cout<<"\n size = "<<size<<":"<<TAIL->prev->prev->val;

         		ans.push_back(MIDDLE->val);
         	}
         } else  if(A[i][0]==4){ 
         	if(size==0){
         		HEAD->next=TAIL;
         		TAIL->prev=HEAD;
         	}	
         	else {

         		Node* t = MIDDLE->next;

         		t->prev=MIDDLE->prev;

         		///if(i==10){
         		cout<<"\n entered.."<<MIDDLE->val<<":size="<<size;
         		//	break;
         		//} 

         		MIDDLE->prev->next=t;

         		size--;
         		if(size==1) MIDDLE=HEAD->next;
         		else 
         			if (size==2) MIDDLE=HEAD->next->next;
         		else  if(size>0 and size%2==0){
         			MIDDLE=t;
         		}else  if(size>0 and size%2!=0){
         			MIDDLE=t->prev;
         		}
         		
         	}
         } else{
         	Node* ttmp=HEAD;
         	cout<<endl<<"============";
         	while(ttmp){
         		cout<<ttmp->val<<" ";
         		ttmp = ttmp->next;
         	}
         	cout<<endl<<"============";
         }
     }

     return ans;
 }


 int main(){
 	clock_t begin = clock();
 	file_i_o();
 	int TC=1;
	//cin>>TC;
 	while(TC--){
 		int tot;
 		cin>>tot;
 		vector<vector<int>> V;
 		while(tot--){
 			int x,y;
 			cin>>x>>y;
 			vector<int> vv(2);
 			vv[0]=x;
 			vv[1]=y;
 			V.push_back(vv);
 		}
 		vector<int> ANS = solve(V);
 		cout<<endl<<"--------\n";
 		for(int a:ANS){
 			cout<<a<<" ";
 		}
 	}
	 #ifndef ONLINE_JUDGE 
 	clock_t end = clock();
 	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
 	return 0;
 }
