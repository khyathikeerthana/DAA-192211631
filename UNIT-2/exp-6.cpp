#include <stdio.h>
#include <limits.h>

// Function to calculate the time taken to finish the race
int minTimeToFinishRace(int tires[][2], int numTires, int changeTime, int numLaps) {
    int minTime = INT_MAX;

    // Iterate over each type of tire
    for (int i = 0; i < numTires; i++) {
        int time = 0;

        // Simulate the race for each tire
        for (int lap = 0; lap < numLaps; lap++) {
            int lapTime = 0;

            // Calculate the time taken for the current lap
            for (int j = 0; j <= lap; j++) {
                lapTime += tires[i][0] * power(tires[i][1], j);
            }

            // Add change time if it's not the last lap
            time += lapTime + (lap < numLaps - 1 ? changeTime : 0);
        }

        // Update the minimum time
        minTime = min(minTime, time);
    }

    return minTime;
}

// Function to calculate power
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    // Example input
    int tires[][2] = {{2,3},{3,4}};
    int changeTime = 5;
    int numLaps = 4;
    int numTires = sizeof(tires) / sizeof(tires[0]);

    // Calculate and print the minimum time to finish the race
    printf("Minimum time to finish the race: %d\n", minTimeToFinishRace(tires, numTires, changeTime, numLaps));

    return 0;
}
