//
//  Options01.cpp
//  final 01
//
//  Created by 陈贝茜 on 2017/9/22.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Options01.hpp"
#include "BinModel01.hpp"
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

double CallPayoff(double z, double K)
{
    if(z>K)
        return z-K;
    
    return 0.0;
}


double PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
    double q= RiskNeutProb(U,D,R);
    double Price=0;
    double FactorialN = factorial(N);
    
    for(int i=0;i<=N;i++)
    {
        
    int Factoriali = factorial(i);
    int FactorialNi = factorial(N-i);
        
    Price+=FactorialN/(Factoriali*FactorialNi)*pow(q,i)*pow(1-q,N-i)*CallPayoff(S(S0,U,D,N,i),K);
     }
    
    Price=Price/pow(1+R,N);
    
    return Price;
    
}




