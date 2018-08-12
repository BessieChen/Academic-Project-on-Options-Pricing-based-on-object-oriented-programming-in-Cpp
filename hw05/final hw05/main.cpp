//
//  main.cpp
//  final hw05
//
//  Created by 陈贝茜 on 2017/10/6.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include <iostream>
#include "BinModel 01.hpp"
#include "Option01.hpp"
#include "callandput.hpp"
#include "strangleandbutterfly.hpp"
#include "doubledigit.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    BinModelhw4 hw4;
    Euroption E1;
    
    if(hw4.GetInputData()==1)
        return 1;
    
    Call Call1;
    Call1.GetInputData();
    cout<<"European Call Option Price is: "<<Call1.PricebyCrr(hw4)<<endl<<endl;
    
    Put Put1;
    Put1.GetInputData();
    cout<<"European Put Option Price is: "<<Put1.PricebyCrr(hw4)<<endl<<endl;
    
    DoubleDigit DoubleDigit1;
    DoubleDigit1.GetInputData();
    cout<<"European Double-Digital Option Price is: "<<DoubleDigit1.PricebyCrr(hw4)<<endl<<endl;
    
    Strangle Strangle1;
    Strangle1.GetInputData();
    cout<<"N = "<<Strangle1.GetN()<<endl;
    cout<<"K1 = "<<Strangle1.GetK1()<<endl;
    cout<<"K2 = "<<Strangle1.GetK2()<<endl<<endl;
    cout<<"European Strangle Option Price is: "<<Strangle1.PricebyCrr(hw4)<<endl<<endl;
    
    Butterfly Butterfly1;
    Butterfly1.GetInputData();
    cout<<"N = "<<Butterfly1.GetN()<<endl;
    cout<<"K1 = "<<Butterfly1.GetK1()<<endl;
    cout<<"K2 = "<<Butterfly1.GetK2()<<endl<<endl;
    cout<<"European Butterfly Option Price is: "<<Butterfly1.PricebyCrr(hw4)<<endl<<endl;
    
    system("pause");
    
    return 0;
}

/*
 Enter S0: 106
 Enter U: 0.1525
 Enter D: -0.13138
 Enter R: 0.00545
 
 Input data checked
 There is no arbitrage
 
 Enter call option data:
 Enter steps to expiry: 8
 Enter K: 100
 
 European Call Option Price is: 21.7726
 
 Enter put option data:
 Enter steps to expiry: 8
 Enter K: 100
 
 European Put Option Price is: 11.5176
 
 Enter double-digital option data:
 Enter steps to expiry: 8
 Enter K1: 100
 Enter K2: 110
 
 European Double-Digital Option Price is: 0.260448
 
 Enter strangle option data:
 Enter steps to expiry: 8
 Enter K1: 100
 Enter K2: 110
 
 N = 8
 K1 = 100
 K2 = 110
 
 European Strangle Option Price is: 28.4991
 
 Enter Butterfly option data:
 Enter steps to expiry: 8
 Enter K1: 100
 Enter K2: 110
 
 N = 8
 K1 = 100
 K2 = 110
 
 European Butterfly Option Price is: 0.921831
 
 Program ended with exit code: 0
 */

