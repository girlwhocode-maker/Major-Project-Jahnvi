#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcomeScreen();
void customerDetails(char name[], int *custID, int *type);
float calculateDomestic(float units);
float calculateCommercial(float units);
void printBill(char name[], int custID, int type, float units, float amount);
void instructions();

int main() {
    char name[50];
    int custID, type;
    float units, amount;

    welcomeScreen();
    instructions();

    customerDetails(name, &custID, &type);

    printf("\nEnter total units consumed: ");
    scanf("%f", &units);

    if (units < 0) {
        printf("\nInvalid unit entry! Program exiting...\n");
        return 0;
    }

    if (type == 1) {
        amount = calculateDomestic(units);
    } else {
        amount = calculateCommercial(units);
    }

    printBill(name, custID, type, units, amount);
    printf("\nThank you for using Electricity Bill Calculator!\n");

    return 0;
}

void welcomeScreen() {
    printf("===============================================\n");
    printf("          ELECTRICITY BILL CALCULATOR          \n");
    printf("===============================================\n");
}

void instructions() {
    printf("\nThis program calculates electricity bills based on:\n");
    printf("1. Customer Type (Domestic/Commercial)\n");
    printf("2. Units consumed\n");
    printf("3. Slab-wise tariff\n\n");
}

void customerDetails(char name[], int *custID, int *type) {
    printf("Enter Customer Name: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter Customer ID: ");
    scanf("%d", custID);

    printf("\nSelect Connection Type:\n");
    printf("1. Domestic\n");
    printf("2. Commercial\n");
    printf("Enter choice: ");
    scanf("%d", type);

    if (*type != 1 && *type != 2) {
        printf("Invalid type selected! Defaulting to Domestic.\n");
        *type = 1;
    }
}

float calculateDomestic(float units) {
    float amount = 0;

    if (units <= 100) {
        amount = units * 3;
    } else if (units <= 200) {
        amount = (100 * 3) + (units - 100) * 4.5;
    } else if (units <= 500) {
        amount = (100 * 3) + (100 * 4.5) + (units - 200) * 6;
    } else {
        amount = (100 * 3) + (100 * 4.5) + (300 * 6) + (units - 500) * 7.5;
    }

    float fixedCharge = 50;
    float tax = amount * 0.05;

    return amount + fixedCharge + tax;
}

float calculateCommercial(float units) {
    float amount = 0;

    if (units <= 100) {
        amount = units * 5;
    } else if (units <= 300) {
        amount = (100 * 5) + (units - 100) * 7.5;
    } else if (units <= 600) {
        amount = (100 * 5) + (200 * 7.5) + (units - 300) * 10;
    } else {
        amount = (100 * 5) + (200 * 7.5) + (300 * 10) + (units - 600) * 12;
    }

    float fixedCharge = 120;
    float tax = amount * 0.12;

    return amount + fixedCharge + tax;
}

void printBill(char name[], int custID, int type, float units, float amount) {
    printf("\n===============================================\n");
    printf("                ELECTRICITY BILL                \n");
    printf("===============================================\n");

    printf("Customer Name: %s\n", name);
    printf("Customer ID   : %d\n", custID);
    printf("Connection    : %s\n", (type == 1) ? "Domestic" : "Commercial");
    printf("Units Consumed: %.2f\n", units);

    printf("-----------------------------------------------\n");
    printf("Total Amount Payable: ₹ %.2f\n", amount);
    printf("-----------------------------------------------\n");

    if (units > 500) {
        printf("Note: High usage detected! Try saving electricity.\n");
    }
}
