//
//  BinaryChop.h
//  CppTests
//
//  Created by Stewart Bracken on 12/8/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewTests_BinaryChop_h
#define InterviewTests_BinaryChop_h

#include <vector>

#define NOT_FOUND -1

//These all should return the same value if supplied equivalent args
namespace BinaryChop {
    //Iterative - pretty fast!
    int chop1(int to_find, const std::vector<int>& data);
    //Tail Recursive - fast!
    int chop2(int to_find, const std::vector<int>& data);
    //vector slicing - slow due to data copying.
    int chop3(int to_find, const std::vector<int>& data);
    //concurrent searching - slow
    int chop4(int to_find, const std::vector<int>& data);
    //iterative with deferred equality
    int chop5(int to_find, const std::vector<int>& data);
    //attempt to speed up recursive chop
    int chop6(int to_find, const std::vector<int>& data);
}

#endif
