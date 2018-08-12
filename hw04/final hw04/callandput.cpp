//
//  callandput.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "callandput.hpp"
#include "BinModel 01.hpp"
#include "Option01.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int Call::GetInputData()
{
    cout<<"Enter call option data: "<<endl;
    int N;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K: ";cin>>K;
    cout<<endl;
    
    return 0;
}

double Call::Payoff(double z)
{
    if(z>K)
        return z-K;
    return 0.0;
}

int Put::GetInputData()
{
    cout<<"Enter put option data: "<<endl;
    int N;
    cout<<"Enter steps to expiry: ";cin>>N;
    SetN(N);
    cout<<"Enter K: ";cin>>K;
    cout<<endl;
    
    return 0;
}

double Put::Payoff(double z)
{
    if(K>z)
        return K-z;
    return 0.0;
}

