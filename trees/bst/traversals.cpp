#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

 node* newnode(int value){
         node* newnode = new node();
         newnode->data = value;
         newnode->right=newnode->left=NULL;
         
          return newnode;
         
 }




node* inserta(node*& root, int data){
         if(root==NULL){
             
             return newnode(data);
         }

         if(data>root->data){
                root->right = inserta(root->right,data);
         }else{
             root->left = inserta(root->left,data);
         }
           return root;
}
struct node* minnode(node*& root){
        node* current = root;
        while(current->left != NULL){
            current = current->left;
        }

        return current;
}

struct node* deletea(node*& root, int data){
    
        if(root == NULL){
            return root;
        }

        if(data < root->data )
        {
            root->left = deletea(root->left,data);
            
        }
        else if (data > root->data)
        {
            
            root->right = deletea(root->right,data);
            
        }

        else{
            if(root->right==NULL && root->left==NULL){
                    return NULL;
            }

            else if(root->left==NULL){
                struct node* temp = root->right;
                free(root);
                return temp;
            }

            else if(root->right == NULL){
                struct node* temp = root->left;
            free(root);
            return temp;
            }
        

          struct node* temp = minnode(root->right);

          root->data = temp->data;

          root->right = deletea(root->right, temp->data);
        }
        
        return root;

}

void inorder(node*&root){
   
            if (root != NULL) {
        inorder(root->left);
        cout<<root->data<<',';
        inorder(root->right);
    }
}


void preorder(node*&root){
   
            if (root != NULL) {
        
        cout<<root->data<<',';
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node*&root){
   
            if (root != NULL) {
        
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<',';
    }
}




int main(){

         node* root = NULL;
          root = inserta(root,25);
           
           inserta(root,15);
           inserta(root,50);
           inserta(root,10);
           inserta(root,4);
           inserta(root,12);
           
           inserta(root,22);
           inserta(root,18);
           inserta(root,24);
           inserta(root,35);
           inserta(root,70);
           inserta(root,31);
           inserta(root,44);
           inserta(root,66);
           inserta(root,90);
            
            cout<<"INORDER ITEMS: "<<'\n';
           inorder(root);

          deletea(root,50);
            cout<<"INORDER ITEMS: "<<'\n';
           inorder(root);
           
          // cout<<"PREORDER ITEMS: "<<'\n';
          // preorder(root);
         //  cout<<"POSTORDER ITEMS: "<<'\n';
         //  postorder(root);
          
return 0;

}
