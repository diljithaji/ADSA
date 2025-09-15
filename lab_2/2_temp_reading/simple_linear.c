#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of temperature readings: ");
    scanf("%d", &n);

    float temperatures[n];
    printf("Enter the %d temperature readings:\n", n);
    for (i = 0; i < n; i++) {
        printf("Reading %d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    float max_temp = temperatures[0];

    for (i = 1; i < n; i++) {
        if (temperatures[i] > max_temp) {
            max_temp = temperatures[i];
        }
    }

    printf("The maximum temperature for the week is: %.2f\n", max_temp);

    return 0;
}