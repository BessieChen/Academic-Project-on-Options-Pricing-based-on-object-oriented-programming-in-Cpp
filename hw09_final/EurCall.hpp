//
//  EurCall.hpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef EurCall_hpp
#define EurCall_hpp

#include <stdio.h>

class EurCall
{
public:
    double T, K;
    EurCall(double T_, double K_):T(T_),K(K_){}
    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
    double PricebyBSFormula(double S0, double sigma, double r);
    double VegabyBSFormula(double S0, double sigma, double r);
};

double N(double x);

#endif /* EurCall_hpp */
