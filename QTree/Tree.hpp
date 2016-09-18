//
//  Tree.hpp
//  QTree
//
//  Created by Zhe on 9/17/16.
//  Copyright © 2016 Zhe. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <list>
#include <stdio.h>
#include "TimeSlice.hpp"

using namespace std;

class Tree
{
private:
    enum Model
    {
        BLACKSCHOLES,
        HESTON,
        THREEOVERTWO,
        HULLWHITE
    };
    Model treeModel;
    
    enum Instrument
    {
        EUROPEANCALL,
        EUROPEANPUT,
        AMERICANCALL,
        AMERICANPUT,
        VARIANCESWAP
    };
    Instrument treeInstrument;
    
public:
    Tree();
    void genGridAndDrift();
    void buildTree();
    void calcPayoff();
    double getInstrumentFinalPrice();
    
private:
    int steps;
    double maturity;
    double dt;
    list<double> gridList;
    list<double> driftList;
    list<TimeSlice> tsList;
};

#endif /* Tree_hpp */
