//
//  Queue.c
//  DataStructure
//
//  Created by Daniel on 15/9/23.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "Queue.h"

int tail=12,head=7,length=12;
void enqueue(int *Q,int x)
{
    Q[tail] = x;
    if (tail == length)
    {
        tail=1;
    }
    else
    {
        tail += 1;
    }
}
int dequeue(int *Q)
{
    int x = Q[head];
    if (head == length)
        head=1;
    else
        head += 1;
    return x;
}
_Bool queueEmpty(int *Q)
{
    if (head==tail)
        return true;
    else
        return false;
}