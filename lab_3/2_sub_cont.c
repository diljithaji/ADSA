#include<stdio.h>

void sub_array(int arr[],int n,int s){
    int index=0;
    int sum=0;
    int i;

    for(i=0;i<n;i++){
        sum+=arr[i];

        while(sum>s && index<=i){
            sum-=arr[index];
            index++;
        }
        if(sum==s){
            printf("Sum %d exists from index %d to %d",s,index,i);
            return;
        }
        
    }
    
        printf("There doesn't exists such a sub array.");
}

int main(){

    int n,i,s;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter the %d elements\n",n);
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter the sum need to be found: ");
    scanf("%d",&s);

    sub_array(a,n,s);

    return 0;
}