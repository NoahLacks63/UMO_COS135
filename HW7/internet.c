
#include <stdio.h>
/*
 the header file with the dataset should be inclded as #include "internet.h"
 note that user defined header files should be included with "" not with <>
 make sure the internet.h is in the same directory (folder)

 more info: The " " here are used to instruct the preprocessor to look into the working directory (if not found in the current directory, it will look in the standard library directory in gcc). If you are using " " you need to ensure that the header file you created is saved in the same directory in which you will save the C file that uses this header file.
 */
#include "internet.h"

float* monthlyAverage(float* arr);
void overallAverage();

int main() {
    float monthlyAverages[12];

    monthlyAverage(monthlyAverages);

    for (int i = 0; i < 12; i++) {
        printf("Average internet consumption in month %d is %.2f GB\n", i + 1, monthlyAverages[i]);
    }

    overallAverage();

    return 0;
}

float* monthlyAverage(float* arr) {
    float sum = 0.0;
    int count = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            sum += internet[j][i];
            count++;
        }

        arr[i] = sum / count;
        sum = 0.0;
        count = 0;
    }
    return arr;
}

void overallAverage() {
    float arr[12];
    float* averages = monthlyAverage(arr);
    float sum = 0.0;

    for (int i = 0; i < 12; i++) {
        sum += averages[i];
    }

    printf("Overall average internet consumption is %.2f GB\n", sum / 12);
}