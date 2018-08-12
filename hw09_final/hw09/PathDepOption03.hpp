//
//  PathDepOption03.hpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef PathDepOption03_hpp
#define PathDepOption03_hpp

#include <stdio.h>
#include "BSModel01.hpp"

class PathDepOption
{
public:
    double T;
    int m;
    double Price;
    double PricingError;
    double delta;
    double gamma;
    
    double PricebyMC(BSModel BSModel1, long N, double epsilon);
    double PricebyVarRedMC(BSModel BSModel1, long N, PathDepOption &CVOption, double epsilon);
    virtual double PricebyBSFormula(BSModel BSModel1) {return 0.0;};
    
    virtual double Payoff(SamplePath &S) = 0;
};

class DifferenceOfOption:public PathDepOption
{
public:
    PathDepOption *p1;
    PathDepOption *p2;
    
    DifferenceOfOption(double T_, int m_, PathDepOption* p1_, PathDepOption* p2_)
    {T = T_; m= m_; p1 = p1_; p2 = p2_;}
    
    double Payoff(SamplePath &S)
    {return p1->Payoff(S)-p2->Payoff(S);}
};

class ArthmAsianCall: public PathDepOption
{
public:
    double K;
    ArthmAsianCall(double T_, double K_, int m_)
    {T = T_; K = K_; m = m_;}
    double Payoff(SamplePath &S);
};
#endif /* PathDepOption03_hpp */
