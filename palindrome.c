#include<stdio.h>
int x=0;
int reverse(int n){
    while(n>0){
        int a=n%10;
        n=n/10;
       x=x*10+a; 
    }
    return x;
}
int main(){
    int n=0;
    scanf("%d",&n);
    reverse(n);
    if(n==x){
        printf("palindrome");
    }
    else{
        printf("not a palindrome");
    }
    return 0;
}