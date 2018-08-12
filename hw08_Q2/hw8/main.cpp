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
#include <cmath>
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

class hw8
{
private:
    double C;
    double F;
    double P;
    int T;
public:
    hw8(double P_, double C_, double T_, double F_):P(P_),C(C_),T(T_),F(F_){}
    double Value(double y)
    {
        double a = 0.0;
        for(int i = 0; i<T; i++)
    {
        //double a = 0.0;不能把double a写在这里，因为出了花括号就没有了。应该写在上面。
        a += C*exp(-y*(i+1));
    }
        a = a+F*exp(-y*T) - P;
        return a;
    }
    
    double Derive(double y)
    {
        double b = 0.0;
        for(int i = 0; i<T; i++)
        {
            b += -(i+1)*C*exp(-y*(i+1));
        }
        b = b+F*(-T)*exp(-y*T);
        return b;
    }
    
    double GetF(){return F;}
    double GetT(){return T;}
    double GetC(){return C;}
    double GetP(){return P;}
    
};

int main()
{
    
    cout << setiosflags(ios::fixed) << setprecision(4);
    double F=100.0;
    int T= 3.0;
    double C=1.2;
    double P=98.56;
    
    hw8 myfunction(P,C,T,F);
    
    double Acc=0.0001;
    double Tgt=0.0;
    double LEnd=0.0;
    double REnd=1.0;
    double Guess=0.2;
    
    
    
    cout<<"F = "<<myfunction.GetF()<<endl;
    cout<<"T = "<<myfunction.GetT()<<endl;
    cout<<"coupons: "<<endl;
    for (int i = 0; i <= T; i++)
    {
        cout<<"C"<<i<<" = "<<myfunction.GetC()<<endl;
    }
    cout<<"tanors: "<<endl;
    for (int i = 0; i < T; i++)
    {
        cout<<"T"<<i<<" = "<<(double)i+1<<endl;
    }
    cout<<"P = "<<myfunction.GetP()<<endl;
    
    
    cout<<"Yield by bisection method: " <<SolvebyBisect<hw8>(myfunction,Tgt,LEnd,REnd,Acc)<<endl;//我之前运行不出来，是因为写了hw8 hw8（就是对象也叫hw8，这样计算机是识别不出的。）
    cout<<"Yield by Newton-Raphson method: "<<SolvebyNR<hw8>(myfunction,Tgt,Guess,Acc)<<endl;
  
    system("pause");
    
    return 0;
}


/*
 F = 100.0000
 T = 3.0000
 coupons:
 C0 = 1.2000
 C1 = 1.2000
 C2 = 1.2000
 C3 = 1.2000
 tanors:
 T0 = 1.0000
 T1 = 2.0000
 T2 = 3.0000
 P = 98.5600
 Yield by bisection method: 0.0168
 Yield by Newton-Raphson method: 0.0168
 Program ended with exit code: 0
 */
