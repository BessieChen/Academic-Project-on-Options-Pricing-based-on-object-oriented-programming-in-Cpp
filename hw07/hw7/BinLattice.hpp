//
//  BinLattice.hpp
//  hw7
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#ifndef BinLattice_hpp
#define BinLattice_hpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

template <class Type>
class BinLattice
{
private:
    int N;
    vector< vector<Type>> Lattice;
public:
    void SetN(int N_)//注意！这里不仅仅是N = N_,还有resize!
    {N = N_;
        Lattice.resize(N+1);
        for(int n = 0; n<=N; n++)Lattice[n].resize(n+1);
    }
    
    void SetNode(int n, int i, Type x)//注意！要加void！
    {
        Lattice[n][i] = x;
    }
    
    Type GetNode(int n, int i)
    {
        return Lattice[n][i];
    }
    
    void display(fstream &foutput)//虽然是输出，但是不适用 return，是cout，所以还是void！
    {
        foutput<<setiosflags(ios::fixed)<<setprecision(7);
        for(int n = 0; n<=N; n++)//先从n开始，就是先从竖行开始，从左往右
        {
            for(int i = 0; i<=n; i++)
            {foutput<<setw(15)<<GetNode(n,i)<<endl;}
        }
        foutput<<endl;
    }
};


#include <stdio.h>

#endif /* BinLattice_hpp */
