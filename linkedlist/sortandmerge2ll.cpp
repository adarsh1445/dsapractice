#include<iostream>
using namespace std;

struct node{
   int data;
   node* next;
};
void split(node* head , node*& front ,node*& back);
node* sortmerge(node * a,node* b);

void mergesort(node*& headref){
       
     node* head = headref;

     if( (head == NULL) || (head->next == NULL) ){
           return;
     }

     node* a;
     node* b;

     split(head,a,b);

     mergesort(a);
     mergesort(b);
      
      headref  =  sortmerge(a,b);

}

void split(node* head , node*& front ,node*& back){

    node* source = head;
    node* slow = source;
    node* fast = source->next;

    while(fast != NULL){
         fast = fast->next;

         if(fast != NULL){
             slow = slow->next;
             fast = fast->next;
         }
    }

     front = source;
     back = slow->next;
     slow->next = NULL;

}

node* sortmerge(node * a,node* b){
         node* result = NULL;

         if(a == NULL){
             return (b);
         }else if (b == NULL)
         {
             return (a);
         }


         if(a->data <= b->data){

                result = a;
                result->next = sortmerge(a->next,b);
         }

         else{
             result = b;
             result->next = sortmerge(a,b->next);
         }

         return (result);
}
void removedups(node*& t){

    node* current = t;
    node* next_next;

    if(current == NULL){
        return ;
    }

    while(current->next != NULL){

        if(current->data == current->next->data){
                  
                  next_next = current->next->next;
                  free(current->next);
                  current->next = next_next;
        }else{
            current  =  current->next;
        }
    }
}

node* smwithoutdups(node*& a, node*& b){
    node* t = sortmerge(a,b);

    removedups(t);

    return t;
}

void inserta(node*& head,int data){

        node* newnode = new node();
    node* last = head;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }

    while(last->next != NULL){
       last = last->next;
    }
    
     last->next = newnode;
    return;
}


void print(node*& head){

    

     while (head!=NULL)
     {
          cout<<head->data;
          head = head->next;
     }
     
}



 int main(){
            
        node* head = NULL;
        node* head1 = NULL;
        node* t = NULL;
        node* u = NULL;
         int num,te,m;
         cin>>te;
          for(int i = 0 ; i < te ; i++){
         cin>>num;
         
       
         for(int i = 0 ; i < num ; i++){
               int data;
               cin>>data;
               inserta(head,data);
         }
         cin>>m;
         
          for(int i = 0 ; i < m ; i++){
               int data;
               cin>>data;
               inserta(head1,data);
         }

          

           mergesort(head);
           mergesort(head1);

           t = sortmerge(head,head1);
             print(t);
           
          }
 }