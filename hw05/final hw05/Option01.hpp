//
//  Option01.hpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef Option01_hpp
#define Option01_hpp
#include "BinModel 01.hpp"
#include <iostream>
#include <stdio.h>

int factorial(int i);

class Euroption
{
private:
    int N;
public:
    void SetN(int N_){N = N_;}//这里不用；
    virtual double Payoff(double z){return 0.0;}//这里不用；
    double PricebyCrr(BinModelhw4 Model);
};


#endif /* Option01_hpp */

