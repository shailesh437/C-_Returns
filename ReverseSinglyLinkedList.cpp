#include <iostream>

using namespace std;

typedef struct node
{
  int value;
  struct node *next;
} NODE;
NODE *head, *temp, *newnode;

NODE* reverse_BU(NODE * inpNode)
{
  if (inpNode->next == NULL)
    {
      head = inpNode;
      return inpNode;
    }
    NODE *prev = reverse_BU (inpNode->next);
    prev->next = inpNode;
    inpNode->next=NULL;
    return inpNode;
}
void  reverse(NODE * node_fn) {
  if (node_fn->next == NULL)
    {
     head = node_fn; return;}
     reverse (node_fn->next);
     node_fn->next->next = node_fn; node_fn->next = NULL;}
     void createSingeLinkedList ()
     {
     int numberOfNodes = 0;
     int nodeValue;
     cout << "Enter the number of nodes: ";
     cin >> numberOfNodes; if (numberOfNodes > 0)
     {
     head = (NODE *) malloc (sizeof (node));
     int nodeValue;
     cin >> nodeValue;
     head->value = nodeValue;
     head->next = NULL; numberOfNodes--; temp = head;}
     while (numberOfNodes--)
     {
     newnode = (NODE *) malloc (sizeof (node));
     cin >> nodeValue;
     newnode->value = nodeValue;
     newnode->next = NULL;
     temp->next = newnode; temp = newnode; temp->next = NULL;}
     }

     void display()
     {
     temp = head; cout << endl; while (temp != NULL)
     {
     cout << "  " << temp->value; temp = temp->next;}
     }

     int main()
     {
     createSingeLinkedList ();
     cout << endl << "Traversing the list:" << endl;
     display ();
     reverse (head);
     cout << endl << "Traversing the list in reverse{TD}:" << endl;
     display ();
     reverse (head);
     cout << endl << "Again reversing and Traversing the list:" << endl;
     display ();
     cout << endl << "Traversing the list in reverse{BU}:" << endl;
     reverse_BU(head); 
     display (); 
     return 0;
     }
