//
//  GmtrAsianCall.cpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "GmtrAsianCall.hpp"
#include "EurCall.hpp"
#include <cmath>

double GmtrAsianCall::Payoff(SamplePath &S)
{
    double Prod = 1.0;
    for(int i =0; i<m; i++)
    {
        Prod = Prod*S[i];
    }
    
    if(pow(Prod,1.0/m)<K)
        return 0.0;
    return pow(Prod,1.0/m)-K;
}

double GmtrAsianCall::PricebyBSFormula(BSModel BSModel1)
{
    double a = exp(-BSModel1.r*T)*BSModel1.S0*exp((m + 1.0)*T / (2.0*m)*(BSModel1.r + BSModel1.sigma*BSModel1.sigma*((2.0*m + 1.0) / (3.0*m) - 1.0) / 2.0));
    double b = BSModel1.sigma*sqrt((m + 1.0)*(2.0*m + 1.0) / (6.0*m*m));
    
    EurCall EC(T,K);
    Price = EC.PricebyBSFormula(a, b, BSModel1.r);
    
    delta = N(EC.d_plus(a, b, BSModel1.r))*a/BSModel1.S0;
    
    return Price;
}
