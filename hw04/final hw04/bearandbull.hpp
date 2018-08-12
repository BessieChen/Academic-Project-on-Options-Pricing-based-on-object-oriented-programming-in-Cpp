//
//  bearandbull.hpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef bearandbull_hpp
#define bearandbull_hpp
#include "Option01.hpp"
#include "BinModel 01.hpp"
#include <stdio.h>

class Bull: public Euroption
{
private:
    double K1;
    double K2;
public:
    int GetInputData();
    double Payoff(double z);
};

class Bear: public Euroption
{
private:
    double K1;
    double K2;
public:
    int GetInputData();
    double Payoff(double z);
};

#endif /* bearandbull_hpp */
