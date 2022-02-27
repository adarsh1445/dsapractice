#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node* next;
};

node* inserta(node*& root){
    
    node* newnode = new node();
     node* last = root;
    cin>>newnode->data;
    newnode->next = NULL;
    
    if(root == NULL){
        root = newnode;
        return root;
    }
    
    while(last->next!=NULL){
        last = last->next;
    }
     
     last->next = newnode;
    return last;
}

node* insertat(node*& root,int data,int pos){
    node* newnode = new node();
    node* last = root;
    newnode->data = data;
    newnode->next = NULL;
    
    while(pos!=1){
        last = last->next;
        pos--;
    }
     node* temp = last->next;
     last->next = newnode;
     last->next->next = temp;
    
     return last;
}
node* reverse(node* head) {
     
     node* rhead = NULL;

     while(head!=NULL){
         node* newnode = new node();
         newnode->data = head->data;
          newnode->next = rhead;
         rhead = newnode;

         head = head->next;

     }

    return rhead;

}

void display(node* root){
   if(root == NULL){
       return;
   }
    
    display(root->next);
    cout<<root->data;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     node* root = NULL;
     int a,pos,ele,t;
    
     cin>>a;
    

          root = inserta(root);
     for(int i=1; i<a;i++){
         inserta(root);
     }
         
     reverse(root);
       display(root);
 
     


     
    return 0;
}
