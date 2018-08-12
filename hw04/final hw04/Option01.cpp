//
//  Option01.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Option01.hpp"
#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int factorial(int i)
{
    int fac=1;
    
    if(i<=0)
        return fac;
    
    for(int n=1; n<=i; n++)
    {
        fac*=n;
    }
    return fac;
}

double Euroption::PricebyCrr(BinModelhw4 Model)
{
    double q = Model.RiskNeutProb();
    double Price=0;
    double FactorialN = factorial(N);
    
    for(int i=0;i<=N;i++)
    {
        int Factoriali = factorial(i);
        int FactorialNi = factorial(N-i);
        
        Price+=FactorialN/(Factoriali*FactorialNi)*pow(q,i)*pow(1-q,N-i)*Payoff(Model.S(N,i));
    }
    
    Price=Price/pow(1+Model.GetR(),N);
    
    return Price;
}


