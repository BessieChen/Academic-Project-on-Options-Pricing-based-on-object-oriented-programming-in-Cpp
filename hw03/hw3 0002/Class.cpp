//
//  Class.cpp
//  hw3 0002
//
//  Created by 陈贝茜 on 2017/10/5.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Class.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double functionfromhw(double X)
{
    return pow(X,3)-pow(X,2)+1;
}

double DefInt::ByTrapezoid(int N)
{
    double I = 0;
    double J = 0;
    double d = (b-a)/N;
    
    for(int i=0;i<=N;i++)
    {
        I=I+f(a+(i*d));
    }
    
    for(int i=1;i<N;i++)
    {
        J=J+f(a+(i*d));
    }
    
    double T = 0;
    
    T =(d/2)*(I+J);
    
    return T;
}

double DefInt::BySimpson(int N)
{
    double I = 0;
    double J = 0;
    double d = (b-a)/N;
    
    for(int i=1;i<N;i++)
    {
        if((i%2)!=0)
        {
            I=I+f(a+(i*d));
        }
    }
    
    for(int i=2;i<N-1;i++)
    {
        if((i%2)==0)
        {
            J=J+f(a+(i*d));
        }
    }
    
    double T = 0;
    
    T =(d/3)*(f(a)+(4*I)+(2*J)+f(b));
    
    return T;
}
