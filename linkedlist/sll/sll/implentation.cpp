#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* link;
};

void print(node* n){
    while(n != NULL){
        cout<<n->data;
        n = n->link;
        cout<<"\n";
    }
}

void push(node *&head_ref){
      
      node* newnode = new node();
      newnode->data = 90;
      newnode->link = head_ref;     
      head_ref = newnode;
   
}
void deletea(node*& head_ref,int val){
          
           
      if(head_ref == NULL){
          cout<<"ELEMENTS NOT FOUND IN LL";
          return;
      }

      if(head_ref->data==val){
          node* temp = head_ref;
           head_ref = head_ref->link;
          delete(temp);
          return;
      }

      deletea(head_ref->link, val);

}
void insertafter(node* prenode){
     node* newnode = new node();
     newnode->data = 99;
     newnode->link = prenode->link;
     prenode->link = newnode;
}


void append(node** a){
     node* newnode = new node();
     node* last = *a;
     newnode->data = 56;
     newnode->link = NULL;
     if(*a == NULL){
         *a = newnode;
     }
     while(last->link != NULL){
         last = last->link;
     }
     last->link =  newnode;
}


int main(){
    node* head,*sec,*tri = NULL;
    head = new node();
     sec = new node();
      tri = new node();
    head->data = 11;
    head->link = sec; 
    sec->data = 13;
    sec->link = tri;
    tri->data = 15;
    tri->link = NULL;
     push(head);

     insertafter(head->link);

     append(&head);

     deletea(head,13);

    print(head);




 return 0;
}