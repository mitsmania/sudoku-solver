#include<stdio.h>
#include<math.h>
int power(int n,int m){
    if(m==0)return 1;
    return n*power(n,m-1);
}
int main(){
    int n=0;
    scanf("%d",&n);
    int m=0;
    scanf("%d",&m);
    power(n,m);
    printf("%d",power(n,m));
    return 0;
}