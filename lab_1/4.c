#include<stdio.h>

int main(){
    
    int a,b,c,l;
    printf("Enter the 1st num: ");
    scanf("%d",&a);
    printf("Enter the 2nd num: ");
    scanf("%d",&b);
    printf("Enter the 3rd num: ");
    scanf("%d",&c);
    
    l=a;
    if(b>=l){
        l=b;
    }
    if(c>=l){
        l=c;
    }
    printf("the largest element is: %d",l);

    return 0;
}