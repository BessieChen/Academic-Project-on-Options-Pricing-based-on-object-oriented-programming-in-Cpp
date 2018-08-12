//
//  Option.hpp
//  hw06
//
//  Created by 陈贝茜 on 2017/10/21.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef Option_hpp
#define Option_hpp

#include <stdio.h>
#include "BinLattice.hpp"
#include "BinModel 01.hpp"

class Option
{
private:
    int N;
public:
    void SetN(int N_){ N = N_; }
    int GetN(){return N;}
    virtual double Payoff(double z) = 0;
};

class EurOption:public Option//public virtual Option
{
public:
    double PricebyCrr(BinModel Model);
    double PricebyCrrhw06(BinModel Model, BinLattice<double> &PriceTree, BinLattice<double> &DeltaTree, BinLattice<double> &BorrowTree);
};

class Call:public EurOption
{
private:
    int K;
public:
    void SetK(int K_){K = K_;}
    int GetInputData();
    double Payoff(double z);
    double GetK(){return K;};
};

class Put:public EurOption
{
private:
    int K;
public:
    void SetK(int K_){K = K_;}
    int GetInputData();
    double Payoff(double z);
    double GetK(){return K;};
};
#endif /* Option_hpp */
