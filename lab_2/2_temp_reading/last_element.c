#include <stdio.h>

int maximum(int arr[], int n){
    if (n == 1){
        return arr[0];
    }
    int maxRest = maximum(arr, n - 1);
    if (arr[n - 1] > maxRest){
        return arr[n - 1];
    }
    else{
        return maxRest;
    }
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxi = maximum(arr, n);
    printf("Maximum Element : %d\n", maxi);
}