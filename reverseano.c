#include<stdio.h>
int reverse(int n){
if(n==0)return 0;
while(n>0){
int a=n%10;
n=n/10;
printf("%d",a);
}   
}
int main(){
    int n=0;
    scanf("%d",&n);
    reverse(n);
    return 0;
}