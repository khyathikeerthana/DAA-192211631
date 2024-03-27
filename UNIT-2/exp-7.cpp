#include <stdio.h>

// Structure to hold both min and max values
struct MinMax {
    int min;
    int max;
};

// Function to find minimum and maximum values using Divide and Conquer
struct MinMax findMinMax(int arr[], int left, int right) {
    struct MinMax result, leftResult, rightResult;
    int mid;

    // Base case: If there is only one element
    if (left == right) {
        result.min = arr[left];
        result.max = arr[right];
        return result;
    }

    // If there are two elements
    if (right == left + 1) {
        if (arr[left] > arr[right]) {
            result.min = arr[right];
            result.max = arr[left];
        } else {
            result.min = arr[left];
            result.max = arr[right];
        }
        return result;
    }

    // Divide the array into two halves
    mid = (left + right) / 2;
    leftResult = findMinMax(arr, left, mid);
    rightResult = findMinMax(arr, mid + 1, right);

    // Merge the results of two halves
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int arr[100], arr_size;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &arr_size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    struct MinMax result = findMinMax(arr, 0, arr_size - 1);

    printf("Minimum element in the array: %d\n", result.min);
    printf("Maximum element in the array: %d\n", result.max);

    return 0;
}

