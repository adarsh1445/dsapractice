#include<stdio.h>
#include<math.h>

int nod(int n){
    int cnt = 0;
    while(n>0){
    cnt++;
    n/=10;
    }
    return cnt;
}


int main(){
   int n;
   scanf("%d",&n);

   int nu[10000];
   int f = 0;
   int digits = nod(n);

   int powten = pow(10, digits - 1);
    for (int i = 0; i < digits - 1; i++) {
 
        int firstDigit = n / powten;
 
    
        int left  = ((n * 10) + firstDigit)
              - (firstDigit * powten * 10);
       

       nu[i] = left;

       f += 1;

        n = left;
    }

     int max = nu[0];
    int min  = nu[0];
     int diff = 0;
    for(int i=1; i<f; i++)
    {
      
        if(nu[i] > max)
        {
            max = nu[i];
        }

    /* If current element is smaller than min */
        if(nu[i] < min)
        {
            min = nu[i];
        }
    }
     diff = max - min;
    printf("%d",diff);

}