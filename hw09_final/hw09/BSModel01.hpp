//
//  BSModel01.hpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef BSModel01_hpp
#define BSModel01_hpp

#include <stdio.h>

using namespace std;

#include <vector>
#include <cstdlib>
#include <ctime>

typedef vector<double> SamplePath;

class BSModel
{
public:
    double S0, r, sigma;
    BSModel(double S0_, double r_, double sigma_)
    {
        S0 = S0_;
        r = r_;
        sigma = sigma_;
        srand(time(NULL));
    }
    void GenerateOneSamplePath(double T, int m, SamplePath &S);
    
};


#endif /* BSModel01_hpp */
