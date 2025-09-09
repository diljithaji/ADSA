#include <stdio.h>

int main() {
    int units;
    double bill = 0.0;

    printf("Enter the units consumed: ");
    scanf("%d", &units);

    if (units<=100) {
        bill=units*5.0;
    }
    else if (units<=200) {
        bill=(100*5.0)+((units-100)*7.0);
    }
    else {
        bill=(100*5.0)+(100*7.0)+((units-200)*10.0);
    }

    printf("Total bill: %.2lfRs\n",bill);

    return 0;
}