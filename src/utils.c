#include <stdio.h>
#include <string.h>
#include "bill.h"
#include "utils.h"

static float calculateAmount(float units, TariffPlan *plan) {
    float amount = 0.0f;
    float prevLimit = 0.0f;

    for (int i = 0; i < plan->slabCount; i++) {
        float upper = plan->slabs[i].limit;
        float rate  = plan->slabs[i].rate;

        if (units > upper) {
            amount += (upper - prevLimit) * rate;
            prevLimit = upper;
        } else {
            amount += (units - prevLimit) * rate;
            break;
        }
    }

    float tax = amount * plan->taxRate;
    return amount + plan->fixedCharge + tax;
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
    int ch;

    printf("Enter Customer Name: ");
    while ((ch = getchar()) != '\n' && ch != EOF);
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
    return calculateAmount(units, &domesticPlan);
}

float calculateCommercial(float units) {
    return calculateAmount(units, &commercialPlan);
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
