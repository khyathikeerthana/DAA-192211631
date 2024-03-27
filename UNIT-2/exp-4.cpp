#include <stdio.h>

void findMinMax(int arr[], int size) {
    if (size <= 0) {
        printf("List is empty.\n");
        return;
    }

    int min = arr[0];
    int max = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i]; 
        }
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }

    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);
}

int main() {
    int arr[] = {3, 7, 2, 8, 1, 9, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMinMax(arr, size);

    return 0;
}

