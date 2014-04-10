//
//  FunctionalVector_unittest.cpp
//  CppPractice
//
//  Created by Stewart Bracken on 12/12/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "FunctionalVector.h"

TEST(FunctionalVector, comprehensive_test){
    FunctionalVector<int> original({1,2,3,4,5});
    FunctionalVector<int> sliced = original;
    sliced.slice(1,3); //slice to indices 1->3s
    ASSERT_EQ(original[1], sliced[0]);
    sliced[0] = 10;
    original[0] = 11;
    std::cout<<"original: "<<original<<std::endl;
    std::cout<<"sliced: "<<sliced<<std::endl;
    FunctionalVector<int> slice_copy = original.slice(2, 4);
    std::cout<<"original: "<<original<<std::endl;
    std::cout<<"slice_copy: "<<slice_copy<<std::endl;
}