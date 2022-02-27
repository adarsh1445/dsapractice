#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;    
};
 void push(node*& root,int data){
     node* newnode = new node();
     newnode->data = data;
     newnode->next = root;
     root = newnode;
     cout << root->data << " pushed to stack\n";
 }

 int pop(node*&root){
        if(root==NULL){
           cout<<"STACK IS EMPTY";
           return 0;
        }
        node* temp = root;
        root = root->next;
        int popped = temp->data;
        delete(temp);
        return popped;
 }

 int peek(node*& root){
     if(root==NULL){
         cout<<"STACK IS NULL";
         return 0;
     }
    return root->data;

 }
int main(){
     node* root = NULL;

     push(root, 10);
    push(root, 20);
    push(root, 30);

     while(root!=NULL)
    {
        cout<<peek(root)<<" "<<"\n";
       
        pop(root);
    }
}
