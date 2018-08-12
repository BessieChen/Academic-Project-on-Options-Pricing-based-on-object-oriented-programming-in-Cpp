//
//  callandput.hpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef callandput_hpp
#define callandput_hpp
#include "BinModel 01.hpp"
#include "Option01.hpp"
#include <stdio.h>

class Call: public Euroption
{
private:
    double K;
public:
    int GetInputData();
    double Payoff(double z);
};

class Put: public Euroption
{
private:
    double K;
public:
    int GetInputData();
    double Payoff(double z);
};



#endif /* callandput_hpp */
