//
//  ReverseString_unittest.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include <string>
using namespace std;

//s is a null terminated c-style string
void reverseCStr (char* s){
    char* end = s;
    char* begin = s;
    while( * (end+1) != '\0') end++;
    while (begin != end){
        char tmp = *end;
        *end = *begin;
        *begin = tmp;
        begin++;
        if(begin == end) break;
        end--;
    }
    return;
}

TEST(ReverseCString_unittest, ReverseCString){
    char s[4] = {'a','b','c','\0'};
    std::cout << "Orig: "<< string(s) <<std::endl;
    reverseCStr(s);
    std::cout<< "Result: " << string(s)<<std::endl;
    string str(s);
}