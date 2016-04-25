//
//  List.h
//  DataStructure
//
//  Created by Daniel on 15/9/23.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#ifndef __DataStructure__List__
#define __DataStructure__List__

#include <stdio.h>

struct node
{
    struct node *pre;
    struct node *next;
    int key;
};

struct node * list_search(struct node *head,int k);

struct node * list_insert(struct node *head,struct node *x);

struct node * list_delete(struct node *head,struct node *x);

void list_print(struct node *head);

#endif /* defined(__DataStructure__List__) */
