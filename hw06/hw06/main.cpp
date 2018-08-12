//
//  main.cpp
//  hw06
//
//  Created by 陈贝茜 on 2017/10/21.
//  Copyright © 2017年 陈贝茜. All rights reserved.
//

#include "BinModel 01.hpp"
#include "BinLattice.hpp"
#include "Option.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    BinModel Model;
    if(Model.GetInputData()==1)
        return 1;
    
    ofstream fout;
    fout.open("/Users/bessie.chan/Desktop/nyu/courses/6883 financial computing/hw/for submission/final hw06/hw06/Results06.txt");
    
    Call Call1;
    Call1.GetInputData();
    
    BinLattice<double> PriceTree;
    BinLattice<double> DeltaTree;
    BinLattice<double> BorrowTree;
    
    fout<<"S0 = "<<Model.GetS0()<<endl<<"U = "<<Model.GetU()<<endl<<"D = "<<Model.GetD()<<endl;
    fout<<"R = "<<Model.GetR()<<endl;
    
    fout<<"N = "<<Call1.GetN()<<endl;
    fout<<"K = "<<Call1.GetK()<<endl;
    
    fout<<"European Call prices by PriceByCRR: "<<Call1.PricebyCrr(Model)<<endl<<endl;
    
    fout<<"European Call prices by PriceByCRRhw06: "<<Call1.PricebyCrrhw06(Model,PriceTree,DeltaTree,BorrowTree)<<endl<<endl;
    
    fout<<"Stock positions in replicating strategy:"<<endl<<endl;
    DeltaTree.display(fout);
    
    fout<<"Money market account positions in replicating strategy:"<<endl<<endl;
    BorrowTree.display(fout);
    
    
    
    Put Put1;
    Put1.GetInputData();
    
    BinLattice<double> PriceTree2;
    BinLattice<double> DeltaTree2;
    BinLattice<double> BorrowTree2;
    
    fout<<"N = "<<Put1.GetN()<<endl;
    fout<<"K = "<<Put1.GetK()<<endl;
    
    fout<<"European Put prices by PriceByCRR: "<<Put1.PricebyCrr(Model)<<endl<<endl;
    
    fout<<"European Put prices by PriceByCRRhw06: "<<Put1.PricebyCrrhw06(Model,PriceTree2,DeltaTree2,BorrowTree2)<<endl<<endl;
    
    fout<<"Stock positions in replicating strategy:"<<endl<<endl;
    DeltaTree2.display(fout);
    
    fout<<"Money market account positions in replicating strategy:"<<endl<<endl;
    BorrowTree2.display(fout);

    return 0;
    
}
