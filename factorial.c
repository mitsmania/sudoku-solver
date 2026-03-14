#include<stdio.h>
int  factorial(int n){
    if(n==0)return 1;
     return n*factorial(n-1);
}

int main(){
int n=0;
scanf("%d",&n);
factorial(n);

printf("%d",factorial(n));


    return 0;
}