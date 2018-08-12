//
//  Option.cpp
//  hw06
//
//  Created by 陈贝茜 on 2017/10/21.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "Option.hpp"
#include "BinLattice.hpp"
#include "BinModel 01.hpp"
#include <iostream>
#include <cmath>

using namespace std;

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

double EurOption::PricebyCrrhw06(BinModel Model, BinLattice<double> &PriceTree, BinLattice<double> &DeltaTree, BinLattice<double> &BorrowTree)
{
    int N = GetN();
    double q = Model.RiskNeutProb();
    PriceTree.SetN(N);
    DeltaTree.SetN(N-1);
    BorrowTree.SetN(N-1);
    
    for(int i = 0; i<=N; i++)
    {PriceTree.SetNode(N,i,Payoff(Model.S(N,i)));}
    
    double P;
    double D;
    double B;
    
    for(int n = N-1; n>=0 ; n--)
    {
        for(int i = 0; i<=n; i++)
        {
            P = (q*PriceTree.GetNode(n+1,i+1)+(1-q)*PriceTree.GetNode(n+1,i))/(1+Model.GetR());
            PriceTree.SetNode(n,i,P);
            
            D = (PriceTree.GetNode(n+1,i+1)-PriceTree.GetNode(n+1,i))/(Model.S(n+1,i+1)-Model.S(n+1,i));
            DeltaTree.SetNode(n,i,D);
            
            B = (PriceTree.GetNode(n+1,i)-DeltaTree.GetNode(n,i)*Model.S(n+1,i))/(1+Model.GetR());
            BorrowTree.SetNode(n,i,B);
        }
        
    }
    
    return DeltaTree.GetNode(0,0)*Model.S(0,0)+BorrowTree.GetNode(0,0);
}

int Call::GetInputData()
{
    cout<<"Enter call option data:" << endl;
    int N;
    cout<<"Enter steps to expiry N: ";
    cin>>N;
    SetN(N);
    cout<<"Enter strike price K: ";
    cin>>K;
    cout<<endl;
    return 0;
}

double Call::Payoff(double z)
{
    if (z>K) return z-K;
    return 0.0;
}

int Put::GetInputData()
{
    cout<<"Enter put option data:" << endl;
    int N;
    cout<<"Enter steps to expiry N: ";
    cin>>N;
    SetN(N);
    cout<<"Enter strike price K: ";
    cin>>K;
    cout<<endl;
    return 0;
}
double Put::Payoff(double z)
{
    if (z<K) return K-z;
    return 0.0;
}
