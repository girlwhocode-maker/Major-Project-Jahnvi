#ifndef UTILS_H
#define UTILS_H

void welcomeScreen();
void customerDetails(char name[], int *custID, int *type);
float calculateDomestic(float units);
float calculateCommercial(float units);
void printBill(char name[], int custID, int type, float units, float amount);
void instructions();

#endif
