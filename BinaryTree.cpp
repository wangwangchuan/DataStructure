//
//  BinaryTree.cpp
//  DataStructure
//
//  Created by Daniel on 16/4/13.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#include "BinaryTree.hpp"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void BinaryTree::PreOrderTraverseRec(BiTree T)
{
    BitNode *p,*q;
    stack<BitNode *>S;
    p = T;
    while(p||!S.empty()) {
        if (p) {
            S.push(p);
            cout<<p->data;
            p=p->lchild;
        }
        else {
            q = S.top();
            S.pop();
            p=q->rchild;
        }
    }
}
void BinaryTree::InOrderTraverse(BiTree T)
{
    if (T) {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
void BinaryTree::InOrderTraverseST(BiTree T)
{
    BitNode *p,*q;
    stack<BitNode *> S;
    p = T;
    while (p||!S.empty()) {
        if (p) {
            S.push(p);
            p= p->lchild;
        }
        else {
            q=S.top();
            S.pop();
            cout<<q->data;
            p=q->rchild;
        }
    }
}
void BinaryTree::PostOrderTraverseRec(BiTree T)
{
    BitNode *p,*q = nullptr;
    p=T;
    stack<BitNode *> S;
    while (p||!S.empty()) {
        while (p) {
            S.push(p);
            p=p->lchild;
        }
        p=S.top();
        
        if (!p->rchild||p->rchild==q) {
            cout<<p->data;
            q=p;
            p=NULL;
            S.pop();
        }
        else {
            p=p->rchild;
        }
    }
}
void BinaryTree::PostOrderTraverseRec2(BiTree T)
{
    BitNode *cur,*pre = NULL;
    cur=T;
    stack<BitNode *> S;
    S.push(cur);
    while (!S.empty()) {
        cur=S.top();
        if ((!cur->lchild&&!cur->rchild)||(pre&&(pre==cur->lchild||pre==cur->rchild))) {
            cout<<cur->data;
            S.pop();
            pre=cur;
        }
        else {
            if (cur->rchild) {
                S.push(cur->rchild);
            }
            if (cur->lchild) {
                S.push(cur->lchild);
            }
        }
    }
}

void BinaryTree::LevelOrderTraverse(BiTree T)
{
    BitNode *p,*t;
    p=T;
    queue<BitNode *>Q;
    Q.push(p);
    while (!Q.empty()) {
        t = Q.front();
        Q.pop();
        cout<<t->data;
        if(t->lchild) {
            Q.push(t->lchild);
        }
        if (t->rchild) {
            Q.push(t->rchild);
        }
    }
}

void BinaryTree::CreateBitTree(BiTree &T)
{
    char ch;
    cin>>ch;
    if (ch == '#') {
        T=NULL;
    }
    else {
        T= new BitNode;
        T->data = ch;
        CreateBitTree(T->lchild);
        CreateBitTree(T->rchild);
    }
}

void BinaryTree::Copy(BiTree T,BiTree &NewT)
{
    if (!T) {
        NewT =NULL;
        return;
    }
    else
    {
        NewT = new BitNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}
int BinaryTree::Depth(BiTree T)
{
    int m,n=0;
    if(!T){
        return 0;
    }
    else {
        m=Depth(T->lchild);
        n=Depth(T->rchild);
        if (m>n) {
            return m+1;
        }
        else
            return n+1;
    }
}

int BinaryTree::NodeCount(BiTree T)
{
    if (T==NULL) {
        return 0;
    }
    else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}
int BinaryTree::Node0Count(BiTree T)
{
    if (!T) {
        return 0;
    }
    
    if (!T->lchild&&!T->rchild) {
        return 1;
    }
    return Node0Count(T->lchild)+Node0Count(T->rchild);
}
int BinaryTree::Node1Count(BiTree T)
{
    int n=0;
    if (!T) {
        return 0;
    }
    
    if ((T->lchild&&!T->rchild)||(T->rchild&&!T->lchild)) {
        n=1;
    }
    return Node1Count(T->lchild)+Node1Count(T->rchild)+n;
}
int BinaryTree::Node2Count(BiTree T)
{
    int n =0;
    if (!T) {
        return 0;
    }
    
    if (T->rchild&&T->lchild) {
        n=1;
    }
    return Node2Count(T->lchild)+Node2Count(T->rchild)+n;
}
void BinaryTree::DestoryBitTree(BiTree &T)
{
    if (T) {
        DestoryBitTree(T->lchild);
        DestoryBitTree(T->rchild);
        delete T;
        T=NULL;
    }
}