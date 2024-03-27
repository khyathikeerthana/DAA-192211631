#include <stdio.h>

int findLargest(int arr[], int size) {
    int largest = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    return largest;
}
int main() {
    int arr[100]; 
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, size);

    printf("The largest element of the array is: %d\n", largest);

    return 0;
}

