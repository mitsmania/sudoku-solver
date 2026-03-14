#include<stdio.h>
int sum(int n){
    int sum=0;
    while(n>0){
    int a=n%10;
    n=n/10;
     sum=a+sum;
    }
    printf("%d",sum);
}
int main(){
    int n=0;
    scanf("%d",&n);
    sum(n);
    return 0;
}