//
//  TimeSlice.cpp
//  QTree
//
//  Created by Zhe on 9/17/16.
//  Copyright © 2016 Zhe. All rights reserved.
//

#include "TimeSlice.hpp"

TimeSlice::TimeSlice(int index) : tsIndex(index)
{
}

int TimeSlice::getIndex()
{
    return tsIndex;
}

void TimeSlice::calcPayoffAllNode(TimeSlice& nextTS)
{
    for(auto itr = nodeList.begin(); itr!= nodeList.end(); itr++)
    {
        (*itr).priceOptFromNodes(nextTS);
    }
}

double TimeSlice::getNodeUnderlyingValue(int nodeIndex)
{
    throw;
}

double TimeSlice::getNodeInstrumentValue(int nodeIndex)
{
    throw;
}

double TimeSlice::getRootInstrumentValue()
{
    assert(tsIndex == 0);
    return nodeList.front().getInstrumentValue();
}