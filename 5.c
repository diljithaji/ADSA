#include<stdio.h>

int main(){

    char o;
    double n1,n2;

    printf("Enter 1st numbers: ");
    scanf("%lf",&n1);
    printf("Enter 2nd numbers: ");
    scanf("%lf",&n2);

    printf("Select an operator (+,-,*,/): ");
    scanf(" %c",&o);

    switch (o){
        case '+':
            printf("The value is: %.2lf",n1+n2);
            break;
        case '-':
            printf("The value is: %.2lf",n1-n2);
            break;
        case '*':
            printf("The value is: %.2lf",n1*n2);
            break;
        case '/':
            if(n2>0){
                printf("The value is: %.2lf",n1/n2);
            }
            else{
                printf("the denominator cannot be zero");
            }
            break;

    default:
        printf("Enter proper operators");
        break;
    }


    return 0;
}