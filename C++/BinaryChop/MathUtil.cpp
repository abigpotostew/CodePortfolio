//
//  MathUtil.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/9/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include "MathUtil.h"

//This function has possible overflow from dividend + divisor
static int div_ceil_overflow(int dividend, int divisor){
    return (dividend + divisor - 1) / divisor;
}

int div_ceil(int dividend, int divisor){
    if(dividend == 0)
        return div_ceil_overflow(dividend, divisor);
    return 1 + ((dividend - 1) / divisor); // if x != 0
}