//
// Created by xdnzx on 2018/12/11.
//

#ifndef SZ_BITHOLDER_H
#define SZ_BITHOLDER_H

#include "stdint.h"
#include <stdio.h>

struct BitHolder{
    uint8_t holder[3];
};

static int BitHolderGetRequiredCount(int dataCount){
    return ((dataCount-3)%8) ? (dataCount-3)/8+1 : (dataCount-3)/8;
}

static void BitHolderAddRecord(struct BitHolder* bitHolder, int index, int record){
    int BHindex = index / 8;
    int BHoffset = index % 8;
    switch (BHoffset){
        case 0:
            bitHolder[BHindex].holder[0] += record << 5;
            break;
        case 1:
            bitHolder[BHindex].holder[0] += record << 2;
            break;
        case 2:
            bitHolder[BHindex].holder[0] += record >> 1;
            bitHolder[BHindex].holder[1] += record << 7;
            break;
        case 3:
            bitHolder[BHindex].holder[1] += record << 4;
            break;
        case 4:
            bitHolder[BHindex].holder[1] += record << 1;
            break;
        case 5:
            bitHolder[BHindex].holder[1] += record >> 2;
            bitHolder[BHindex].holder[2] += record << 6;
            break;
        case 6:
            bitHolder[BHindex].holder[2] += record << 3;
            break;
        case 7:
            bitHolder[BHindex].holder[2] += record;
            break;
    }
}

static int BitHolderGetRecord(struct BitHolder* bitHolder, int index){
    int BHindex = index / 8;
    int BHoffset = index % 8;
    uint8_t method = 0;
    struct BitHolder test = bitHolder[BHindex];
    switch (BHoffset){
        case 0:
            method = (bitHolder[BHindex].holder[0] >> 5);
            break;
        case 1:
            method = bitHolder[BHindex].holder[0] << 3;
            method = method >> 5;
            break;
        case 2:
            method = bitHolder[BHindex].holder[0] << 6;
            method = (method >> 5);
            method += bitHolder[BHindex].holder[1] >> 7;
            break;
        case 3:
            method = (bitHolder[BHindex].holder[1] << 1);
            method = method >> 5;
            break;
        case 4:
            method = (bitHolder[BHindex].holder[1] << 4);
            method = method >> 5;
            break;
        case 5:
            method = (bitHolder[BHindex].holder[1] << 7);
            method = (method >> 5);
            method += bitHolder[BHindex].holder[2] >> 6;
            break;
        case 6:
            method = (bitHolder[BHindex].holder[2] << 2);
            method = method >> 5;
            break;
        case 7:
            method = (bitHolder[BHindex].holder[2] << 5);
            method = method >> 5;
            break;
    }
    return method;
}

static struct BitHolder* BitHolderGetByte(struct BitHolder* bitHolder, int index){
    int BHindex = index / 8;
    int BHoffset = index % 8;
    return &bitHolder[BHindex];
}

#endif //SZ_BITHOLDER_H
