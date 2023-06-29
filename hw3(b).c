#include <stdio.h>
#include <stdlib.h>

// Function for binary search
int binarySearch(int array[], int start, int end, int target) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        // If target is at mid
        if (array[mid] == target)
            return mid;

        // If target is smaller than mid, it can only be present in left subarray
        if (array[mid] > target)
            return binarySearch(array, start, mid - 1, target);

        // Else the target can only be present in right subarray
        return binarySearch(array, mid + 1, end, target);
    }

    // If target is not in array
    return -1;
}

// Function for bubble sort
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size-1; i++)      
        for (int j = 0; j < size-i-1; j++) 
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Main function
int main() {
    int size, target;
    
    printf("Input array size:\n");
    scanf("%d", &size);
    
    int *array = malloc(size * sizeof(int));
    
    if(!array){
        printf("There was a problem with malloc.");
        exit(EXIT_FAILURE);
    }
    
    printf("Input elements of the array:\n");
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
    
    printf("Input target:\n");
    scanf("%d", &target);
    
    printf("The array:\n");
    printArray(array, size);
    
    printf("The target:\n");
    printf("%d\n", target);

    bubbleSort(array, size);
    
    printf("The sorted array:\n");
    printArray(array, size);
    
    int result = binarySearch(array, 0, size - 1, target);
    
    printf("Search result:\n");
    printf("%d\n", result);
    
    free(array);
    
    return 0;
}

