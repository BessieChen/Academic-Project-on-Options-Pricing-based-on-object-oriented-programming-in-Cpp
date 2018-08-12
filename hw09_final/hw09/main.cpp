//
//  main.cpp
//  hw09
//
//  Created by 陈贝茜 on 2017/11/2.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "PathDepOption03.hpp"
#include "GmtrAsianCall.hpp"


using namespace std;

int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    BSModel Model(S0,r,sigma);
    
    double T =1.0/12.0, K=100.0;
    int m=30;
    
    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall  CVOption(T,K,m);
    
    long N=30000;
    double epsilon =0.001;
    Option.PricebyVarRedMC(Model,N,CVOption,epsilon);
    cout << "Arithmetic call price = " << Option.Price << endl
    << "Error = " << Option.PricingError << endl
    << "delta = " << Option.delta << endl << endl;
    
    Option.PricebyMC(Model,N,epsilon);
    cout << "Price by direct MC = " << Option.Price << endl
    << "Error = " << Option.PricingError << endl
    << "delta = " << Option.delta << endl;
    
    system("pause");
    
    return 0;
}

/*
 
 Arithmetic call price = 1.42598
 Error = 0.000136314
 delta = 0.5202
 
 Price by direct MC = 1.43207
 Error = 0.0120215
 delta = 0.525759
 Program ended with exit code: 0
 
 */

