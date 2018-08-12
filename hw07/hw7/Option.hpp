//
//  Option.hpp
//  hw7
//
//  Created by 陈贝茜 on 2017/10/26.
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

class EurOption:public virtual Option
{
public:
    double PricebyCrr(BinModel Model);
    double PricebyCrrhw06(BinModel Model, BinLattice<double> &PriceTree, BinLattice<double> &DeltaTree, BinLattice<double> &BorrowTree);
};

class AmOption:public virtual Option
{
public:
    double PricebySnell(BinModel Model);
};

class Call:public EurOption, public AmOption
{
private:
    int K;
    int N;//为什么不能用到Option类的int N？？这样也不行：Call(int N_, int K_):int Option::N(N_),K(K_){};然后cpp里面的 PricebySnell的GetN我改成了  int N = 8;
public:
    Call(int N_, int K_):N(N_),K(K_){};
    double Payoff(double z);
    double GetK(){return K;};
};

class Put:public EurOption, public AmOption
{
private:
    int K;
public:
    void SetK(int K_){K = K_;}
    double Payoff(double z);
    double GetK(){return K;};
};
#endif /* Option_hpp */

