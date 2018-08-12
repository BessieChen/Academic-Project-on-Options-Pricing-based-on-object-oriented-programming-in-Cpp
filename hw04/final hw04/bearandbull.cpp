//
//  bearandbull.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.

#include "bearandbull.hpp"
#include "Option01.hpp"
#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int Bull::GetInputData()
{
    cout<<"Enter European bull spread option data: "<<endl;
    int N;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K1: ";cin>>K1;
    cout<<"Enter K2: ";cin>>K2;
    cout<<endl;
    
    return 0;
}

double Bull::Payoff(double z)
{
    if(z<=K1)
        return 0.0;
    if(K1<z && z<K2)
        return z-K1;
    return K2-K1;
}

int Bear::GetInputData()
{
    cout<<"Enter European bear spread option data: "<<endl;
    int N;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K1: ";cin>>K1;
    cout<<"Enter K2: ";cin>>K2;
    cout<<endl;
    
    return 0;
}

double Bear::Payoff(double z)
{
    if(z<=K1)
        return K2-K1;
    if(K1<z && z<K2)
        return K2-z;
    return 0.0;
}


