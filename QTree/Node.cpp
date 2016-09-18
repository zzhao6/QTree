//
//  Node.cpp
//  QTree
//
//  Created by Zhe on 9/17/16.
//  Copyright © 2016 Zhe. All rights reserved.
//

#include "Node.hpp"
#include "TimeSlice.hpp"

Node::Node() :
    instrumentValue(0),
    underlyingValue(0),
    nodeCase(CASE1),
    magicP(1/8),
    delta(0)
{
    childNodeIndexInNextTimeSlice[0] = 0;
    childNodeIndexInNextTimeSlice[1] = 0;
    childNodeIndexInNextTimeSlice[2] = 0;
    childNodeIndexInNextTimeSlice[3] = 0;
    
    probs[0] = 0;
    probs[1] = 0;
    probs[2] = 0;
    probs[3] = 0;
}

void Node::priceOptFromNodes(TimeSlice& nextTS)
{
    assert(probs[0] + probs[1] + probs[2] + probs[3] == 1);
    
    double successorUnderlyingValues[4];
    successorUnderlyingValues[0] = nextTS.getNodeUnderlyingValue(childNodeIndexInNextTimeSlice[0]);
    successorUnderlyingValues[1] = nextTS.getNodeUnderlyingValue(childNodeIndexInNextTimeSlice[1]);
    successorUnderlyingValues[2] = nextTS.getNodeUnderlyingValue(childNodeIndexInNextTimeSlice[2]);
    successorUnderlyingValues[3] = nextTS.getNodeUnderlyingValue(childNodeIndexInNextTimeSlice[3]);
    
    instrumentValue =
        probs[0] * successorUnderlyingValues[0] +
        probs[1] * successorUnderlyingValues[1] +
        probs[2] * successorUnderlyingValues[2] +
        probs[3] * successorUnderlyingValues[3];
}

void Node::setProb(double _probs[4])
{
    probs[0] = _probs[0];
    probs[1] = _probs[1];
    probs[2] = _probs[2];
    probs[3] = _probs[3];
}

double Node::getInstrumentValue()
{
    return instrumentValue;
}

double Node::getUnderlyingValue()
{
    return underlyingValue;
}
