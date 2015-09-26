//
//  spoj.cpp
//  practice
//
//  Created by njindal on 9/26/15.
//  Copyright (c) 2015 njindal. All rights reserved.
//

#include <iostream>
#include <stdint.h>
#include "spoj.hpp"


void primeNumberGenerator()
{
    InputStore<unsigned int, unsigned int> input;
    input.getNumTestcase(2);
    
    unsigned int elem1, elem2;
    
    unsigned max = input.getMax()+1;
    
    unsigned prime[max];
    
    for(unsigned idx = 0; idx < max; idx++)
    {
        prime[idx] = 0;
    }
    prime[1] = 1; //neither prime nor composite
    
    for(unsigned idx = 2; idx < max; idx++)
    {
        if(prime[idx] == 1)
            continue;
        
        unsigned num = 2;
        while(num*idx < max)
        {
            prime[num*idx] = 1;
            num++;
        }
    }
    
    while(input.getNextElement(elem1) && input.getNextElement(elem2))
    {
        for(unsigned idx = elem1; idx <= elem2; idx++)
        {
            if(prime[idx] == 0)
                std::cout << idx << std::endl;
        }
        std::cout << std::endl;
    }
    
}
