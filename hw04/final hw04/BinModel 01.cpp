//
//  BinModel 01.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/5.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double BinModelhw4::RiskNeutProb()
{
    return(R-D)/(U-D);
}

double BinModelhw4::S(int N, int i)
{
    return S0*pow(1+U,i)*pow(1+D,N-i);
}

int BinModelhw4::GetInputData()
{
    cout<<"Enter S0: ";cin>>S0;
    cout<<"Enter U: ";cin>>U;
    cout<<"Enter D: ";cin>>D;
    cout<<"Enter R: ";cin>>R;
    cout<<endl;
    
    if(S0<=0.0||U<=-1.0||D<=-1.0||U<=D||R<=-1.0)
    {cout<<"illegal data ranges"<<endl;
        cout<<"Terminating program"<<endl;
        return 1;}
    
    if(R>=U||R<=D)
    {cout<<"Arbitrage exists"<<endl;
        cout<<"Terminating program"<<endl;
        return 1;} //
    
    cout<<"Input data checked"<<endl;
    cout<<"There is no arbitrage"<<endl<<endl;
    
    return 0;
}

