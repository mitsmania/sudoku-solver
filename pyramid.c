#include<stdio.h>
void pyramid(int n){
    for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){
        printf("*");
}
printf("\n"); 
    }
    return ;
}


int main(){
  int n=0;
  scanf("%d",&n);
  pyramid(n);  
    return 0;
}