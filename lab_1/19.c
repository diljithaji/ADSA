#include <stdio.h>

int sum_d(int n){
    if (n == 0){
        return 0;
    }
    else {
        return (n % 10)+sum_d(n / 10);
    }
}

int main(){
    int number, sum;

    printf("Enter num: ");
    scanf("%d", &number);

    if (number<0){
        number=-number;
    }
    sum=sum_d(number);

    printf("The sum of the digits is: %d\n",sum);

    return 0;
}