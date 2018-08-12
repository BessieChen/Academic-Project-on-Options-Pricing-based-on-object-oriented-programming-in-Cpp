//
//  Option.cpp
//  hw7
//
//  Created by 陈贝茜 on 2017/10/26.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Option.hpp"
#include "BinLattice.hpp"
#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>

using namespace std;


double AmOption::PricebySnell(BinModel Model)
{
    double q = Model.RiskNeutProb();//不要忘了（）！！
    int N = 8;
    vector<double> Price(N+1);
    double ConValue;
    for (int i = 0; i<=N; i++)
    {Price[i] = Payoff(Model.S(N,i));};
    
    for (int n = N-1; n>=0; n--)
    {
        for(int i = 0; i<=n; i++)
        {
            ConValue = (q*Price[i+1]+(1-q)*Price[i])/(1+Model.GetR());
            Price[i] = Payoff(Model.S(n,i));
            if(ConValue > Price[i])
            Price[i] = ConValue;
        }
    }
    return Price[0];
}


double Call::Payoff(double z)
{
    if (z>K) return z-K;
    return 0.0;
}

double Put::Payoff(double z)
{
    if (z<K) return K-z;
    return 0.0;
}



double EurOption::PricebyCrr(BinModel Model)
{
    double q = Model.RiskNeutProb();
    int N = GetN();
    vector<double> Price(N+1);
    for(int i = 0; i<=N; i++)
        Price[i] = Payoff(Model.S(N,i));
    for(int n = N-1; n>=0; n--)
    {for(int i = 0; i<=n; i++)
        Price[i] = (q*Price[i+1]+(1-q)*Price[i])/(1+Model.GetR());
    }
    return Price[0];
}

double EurOption::PricebyCrrhw06(BinModel Model, BinLattice<double> &PriceTree, BinLattice<double> &DeltaTree, BinLattice<double> &BorrowTree)//之所以要写BinLattice<double> &PriceTree, BinLattice<double> &DeltaTree, BinLattice<double> &BorrowTree。是因为BinLattice是一个Template，需要声明一遍，这样计算机才会复制相应的函数。
{
    int N = GetN();
    double q = Model.RiskNeutProb();
    PriceTree.SetN(N);//不需要写double！
    DeltaTree.SetN(N-1);//注意！！！没有那么多！最后一竖列没有！
    BorrowTree.SetN(N-1);
    
    for(int i = 0; i<=N; i++)
    {PriceTree.SetNode(N,i,Payoff(Model.S(N,i)));}
    
    double P;
    double D;
    double B;
    
    for(int n = N-1; n>=0 ; n--)//注意！n不能从最后一竖列开始！要从倒数第二个竖列开始 N-1!!
    {
        for(int i = 0; i<=n; i++)
        {
            P = (q*PriceTree.GetNode(n+1,i+1)+(1-q)*PriceTree.GetNode(n+1,i))/(1+Model.GetR());
            //不能写成！P = (q*PriceTree[i+1]+(1-q)*PriceTree[i])/(1+Model.GetR());
            PriceTree.SetNode(n,i,P);
            
            D = (PriceTree.GetNode(n+1,i+1)-PriceTree.GetNode(n,i))/(Model.S(n+1,i+1)-Model.S(n,i));
            DeltaTree.SetNode(n,i,D);
            
            B = (PriceTree.GetNode(n+1,i)-DeltaTree.GetNode(n,i)*Model.S(n+1,i));
            BorrowTree.SetNode(n,i,B);
        }
        
    }
    
    return DeltaTree.GetNode(0,0)*Model.S(0,0)+BorrowTree.GetNode(0,0);
}
