#include "bill.h"

TariffPlan domesticPlan = {
    50.0f,      
    0.05f,      
    {
        {100.0f, 3.0f},
        {200.0f, 4.5f},
        {500.0f, 6.0f},
        {1000000.0f, 7.5f}  
    },
    4
};


TariffPlan commercialPlan = {
    120.0f,     
    0.12f,      
    {
        {100.0f, 5.0f},
        {300.0f, 7.5f},
        {600.0f, 10.0f},
        {1000000.0f, 12.0f}  
    },
    4
};
