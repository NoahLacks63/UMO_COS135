/*
Name: Noah Lacorazza
Desc: Reads through a csv file and organizes all the data by mpg
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold every car's data
struct car {
    char car[100];
    double mpg;
    int cylinders;
    double hp;
    double weight;
    int model;
    char origin[100];
};

int main() {
    // Opens the cars.csv file
    FILE *file = fopen("cars.csv", "r");

    // Line buffer
    char line[1024];
    // How many rows we have
    int rows = 0;

    // Count rows
    while (fgets(line, sizeof(line), file)) rows++;
    // How many rows we have without headers
    int data_rows = rows - 2;

    // Reset file to start
    fclose(file);
    file = fopen("cars.csv", "r");

    // Skip first 2 lines
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    // Holds each car
    struct car *cars = malloc(data_rows * sizeof(struct car));
    // Holds each car in 
    struct car **organized = malloc(data_rows * sizeof(struct car *));

    // What row are we on
    int count = 0;
    // Reads all lines in the csv
    while (fgets(line, sizeof(line), file) && count < data_rows) {
        
        char *ptr = strtok(line, ",");
        if (ptr) strcpy(cars[count].car, ptr);

        ptr = strtok(NULL, ",");
        if (ptr) cars[count].mpg = atof(ptr);

        ptr = strtok(NULL, ",");
        if (ptr) cars[count].cylinders = atoi(ptr);

        ptr = strtok(NULL, ",");
        if (ptr) cars[count].hp = atof(ptr);

        ptr = strtok(NULL, ",");
        if (ptr) cars[count].weight = atof(ptr);

        ptr = strtok(NULL, ",");
        if (ptr) cars[count].model = atoi(ptr);

        ptr = strtok(NULL, ",");
        if (ptr) {
            ptr[strcspn(ptr, "\r\n")] = 0;
            strcpy(cars[count].origin, ptr);
        }

        organized[count] = &cars[count];
        
        count++;
    }

    // Organizes cars by mpg
    for (int i = 0; i < count - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < count; j++) {
            if (organized[j]->mpg < organized[max_idx]->mpg) {
                max_idx = j;
            }
        }
        struct car *temp = organized[max_idx];
        organized[max_idx] = organized[i];
        organized[i] = temp;
    }

    
    // Prints results
    printf("Most efficient car: %s\n\tMPG: %.2f, Cylinders: %d, HP: %.2f, Weight: %.2f, Model: %d, Origin: %s\n", 
        organized[count-1]->car, 
        organized[count-1]->mpg, 
        organized[count-1]->cylinders, 
        organized[count-1]->hp, 
        organized[count-1]->weight, 
        organized[count-1]->model, 
        organized[count-1]->origin

    );
    printf("Least efficient car: %s\n\tMPG: %.2f, Cylinders: %d, HP: %.2f, Weight: %.2f, Model: %d, Origin: %s\n", 
        organized[0]->car, 
        organized[0]->mpg, 
        organized[0]->cylinders, 
        organized[0]->hp, 
        organized[0]->weight, 
        organized[0]->model, 
        organized[0]->origin
    );

    // Cleans up
    fclose(file);
    free(cars);
    free(organized);
    return 0;
}