// Hashing by division Method


#include <stdio.h>
#include <stdlib.h>
#define max 10



int Search(int *A,int v){
    if (A[v%10]==v){
        return v%10;
    }
    return -1;
}

void print(int*A){
    for (int i=0;i<max;i++){
        printf("%d\t",A[i]);
    }
}
int main(){
    static int array[max];
    int x;
    printf("Enter the number of keys : ");
    scanf("%d",&x);
    for (int i=0;i<x;i++){
        int n;
        scanf("%d",&n);
        array[n%10]=n;
    }
    printf("Hashmap is completed\n");
    int value;
    printf("Enter the numbers you want to search : ");
    scanf("%d", &value);
    if (Search(array,value)>=0){
        printf("The key of value is %d\n",Search(array,value));

    }
    else{
        printf("The value not found\n");
    }
    
    print(array);
    return 0;
}