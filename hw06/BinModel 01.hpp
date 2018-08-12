//
//  BinModel 01.cpp
//  hw06
//
//  Created by 陈贝茜 on 2017/10/21.
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
    double RiskNeutProb();
    double S(int N, int i);
    int GetInputData();
    double GetR(){return R;};
    double GetS0(){return S0;};
    double GetU(){return U;};
    double GetD(){return D;};
};



#endif /* BinModel_01_hpp */




