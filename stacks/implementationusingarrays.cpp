#include <iostream>
using namespace std;

#define MAX 1000
int top = -1;
int stack[MAX];

void push(int data){
     if(top>MAX){
         cout<<"STACK OVERFLOW";
         return;
     }
    
      stack[++top] = data;
       cout << data << " pushed to stack\n";
       return;
}

int pop(){

      if(top<0){
          cout<<"STACK UNDERFLOW";
          return 0;
      }
       
       int x = stack[top--];
       return x;
}

int peek(){
    if(top<0){
          cout<<"STACK EMPTY";
          return 0;
    }
     
     int x = stack[top];
       return x;

}


int main()
{
    
    push(10);
    push(20);
    push(30);
    cout << pop() << " Popped from stack\n";
  
    cout<<"Elements present in stack : ";
    while(top!=-1)
    {
        
        cout<<peek()<<" ";
       
        pop();
    }

    return 0;
}