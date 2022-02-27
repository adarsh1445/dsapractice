#include<iostream>
using namespace std;

struct  node
{
     int data;
     node* pre;
     node* next;
};

void append(node*& head_ref){
     node* newnode = new node();
     node* last = head_ref;
     cin>>newnode->data;
     newnode->pre = NULL;
     newnode->next = NULL;
     
     if(head_ref == NULL){
          newnode->pre = NULL;
          head_ref = newnode;
          return;
     }

     while(last->next != NULL){
         last = last->next;
     }

      last->next = newnode;
      newnode->pre = last;
      return;
}

 void push(node*& head_ref,int data){
       node* newnode = new node();
       newnode->data = data;
       newnode->pre = NULL;
       newnode->next = head_ref;
       head_ref = newnode;
        }

void insertafter(node* prev,int data){
       node* newnode =  new node();
       newnode->data = data;
       newnode->pre = prev;
       newnode->next = prev->next;
       prev->next = newnode; 
       
       if(newnode->next != NULL)
       {
            newnode->next->pre = newnode;
       }
       
       return;
}

void print(node*& head_ref){
        node* last;

       while(head_ref != NULL){
              cout<<head_ref->data;
              head_ref=head_ref->next;
              last = head_ref;
       }

       while (last!=NULL)
       {
              cout<<last->data;
              last = last->pre;
       }

  
       

}

  void delee(node*& head_ref,int val){
        node* temp = head_ref;
      if(val == head_ref->data){
         
          head_ref = head_ref->next;
          delete(temp);
          return;
      }
     
      while(val != temp->data){
            temp = temp->next;
      }
      
      temp->pre->next = temp->next;
      temp->next->pre = temp->pre;

      delete(temp);
      return;
  }
int main(){
    node* head =NULL;
        int a,v;
        cout<<"Enter the number of items";
        cin>>a;
        v =a;
        while(a != 0){
            append(head);
            a--;
        }
        delee(head,8);
       print(head);
      
}