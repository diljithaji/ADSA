#include<stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateArray(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - 1);
}


int main(){
    int n,i,k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d",&k);
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter the %d elements\n",n);
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Original array\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    rotateArray(a, n, k);

    printf("\nRotated array by %d positions: ", k);
    for (int i= 0;i<n;i++) {
        printf("%d ", a[i]);
    }


    return 0;
}