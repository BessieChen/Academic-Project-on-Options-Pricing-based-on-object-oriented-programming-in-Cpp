//
//  main.cpp
//  hw3 0002
//
//  Created by 陈贝茜 on 2017/10/5.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Class.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    DefInt MyInt(1.0,2.0,functionfromhw);
    
    int N;
    cout<<"Entering the interval: ";cin>>N;
    
    cout<<"Using the Trapetoid method, the value of integral under the entered limit is: "<<endl;
    cout<< MyInt.ByTrapezoid(N)<<endl<<endl;
    
    cout<<"Using the Simpson method, the value of integral under the entered limit is: "<<endl;
    cout<< MyInt.BySimpson(N)<<endl<<endl;
    
    system("pause");
    
    return 0;
}

/*
 Entering the interval: 100000
 Using the Trapetoid method, the value of integral under the entered limit is:
 2.41667
 
 Using the Simpson method, the value of integral under the entered limit is:
 2.41667
 
 sh: pause: command not found
 Program ended with exit code: 0*/


