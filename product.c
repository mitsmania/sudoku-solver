#include<stdio.h>
int product(int a,int b){
    int z=0;
    z=a*b;
    return z;
}
int main(){
int a=0;
scanf("%d",&a);
int b=0;
scanf("%d",&b);
product(a,b);
printf("%d",product(a,b));




    return 0;
}