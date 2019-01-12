//linked list question
/*#CommentsMatter : Commenting should be used for every executable statement that does not perform trivial functions to non-CS person. 

Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 
-> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/
#include<iostream>
using namespace std;
//using ll instead of linked list
//ll is basically the opration with node
//node is data type which contain both data and pointer
class node
{
   public:
   int data;
   node *next;
   public:
   node()
  {
      next=NULL;
  }
 };
//ll is basically rule to work upon nodes how we can work
// only  head is required to work upon and addition further
class ll
{
  public:
  node *head;
  node *tail;

 ll()
{
   head=NULL;
   tail=NULL;
}
// to operate we will have member function
void insert(int d)
{
   node *temp=new node;
   temp->data=d;
   if(head==NULL)
 {
    
    head=temp;
    head->next=NULL;
 }

else
{
   tail->next=temp;
   temp->next=NULL;
   
}
tail=temp;
}
//for removing element
void remove(int a)
{
  node *temp=new node;
  temp->data=a;
  node *current=head;
  while(current->next!=tail)
{
    current=current->next;
  
}
current->next=NULL;
temp=tail;
tail=current;
}
// to insert element at any desired position
int insertat(int pos,int h)
{
   node *temp=new node;
   temp->data=h;
   node *current=head;
  int i=1;
  while(i!=pos-1)
{
   current=current->next;
    i++;
}
current->next=temp;
temp->next=current->next;
}
//to count element
int countelement()
{
  node *current=head;
  int i=1;
  while(current->next!=NULL)

{
   current=current->next;
    i++;
}
return i;  
}
//display the element
void display()
{
  node *current=head;
  int i=1;
  while(current->next!=NULL)
{
   cout<<current->data<<"->";
   current=current->next;
}
}
//to delete at any position
void deletat(int k)
{
  node *current=head;
  node *curr=head;
  node *temp=new node;
int i=1;
while(i!=(k))
{
   curr=curr->next;
    i++;
}

//for deleting at any position first get the element before desired position and then point to the next element
while(i!=(k-1))
{
   current=current->next;
    i++;
}
current->next=curr->next;
temp=curr;
delete temp;
}

};
int main()
{
  ll l1;
// calling the function
  l1.insert(1);
  l1.insert(2);
  l1.insert(3);
  l1.insert(4);
  l1.insert(5);
  l1.display();
  l1.remove(4);
  l1.display();
 cout<<"\n total no. of element are:";
 cout<<l1.countelement();
  int a,b,v;
 cout<<"\n enter the position where want to delete:";
 cin>>a; 
 cout<<"\n enter the position where want to insert:";
 cin>>b;  
 cout<<"\n enter the element you want enter:";
 cin>>v;
 l1.insertat(b,v);
  l1.display();
 l1.deletat(a);
 l1.display();
 return 0;
}
