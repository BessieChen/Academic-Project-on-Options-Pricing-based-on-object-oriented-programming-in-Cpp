//
//  main.cpp
//  hw7
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//
#include "BinModel 01.hpp"
#include "BinLattice.hpp"
#include "Option.hpp"

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    double S0=106.0;
    double r=0.058;
    double sigma=0.46;
    double T=(double)9/12;
    double K=100.0;
    int N=8;
    
    cout << setiosflags(ios::fixed) << setprecision(5);
    
    double h = T/N;
    
    BlackScholes BSModelhw7;
    BSModelhw7.SetValue(r,sigma,S0);
    
    BinModel BinModelhw7;
    BinModelhw7 = BSModelhw7.SetBinModel(h);
    
    Call Call(N,K);
    Call.PricebySnell(BinModelhw7);
    
    cout<<"S0 = "<<S0<<endl;
    cout<<"r = "<<r<<endl;
    cout<<"sigma = "<<sigma<<endl;
    cout<<"T = "<<T<<endl;
    cout<<"K = "<<K<<endl;
    cout<<"N = "<<N<<endl;
    cout<<endl;
    
    cout<<"U = "<<BinModelhw7.GetU()<<endl;
    cout<<"D = "<<BinModelhw7.GetD()<<endl;
    cout<<"R = "<<BinModelhw7.GetR()<<endl;
    cout<<"American call option price is "<<Call.PricebySnell(BinModelhw7)<<endl;
    
    system("pause");
    
    return 0;
    
    
}

/*
 S0 = 106.00000
 r = 0.05800
 sigma = 0.46000
 T = 0.75000
 K = 100.00000
 N = 8
 
 U = 0.14610
 D = -0.13526
 R = 0.00545
 American call option price is 21.33399
 Program ended with exit code: 0
 */
