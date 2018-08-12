//
//  BSModel01.cpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "BSModel01.hpp"
#include <cmath>


const double pi = 4.0*atan(1.0);

double Guess()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1))*cos(2.0*pi*U2);
}

void BSModel::GenerateOneSamplePath(double T, int m, SamplePath &S)
{
    double St = S0;
    for(int i = 0; i<m; i++)
    {
        S[i] = St*exp((r-sigma*sigma*0.5)*(T/m)+sigma*sqrt(T/m)*Guess());
        St = S[i];
    }
}
