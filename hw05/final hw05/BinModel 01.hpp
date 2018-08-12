//
//  BinModel 01.hpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/5.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef BinModel_01_hpp
#define BinModel_01_hpp
#include <stdio.h>


class BinModelhw4
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
};



#endif /* BinModel_01_hpp */




