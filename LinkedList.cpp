// CREATED BY MUHAMMAD HANAN ASGHAR
// PYTHONIST
// DATA SCIENTIST
#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *Next;
}*Start;
class LinkedList{
  public:
    LinkedList(){
      Start = NULL;
    }
    void AddNode(int data){
      Node *node = new Node();
      node->data = data;
      if (Start == NULL){
        Start = node;
      }
      else{
        Node *temp;
        temp = Start;
        while(temp->Next != NULL){
          temp = temp->Next;
        }
        temp->Next = node;
      }
    }
    void Display(){
      Node *temp;
      temp = Start; 
      while(temp != NULL){
        cout<<temp->data<<" - ";
        temp =  temp->Next;
      }
      }
      void AtStart(int data){
        Node *node = new Node();
        node->data = data;
        if (Start == NULL){
          Start = node;
        }
        else{
          node->Next = Start;
          Start = node;
        }
      }
      void AtPosition(int key,int data){
        Node *node = new Node();
        node->data = data;
        if (Start == NULL){
          cout<<"No Node Present";
        }
        else{
          Node *temp,*temp2;
          temp = Start;
          while (temp->data != key){
            temp = temp->Next;
          }
          temp2 = temp->Next;
          temp->Next = node;
          node->Next = temp2;
        }
      }
      void Modify(int data,int key){
        Node *temp = Start;
        while(temp->data != key){
          temp = temp->Next;
        }
        temp->data = data;
      }
      void SortIt(){
        Node *temp;
        temp = Start;
        int val;
        while(temp->Next!=NULL){
          if (temp->data > temp->Next->data){
            val = temp->data;
            temp->data = temp->Next->data;
            temp->Next->data = val;
          }
          temp = temp->Next;
        }
      }
    void DeleteStart(){
      Node *temp;
      temp = Start;
      Start = Start->Next;
      delete temp;      
    }
    void AtEndDelete(){
      Node *temp,*temp2;
      temp = Start;
      while(temp->Next!=NULL){
        temp2 = temp;
        temp = temp->Next;
      }
      temp2->Next = NULL;
      delete (temp);
      
    }
    void DeleteAtPostion(int key){
      Node *temp,*temp2;
      temp = Start;
      while(temp->data != key){
        temp2 = temp;
        temp = temp->Next;
      }
      temp2->Next = temp->Next;
      delete (temp);
    }
    void Reverse(){
      Node *prev,*next = NULL;
      Node *curr = Start;
      while(curr!=NULL){
        next = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = next;
      }
      Start = prev;
    }
};
int main() {
  cout << "LinkedList!\n";
  LinkedList l;
  l.AddNode(10);
  l.AddNode(4);
  l.AddNode(35);
  l.AddNode(11);
  cout<<endl;
  l.Display();
  l.Reverse();
  cout<<endl;
  l.Display();
}
