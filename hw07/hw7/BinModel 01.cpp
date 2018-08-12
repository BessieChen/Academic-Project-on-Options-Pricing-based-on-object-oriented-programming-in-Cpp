//
//  BinModel 01.cpp
//  hw7
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>


double BinModel::S(int N, int i)
{
    return S0*pow(1+U,i)*pow(1+D,N-i);
}

double BinModel::RiskNeutProb()
{
    return(R-D)/(U-D);
}

BinModel BlackScholes::SetBinModel(double h)//神奇的做法！返回值是BinModel类。
{
    double U = exp((r-sigma*sigma/2)*h+sigma*sqrt(h))-1;
    double D = exp((r-sigma*sigma/2)*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    
    BinModel BinModel1(S0, U, D, R);//这里注意！首先：void SetValue(double r_,double sigma_, double S0_)把S0传给了BlackSchole里面的private: double S0,然后这里的BinModel1(S0, U, D, R)中S0就是BlackSchole private里面的值，然后通过parameter constructor传给了BinModel1.
    return BinModel1;
}

