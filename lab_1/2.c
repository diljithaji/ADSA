#include<stdio.h>

int main(){

    int a,b,t;
    printf("Enter the 1st number: ");
    scanf("%d",&a);
    printf("\nEnter the 2nd number: ");
    scanf("%d",&b);
    
    t=a;
    a=b;
    b=t;
    
    printf("After swapping\n The 1st number: %d\n The 2nd number: %d",a,b);


    return 0;
}