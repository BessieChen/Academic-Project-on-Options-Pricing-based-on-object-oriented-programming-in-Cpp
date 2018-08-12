//
//  main.cpp
//  hw4 0001
//
//  Created by 陈贝茜 on 2017/10/5.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include <iostream>
#include "BinModel 01.hpp"
#include "Option01.hpp"
#include "callandput.hpp"
#include "bearandbull.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    BinModelhw4 hw4;
    
    if(hw4.GetInputData()==1)
        return 1;
    
    Call Call1;
    Call1.GetInputData();
    cout<<"European Call Option Price is: "<<Call1.PricebyCrr(hw4)<<endl<<endl;
    
    Put Put1;
    Put1.GetInputData();
    cout<<"European Put Option Price is: "<<Put1.PricebyCrr(hw4)<<endl<<endl;
    
    Bull Bull1;
    Bull1.GetInputData();
    cout<<"European Bull Option Price is: "<<Bull1.PricebyCrr(hw4)<<endl<<endl;

    Bear Bear1;
    Bear1.GetInputData();
    cout<<"European Bear Option Price is: "<<Bear1.PricebyCrr(hw4)<<endl<<endl;
    
    system("pause");
    
    return 0;
}

/*
 Enter S0: 106
 Enter U: 0.15125
 Enter D: -0.13138
 Enter R: 0.00545
 
 Input data checked
 There is no arbitrage
 
 Enter call option data:
 Enter steps to expiry: 8
 Enter K: 100
 
 European Call Option Price is: 21.6811
 
 Enter put option data:
 Enter steps to expiry: 8
 Enter K: 100
 
 European Put Option Price is: 11.4261
 
 Enter European bull spread option data:
 Enter steps to expiry: 8
 Enter K1: 100
 Enter K2: 110
 
 European Bull Option Price is: 4.71584
 
 Enter European bear spread option data:
 Enter steps to expiry: 8
 Enter K1: 100
 Enter K2: 110
 
 European Bear Option Price is: 4.85866
 
 Program ended with exit code: 0*/
