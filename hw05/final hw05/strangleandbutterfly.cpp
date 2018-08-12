//
//  strangleandbutterfly.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "strangleandbutterfly.hpp"
#include "Option01.hpp"
#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int Strangle::GetInputData()
{
    cout<<"Enter strangle option data: "<<endl;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K1: ";cin>>K1;
    cout<<"Enter K2: ";cin>>K2;
    cout<<endl;
    
    return 0;
}

double Strangle::Payoff(double z)
{
    if(z<=K1)
        return K1-z;
    else if(K1<z && z<=K2)
        return 0.0;
    return z-K2;
}

int Butterfly::GetInputData()
{
    cout<<"Enter Butterfly option data: "<<endl;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K1: ";cin>>K1;
    cout<<"Enter K2: ";cin>>K2;
    cout<<endl;
    
    return 0;
}

double Butterfly::Payoff(double z)
{
    if(K1<z && z<=(K1+K2)/2)
        return z-K1;
    else if((K1+K2)/2<z && z<=K2)
        return K2-z;
    return 0.0;
}
