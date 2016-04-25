//
//  List.c
//  DataStructure
//
//  Created by Daniel on 15/9/23.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "List.h"

struct node *list_search(struct node *head,int k)
{
    struct node *x = head;
    while (x != NULL && x->key != k)
        x = x->next;
    return x;
}

struct node * list_insert(struct node *head,struct node *x)
{
    x->next = head;
    if (head != NULL)
        head->pre = x;
    head = x;
    x->pre = NULL;
    return head;
}

struct node * list_delete(struct node *head,struct node *x)
{
    if (x->pre !=NULL)
        x->pre->next = x->next;
    else
        head = x->next;
    if (x->next != NULL)
        x->next->pre = x->pre;
    return head;
}

void list_print(struct node *head)
{
    struct node *x = head;
    while (x != NULL)
    {
        printf("%d--",x->key);
        x = x->next;
    }
    printf("\n");
}