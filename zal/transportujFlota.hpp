#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0) return 0;
    
    unsigned int zagl_count = 0;
    unsigned int sum = 0;
    unsigned int przewiezionyTowar;
    
    Stocznia stocznia{};
    while (true) 
    {
        Statek* s1 = stocznia();
        przewiezionyTowar  = s1->transportuj();
        sum += przewiezionyTowar;
        if (dynamic_cast<Zaglowiec*>(s1)) zagl_count++;
        delete s1;
        if (sum >= towar) return zagl_count;
    }
}
