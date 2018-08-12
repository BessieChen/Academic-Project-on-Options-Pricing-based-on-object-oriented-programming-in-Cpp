//
//  BinModel 01.hpp
//  hw7
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef BinModel_01_hpp
#define BinModel_01_hpp
#include <stdio.h>


class BinModel
{
private:
    double S0;
    double U;
    double D;
    double R;
public:
    BinModel(){};
    BinModel(double S0_, double U_, double D_, double R_):S0(S0_),U(U_),D(D_),R(R_){};
    double RiskNeutProb();
    double S(int N, int i);
    double GetR(){return R;};
    double GetS0(){return S0;};
    double GetU(){return U;};
    double GetD(){return D;};
};


class BlackScholes
{
private:
    double r;
    double sigma;
    double S0;
    //double h;不能再private里面写h，是因为之后需要h = T/N, 会在class外面对h进行修改。
public:
    void SetValue(double r_,double sigma_, double S0_){r = r_, sigma = sigma_, S0 = S0_;};//注意！我这里出过错！就是main函数里面，写成了.SetValue(S0,r,sigma)!!应该是写成.SetValue(r,sigma,S0)
    BinModel SetBinModel(double h);//神奇！一个类里面，也可以返回另一个类。
};

#endif /* BinModel_01_hpp */
