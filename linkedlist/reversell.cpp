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
node* reverse(node*& head) {
    
    if(head !=NULL || head->next != NULL )
      return head;
    
     auto res = reverse(head->next);
     
     head->next->next = head;
     head->next = NULL;
     
     return res;
    

}

void display(node* root){
   while (root != NULL)
     {
          
          cout<<root->data;
        
          root = root->next;
        
     }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     node* root = NULL;
     int a,pos,ele,t;
     cin>>t;
     cin>>a;
     for(int j=0; j<t;j++){
     root = inserta(root);
     for(int i=1; i<a;i++){
         inserta(root);
     }
          reverse(root);
       display(root);
     }
 
     


     
    return 0;
}
