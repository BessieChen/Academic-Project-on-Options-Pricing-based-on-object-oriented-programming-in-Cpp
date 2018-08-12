//
//  main.cpp
//  hw8
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Solver.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

class F1
{
public:
    double Value(double x){return x*x-2;}
    double Derive(double x){return 2*x;}
};

class F2
{
private:
    double a;
public:
    F2(double a_){a = a_;}
    double Value(double x){return x*x-a;}
    double Derive(double x){return 2*x;}
    
};

int main()
{
    F1 hw8F1;
    F2 hw8F2(3.0);
    cout << setiosflags(ios::fixed) << setprecision(4);
    double Acc=0.001;
    double LEnd=0.0, REnd=2.0;
    double Tgt=0.0;
    
    cout<<"Root of F1 by bisect: " <<SolvebyBisect<F1>(hw8F1,Tgt,LEnd,REnd,Acc)<<endl;
    cout<<"Root of F2 by bisect: "<<SolvebyBisect<F2>(hw8F2,Tgt,LEnd,REnd,Acc)<<endl;
    
    double Guess = 1.0;
    
    cout<<"Root of F1 by Newton-Raphson: "<<SolvebyNR<F1>(hw8F1,Tgt,Guess,Acc)<<endl;
    cout<<"Root of F2 by Newton-Raphson: "<<SolvebyNR<F2>(hw8F2,Tgt,Guess,Acc)<<endl;
    
    system("pause");
    
    return 0;
}


/*
 Root of F1 by bisect: 1.4150
 Root of F2 by bisect: 1.7314
 Root of F1 by Newton-Raphson: 1.4142
 Root of F2 by Newton-Raphson: 1.7321
 Program ended with exit code: 0
 */
