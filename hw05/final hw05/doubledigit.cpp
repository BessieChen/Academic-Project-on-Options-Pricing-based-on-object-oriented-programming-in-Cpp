//
//  doubledigit.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "doubledigit.hpp"
#include "Option01.hpp"
#include "BinModel 01.hpp"

#include <iostream>
#include <cmath>

using namespace std;

int DoubleDigit::GetInputData()
{
    cout<<"Enter double-digital option data: "<<endl;
    int N;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K1: ";cin>>K1;
    cout<<"Enter K2: ";cin>>K2;
    cout<<endl;
    
    return 0;
}

double DoubleDigit::Payoff(double z)
{
    if(K1<z && z<K2) return 1.0;
    return 0.0;
}
