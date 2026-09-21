#include <stdio.h>

#define BEEF_PRICE 12.95
#define CHICKEN_PRICE 10.95
#define VEGAN_PRICE 8.95
#define GRATUITY_RATE 0.18
#define ROOM_TAX_RATE 0.065

#define ROOM1_SEATS 200
#define ROOM2_SEATS 150
#define ROOM3_SEATS 100
#define ROOM4_SEATS 30

#define ROOM1_PRICE 250
#define ROOM2_PRICE 200
#define ROOM3_PRICE 100
#define ROOM4_PRICE 50

#define LEFT_ALIGNMENT 15
#define CENTER_ALIGNMENT 8

int main() {
	int beefMeals = 0;
	int chickenMeals = 0;
	int veganMeals = 0;
	int total = 0;

	float roomCost = 0;
	float beefCost = 0;
	float chickenCost = 0;
	float veganCost = 0;
	float gratuity = 0;
	
	//gathers user inputs
	printf("Beef meals: ");
	scanf(" %d", &beefMeals);

	printf("Chicken meals: ");
	scanf(" %d", &chickenMeals);

	printf("Vegan meals: ");
	scanf(" %d", &veganMeals);

	total = beefMeals + chickenMeals + veganMeals;

	//checks for errors and gets the cost of the room
	if (beefMeals < 0 || chickenMeals < 0 || veganMeals < 0) {
		printf("----NEGATIVE ERROR----");
		return 0;
	} else if (total > ROOM1_SEATS) {
		printf("----OVERFILL ERROR----");
		return 0;
	} else if (total > ROOM3_SEATS) { 
		roomCost = ROOM4_PRICE;
	} else if (total > ROOM2_SEATS) {
		roomCost = ROOM3_PRICE;
	} else if (total > ROOM1_SEATS) {
		roomCost = ROOM2_PRICE;
	} else {
		roomCost = ROOM1_PRICE;
	}

	//gets the pricing for all the meals
	beefCost = beefMeals * BEEF_PRICE;
	chickenCost = chickenMeals * CHICKEN_PRICE;
	veganCost = veganMeals * VEGAN_PRICE;
	gratuity = (beefCost + chickenCost + veganMeals) * GRATUITY_RATE;

	//prints out the receipt
	printf("Nova Caterers by Student Name\n\n");
	printf("%*s %d\n", LEFT_ALIGNMENT, "Number in party: ", total);

	printf("%*s %*s %f\n", LEFT_ALIGNMENT, "Room Cost $: ", CENTER_ALIGNMENT, "", roomCost);

	printf("%*s %*s %f\n", LEFT_ALIGNMENT, "Room Tax $: ", CENTER_ALIGNMENT, "", roomCost * ROOM_TAX_RATE);
	printf("%*s %d\n", LEFT_ALIGNMENT, "Number of Vegan Meals: ", veganMeals);
	printf("%*s %*s %f\n", LEFT_ALIGNMENT, "Cost of Vegan Meals $: ", CENTER_ALIGNMENT, "", veganMeals * VEGAN_PRICE);
	printf("%*s %*s %.2f\n", LEFT_ALIGNMENT, "Gratuity $: ", CENTER_ALIGNMENT, "", gratuity);
	printf("--------------------------------------------------\n");
	printf("%*s %*s %.2f\n", LEFT_ALIGNMENT, "Total $: ", CENTER_ALIGNMENT, "", gratuity + total + roomCost);
	
	return 0;
}
