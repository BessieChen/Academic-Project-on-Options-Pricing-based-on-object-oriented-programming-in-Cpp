//
//  BinModel01.hpp
//  final 01
//
//  Created by 陈贝茜 on 2017/9/22.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef BinModel01_hpp
#define BinModel01_hpp

#include <stdio.h>

#endif /* BinModel01_hpp */

int GetInputData(double &S0, double &U,double &D,double &R);
int GetInputData (int &N, double &K);
double RiskNeutProb(double U, double D, double R);
double S(double S0, double U, double D, int N, int i);

