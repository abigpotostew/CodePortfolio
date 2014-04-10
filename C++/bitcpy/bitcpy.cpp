//
//  bitcpy.cpp
//  FreeRangeInterviewTest
//
//  Created by Stewart Bracken on 2/5/14.
//  Copyright (c) 2014 Stewart Bracken. All rights reserved.
//

#include "bitcpy.h"


void bitcpy(void* src, void* dst, int numBits){
    char* srcC = static_cast<char*>(src);
    char* dstC = static_cast<char*>(dst);
    // Copy as many bytes as possible
    while (numBits >= 8){
        numBits -= 8;
		*dstC = *static_cast<char*>(srcC); //copy 1 byte at a time into dst
		srcC++;
        dstC++;
    }
    // Copy the remianing bits using bit operators
    if (numBits > 0 ){
		char mask = 1 << 7; //with a one in the most significant bit position
		while (numBits > 0){
			char result = mask & *srcC;
			if ( result )
				*dstC |= result; //set it
			else
				*dstC &= ~(mask); //clear it
            numBits--;
            mask >>= 1;
        }
    }
}