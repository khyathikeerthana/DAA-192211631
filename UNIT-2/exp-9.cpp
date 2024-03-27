#include <stdio.h>
#include <stdlib.h>

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    return (ratio2 > ratio1) - (ratio2 < ratio1);
}

// Function to solve Fractional Knapsack problem using greedy approach
void fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Sort items based on their value-to-weight ratio in non-increasing order
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Final value of items in knapsack

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the next item doesn't exceed the capacity, add it completely
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else { // Otherwise, add a fraction of the next item to fill the knapsack
            int remainingCapacity = capacity - currentWeight;
            finalValue += (double)items[i].value / items[i].weight * remainingCapacity;
            break; // Knapsack is full, so break the loop
        }
    }

    printf("Maximum value in knapsack (using greedy approach): %.2lf\n", finalValue);
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}}; // Sample items
    int n = sizeof(items) / sizeof(items[0]); // Number of items
    int capacity = 50; // Capacity of knapsack

    fractionalKnapsack(items, n, capacity);

    return 0;
}

