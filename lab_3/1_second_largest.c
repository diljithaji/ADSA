#include<stdio.h>

int main(){
    int n,i,j;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the %d numbers:\n",n);
    for(i=0;i<n;i++){
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    int large, sec_large;

    if(arr[0]>arr[1]){
        large=arr[0];
        sec_large=arr[1];
    }
    else{
        large=arr[1];
        sec_large=arr[0];
    }

    for(j=2;j<n;j++){
        if(arr[j]>large){
            sec_large=large;
            large=arr[j];
        }
        else if(arr[j]>sec_large && arr[j]<large){
            sec_large=arr[j];
        }

    }

    printf("Second largest element: %d",sec_large);
/*
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
*/
    return 0;
}