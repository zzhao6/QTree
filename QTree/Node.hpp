//
//  Node.hpp
//  QTree
//
//  Created by Zhe on 9/17/16.
//  Copyright © 2016 Zhe. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <list>
#include <cassert>
using namespace std;

class TimeSlice;

class Node
{
public:
    Node();
    void setProb(double _prob[4]);
    void priceOptFromNodes(TimeSlice& nextTS);
    double getInstrumentValue();
    double getUnderlyingValue();
    
private:
    double instrumentValue;
    double underlyingValue;
    double probs[4];
    enum Case
    {
        CASE1,
        CASE2
    }nodeCase;
    
    double magicP;
    double delta;   // closest distance to the successors
                    // decide the cases
    
    // very important, this identifies the position of child nodes
    int childNodeIndexInNextTimeSlice[4];
    
    
};

#endif /* Node_hpp */
