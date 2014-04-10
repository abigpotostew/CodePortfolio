//
//  ListKTest_unittest.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/5/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <gtest/gtest.h>

#include "List.h"
//include the template implementation
#include "List.cpp"

TEST(ListKTest, SkipKReverseK){
    List<int> list;
    for(int i = 0; i < 20; ++i){
        list.insert_back(i+1);
    }
    list.print();
    list.reverse_k(20);
    list.print();
    
}
