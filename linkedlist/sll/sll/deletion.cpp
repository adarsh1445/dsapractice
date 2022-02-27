#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

void delet(node*& head_ref,int pos){
            node* temp,*a;
            temp = head_ref;
            int i;
        if(pos==1){
            temp = head_ref;
            head_ref = head_ref->link;
            delete(temp);
            return;
        }
        for (int i = 2; temp != NULL && i < pos-1 ; i++) {
      temp = temp->link;
   }

        if (temp == NULL || temp->link == NULL) {
      return;
   }
   struct node *link = temp->link->link;
   free(temp->link);
   temp->link = link;

}


node* reverse(node*& head){
        
       node* rhead = NULL;

       while (head != NULL)
       {
           node* newnode = new node();
           newnode->data = head->data;
           newnode->link = rhead;
           rhead = newnode;

           head = head->link;223
           3.
       }
       
       return rhead;
    

}

void append(node*& head){
          
    node* newnode = new node();
    node* last = head;
    cin>>newnode->data;
    newnode->link = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }

    while(last->link != NULL){
       last = last->link;
    }
    
     last->link = newnode;
    return;
}

void print(node*& head_ref){
        
        while(head_ref!=NULL){
            cout<<head_ref->data;
            head_ref = head_ref->link;
        }
    
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

        head =  reverse(head);

       print(head);


      
          
        

}