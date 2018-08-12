//
//  GmtrAsianCall.hpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef GmtrAsianCall_hpp
#define GmtrAsianCall_hpp

#include <stdio.h>
#include "PathDepOption03.hpp"

class GmtrAsianCall: public PathDepOption
{
public:
    double K;
    GmtrAsianCall(double T_, double K_, int m_)
    {T = T_; K = K_; m = m_;}
    
    double Payoff(SamplePath &S);
    double PricebyBSFormula(BSModel BSModel1);
};

#endif /* GmtrAsianCall_hpp */
