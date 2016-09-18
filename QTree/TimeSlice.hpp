//
//  TimeSlice.hpp
//  QTree
//
//  Created by Zhe on 9/17/16.
//  Copyright © 2016 Zhe. All rights reserved.
//

#ifndef TimeSlice_hpp
#define TimeSlice_hpp

#include <stdio.h>
#include <list>
#include "Node.hpp"

using namespace std;

class TimeSlice
{
public:
    TimeSlice(int index);
    void generateNextTS(TimeSlice& nextTS);
    double getNodeUnderlyingValue(int nodeIndex);   // retrieve the node index for pricing
    double getNodeInstrumentValue(int nodeIndex);
    double getRootInstrumentValue();
    int getIndex();
    void calcPayoffAllNode(TimeSlice& nextTS);
    
private:
    list<Node> nodeList;
    double grid;
    double drift;
    int tsIndex;    // which ts it is in the tree
};


#endif /* TimeSlice_hpp */
