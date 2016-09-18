//
//  Tree.cpp
//  QTree
//
//  Created by Zhe on 9/17/16.
//  Copyright © 2016 Zhe. All rights reserved.
//

#include "Tree.hpp"

Tree::Tree():
    treeModel(BLACKSCHOLES),
    treeInstrument(EUROPEANCALL),
    steps(252),
    maturity(1),
    dt(maturity/steps)
{
    
}

void Tree::genGridAndDrift()
{
    throw;
}

void Tree::buildTree()
{
    TimeSlice rootTS(0);
    tsList.push_back(rootTS);
    
    int tsIndex = 1;
    for(auto itr = tsList.begin(); itr!=tsList.end(); itr++)
    {
        TimeSlice nextTS(tsIndex);
        (*itr).generateNextTS(nextTS);
        tsList.push_back(nextTS);
        tsIndex++;
    }
}

void Tree::calcPayoff()
{
    auto r_itr = ++tsList.rbegin();
    assert((*r_itr).getIndex() == steps - 2);   // make sure starts with the second last TS
    
    // pricing instrument, needs to go through from the second last ts to the root ts,
    // pass the next ts as a parameter for pricing the current ts
    for(r_itr; r_itr!=tsList.rend(); r_itr++)
    {
        TimeSlice nextTS = *(r_itr--);
        assert(nextTS.getIndex() - 1 == (*r_itr).getIndex());
        (*r_itr).calcPayoffAllNode(nextTS);
    }
}

double Tree::getInstrumentFinalPrice()
{
    return tsList.front().getRootInstrumentValue();
}

