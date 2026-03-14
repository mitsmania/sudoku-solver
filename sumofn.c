#include<stdio.h>
int sum(int n){
    if(n==0)return 0;
    return sum(n-1)+n;
}
int main(){
int n=0;
scanf("%d",&n);
sum(n);
printf("%d",sum(n));



return 0;
}