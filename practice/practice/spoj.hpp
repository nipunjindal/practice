//
//  spoj.hpp
//  practice
//
//  Created by njindal on 9/26/15.
//  Copyright (c) 2015 njindal. All rights reserved.
//

#ifndef practice_spoj_hpp
#define practice_spoj_hpp

#include <iostream>
#include <assert.h>
//uncomment to output input elements debug info
//#define DEBUG_INPUT

//Generic class to input number from console
template<class A, class B>
class Input
{
private:
    B inputElements, readIndex;

public:
    Input(): inputElements(0), readIndex(0) {}
    
    B getNumTestcase(B elemPerTest)
    {
        B numTest;
        std::cin >> numTest;
        inputElements = elemPerTest*numTest;
#ifdef DEBUG_INPUT
        std::cout << "[Input] Number of Testcases is:" << inputElements << std::endl;
#endif
        return inputElements;
    }
    
    bool getNextElement(A &nextElement)
    {
        if(readIndex >= inputElements)
        {
            //assert(false && "read index increases number of elements");
            return false;
        }
        std::cin >> nextElement;
#ifdef DEBUG_INPUT
        std::cout << "[Input] Next Element is:" << nextElement << std::endl;
#endif
        readIndex++;
        return true;
    }
};

template<class A, class B>
class InputStore
{
private:
    A *elements;
    B readIndex, inputElements;
    
public:
    InputStore(): elements(0), readIndex(0) {}
    ~InputStore()
    {
        if(elements)
            delete [] elements;
    }
    
    B getNumTestcase(B elemPerTest)
    {
        B numTest;
        std::cin >> numTest;
        inputElements = elemPerTest*numTest;
#ifdef DEBUG_INPUT
        std::cout << "[Input] Number of Testcases is:" << inputElements << std::endl;
#endif
        elements = new A[inputElements];
        for(unsigned int idx = 0; idx < inputElements; idx++)
        {
            std::cin >> elements[idx];
        }
        return inputElements;
    }
    
    bool getNextElement(A &nextElement)
    {
        if(readIndex >= inputElements)
        {
            //assert(false && "read index increases number of elements");
            return false;
        }
        nextElement = elements[readIndex];
#ifdef DEBUG_INPUT
        std::cout << "[Input] Next Element is:" << nextElement << std::endl;
#endif
        readIndex++;
        return true;

    }
    
    A getMax()
    {
        A max = elements[0];
        for(unsigned int idx = 1; idx < inputElements; idx++)
        {
            if(elements[idx] > max)
                max = elements[idx];
        }
#ifdef DEBUG_INPUT
        std::cout << "[Input] Max Number is:" << max << std::endl;
#endif
        return max;
    }

};

/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
*/
extern void primeNumberGenerator();

#endif
