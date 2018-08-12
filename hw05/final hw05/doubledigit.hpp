//
//  doubledigit.hpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef doubledigit_hpp
#define doubledigit_hpp
#include "BinModel 01.hpp"
#include "Option01.hpp"

#include <stdio.h>

class DoubleDigit: public Euroption
{
private:
    double K1;
    double K2;
public:
    int GetInputData();
    double Payoff(double z);
};
#endif /* doubledigit_hpp */
