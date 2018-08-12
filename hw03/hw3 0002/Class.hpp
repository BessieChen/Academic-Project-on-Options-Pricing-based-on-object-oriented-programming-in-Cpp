//
//  Class.hpp
//  hw3 0002
//
//  Created by 陈贝茜 on 2017/10/5.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef Class_hpp
#define Class_hpp

#include <stdio.h>

#endif /* Class_hpp */


double functionfromhw(double X);

class DefInt
{
private:
    double a; double b; double (*f)(double X);
public:
    DefInt(double a_, double b_, double (*f_)(double X))
    {
        a = a_; b = b_; f = f_;
    }
    double ByTrapezoid(int N);
    double BySimpson(int N);
};


