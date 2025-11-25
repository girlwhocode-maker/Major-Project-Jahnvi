#ifndef BILL_H
#define BILL_H

typedef struct {
    float limit; 
    float rate;
} Slab;

typedef struct {
    float fixedCharge;   
    float taxRate;       
    Slab slabs[4];       
    int slabCount;      
} TariffPlan;

extern TariffPlan domesticPlan;
extern TariffPlan commercialPlan;

#endif
