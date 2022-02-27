#include<iostream>
using namespace std;
int a[10000];
int d;

int getparent(int a){
    int t;
    t = (a-1)/2;
    return t;
}

void inserta(int data,int t){
       if(t==0){
           a[0]=data;
           return;
       }
            
           int i = getparent(t);     

            if(a[(2*i)+1] =='\0')
            {
                a[(2*i)+1] = data; 
                return;
            }
            else if (a[(2*i)+2] =='\0')
            {
               a[(2*i)+2] = data;
            }    
       }


 void print(){
             for(int i=0;i<=d;i++){
           if(a[i] != '\0'){
                      cout<<a[i];
           }
   }
 }
int main(){
   
   cout<<"enter the number of elements";
   cin>>d;
   for(int i=0;i<=d;i++){
       int e;
       cin>>e;
       inserta(e,i);
   }
    print();
}