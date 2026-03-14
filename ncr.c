#include<stdio.h>
int ncr(int n,int r){
   int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*fact(n-1)
}
 return  fact(n)/(fact(n-r)*fact(r));

}
int main(){
int n=0;
scanf("%d",&n);
int r=0;
scanf("%d",&r);
 

ncr(n,r);
printf("%d",ncr(n,r));


    return 0;
}