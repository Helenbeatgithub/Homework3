/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int search(int array[], int size, int target)
{
    for(int i=0; i < size; i++)
        if(array[i] == target)
            return i;
    return -1;
}


void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%i", array[i]);
        if(i != size - 1){
            printf(" ");
        }
    }
    printf("\n");
}


int toBinary(int num){
    int binary = 0, factor = 1;
    
    while(num){
        binary += (num % 2)*factor;
        num /= 2;
        factor *= 10;
    }
    
    return binary;
}

int toDecimal(int num) {
    int decimal = 0, base = 1, rem;

    while (num > 0) {
        rem = num % 10;
        decimal = decimal + rem * base;
        num = num / 10 ;
        base = base * 2;
    }

    return decimal;
}

void revertArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = toDecimal(array[i]);
    }
}

void revertTarget(int* target){
    *target = toDecimal(*target);
}


void convertArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = toBinary(array[i]);
    }
}


void convertTarget(int* target){
    *target = toBinary(*target);
}

void printTarget(int target){
    printf("%i\n", target);
}

int main(){
    
    int size, target;
    
    printf("Input array size:\n");
    scanf("%d", &size);
    
    int *array = malloc(size * sizeof(*array));
    
    
    if(!array){
        printf("There was a problem with malloc.");
        exit(EXIT_FAILURE);}
    
    
    printf("Input elements of the array:\n");
    for(int i = 0; i<size; i++){
    scanf("%d", &array[i]);
    }
    
    printf("Input target:\n");
    scanf("%d", &target);
    
    //int N = sizeof(array) / sizeof(array[0]);
    
    //function call
    int result = search(array, size, target);
    
    printf("The array:\n");
    printArray(array, size);
    
    printf("The target:\n");
    printf("%d", target);
    
    convertArray(array, size);
    printf("\nConverted array:\n");
    printArray(array, size);
    
    printf("Converted target:\n");
    convertTarget(&target);
    printTarget(target);
    
    
    (result == -1)
    ? printf("Element is not present in array.")
    : printf("Search result: \n%d", result);
    
    revertArray(array, size);
    revertTarget(&target);
    
    printf("\nOriginal array:\n");
    printArray(array, size);
    
    printf("Original target:\n");
    printTarget(target);
    
    free(array);
    
    return 0;
}
