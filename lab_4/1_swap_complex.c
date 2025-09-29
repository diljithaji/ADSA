#include<stdio.h>
struct complex{
    float r;
    float i;
};

void swap(struct complex *c1, struct complex *c2){
    struct complex temp;

    temp=*c1;
    *c1=*c2;
    *c2=temp;

}
int main(){
    struct complex num1,num2;

    printf("Enter the details of num1\n");
    printf("Enter the real part of the 1st num: ");
    scanf("%f",&num1.r);
    printf("Enter the imaginary part of 1st number: ");
    scanf("%f",&num1.i);

    printf("Enter the details of the num2\n");
    printf("Enter the real part of the 2nd num: ");
    scanf("%f",&num2.r);
    printf("Enter the imaginary part of 2nd number: ");
    scanf("%f",&num2.i);

    printf("\n--- Before Swap ---\n");
    printf("Number 1 (C1): %.2f + i%.2f\n", num1.r, num1.i);
    printf("Number 2 (C2): %.2f + i%.2f\n", num2.r, num2.i);

    swap(&num1, &num2);

    printf("\n--- After Swap ---\n");
    printf("Number 1 (C1): %.2f + i%.2f\n", num1.r, num1.i);
    printf("Number 2 (C2): %.2f + i%.2f\n", num2.r, num2.i);


    return 0;
}