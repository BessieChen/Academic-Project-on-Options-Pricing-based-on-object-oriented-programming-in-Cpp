//
//  Solver.hpp
//  hw8
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp

template <typename Function>
double SolvebyBisect(Function &Fct, double Tgt, double LEnd, double REnd, double Acc)
{
    double left = LEnd;
    double right = REnd;
    double mid = (left+right)/2;
    double y_left =Fct.Value(left)-Tgt;
    double y_mid = Fct.Value(mid)-Tgt;
    
    while(mid-left>Acc)
    {
        if((y_left>0&&y_mid>0)||(y_left<0&&y_mid<0))
        {left = mid; y_left = y_mid;}
        else right = mid;
        
        mid = (left+right)/2;
        y_mid = Fct.Value(mid)-Tgt;
    }
    return mid;
}

template <typename Function>
double SolvebyNR(Function &Fct, double Tgt, double Guess, double Acc)
{
    double x_prev = Guess;
    double x_next = x_prev- (Fct.Value(x_prev)- Tgt)/Fct.Derive(x_prev);
    while (x_next - x_prev >Acc || x_prev - x_next >Acc)
    {
        x_prev = x_next;
        x_next = x_prev - (Fct.Value(x_prev) - Tgt)/ Fct.Derive(x_prev);
    }
    return x_next;
}

#include <stdio.h>

#endif /* Solver_hpp */
