//
//  strangleandbutterfly.hpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef strangleandbutterfly_hpp
#define strangleandbutterfly_hpp
#include "Option01.hpp"
#include "BinModel 01.hpp"
#include <stdio.h>

class Strangle: public Euroption
{
private:
    double K1;
    double K2;
    int N; //这里有小小的变动，之前int N是不存在在class strangle private里面的，因为main函数需要输出N = 8,所以我在这里把int N设为新的private。
public:
    int GetInputData();
    double Payoff(double z);
    double GetK1(){return K1;};
    double GetK2(){return K2;};
    double GetN(){return N;};
};

class Butterfly: public Euroption
{
private:
    double K1;
    double K2;
    int N;
public:
    int GetInputData();
    double Payoff(double z);
    double GetK1(){return K1;};
    double GetK2(){return K2;};
    double GetN(){return N;};
};



#endif /* strangleandbutterfly_hpp */


