//
//  PathDepOption03.cpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "PathDepOption03.hpp"
#include <cmath>

void Rescale(SamplePath &S, double x)
{
    int m = (int)S.size();
    for(int j = 0; j<m; j++)
        S[j] = x*S[j];
}
double PathDepOption::PricebyMC(BSModel BSModel1, long N, double epsilon)
{
    double H = 0.0;
    double H_sq = 0.0;
    double H_eps = 0.0;
    
    SamplePath S(m);
    
    for(long i =0; i<N; i++)
    {
        BSModel1.GenerateOneSamplePath(T, m, S);
        
        H = (i*H + Payoff(S))/(i+1.0); // the weight of new Payoff(S) is 1, and the weight of previous payoff are i.
        
        H_sq = (i*H_sq + pow(Payoff(S),2.0))/(i+1.0);
        Rescale(S, 1.0+epsilon);
        
        H_eps = (i*H_eps + Payoff(S))/(i+1.0);
    }
    
    Price = exp(-BSModel1.r*T)*H;
    PricingError = exp(-BSModel1.r*T)*sqrt(H_sq-H*H)/sqrt(N-1.0);
    delta = exp(-BSModel1.r*T)*(H_eps-H)/(BSModel1.S0*epsilon);
    
    return Price;
}

double PathDepOption::PricebyVarRedMC(BSModel BSModel1, long N, PathDepOption &CVOption, double epsilon)
{
    DifferenceOfOption VarRedOpt(T,m,this,&CVOption);
    
    Price = VarRedOpt.PricebyMC(BSModel1,N, epsilon) + CVOption.PricebyBSFormula(BSModel1);
    
    PricingError = VarRedOpt.PricingError;
    
    delta = VarRedOpt.delta + CVOption.delta;
    
    return Price;
}

double ArthmAsianCall::Payoff(SamplePath &S)
{
    double Ave = 0.0;
    for(int k = 0; k<m; k++)
        Ave = (k/(k+1.0))*Ave+S[k]/(k+1.0);//also, the weight of new is 1, for the previous are k;
    if(Ave<K)
        return 0.0;
    return Ave-K;
}
