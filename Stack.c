//
//  Stack.c
//  DataStructure
//
//  Created by Daniel on 15/9/23.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "Stack.h"


int top=0;

_Bool stackEmpty(int *S)
{
    if (top == 0)
        return true;
    else
        return false;
}

void push (int *S,int x)
{
    top += 1;
    S[top] = x;
}

int pop (int *S)
{
    if (stackEmpty(S))
    {
        printf("underflow");
        return INT16_MAX;
    }
    else
    {
        top -= 1;
        return S[top+1];
    }
}