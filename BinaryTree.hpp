//
//  BinaryTree.hpp
//  DataStructure
//
//  Created by Daniel on 16/4/13.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

typedef char TelemType;
typedef struct BitNode{
    TelemType data;
    struct BitNode *lchild,*rchild;
}BitNode; 
typedef BitNode *BiTree;
class BinaryTree {
public:
    void PreOrderTraverse(BiTree T);
    void PreOrderTraverseRec(BiTree T);
    void InOrderTraverse(BiTree T);
    void InOrderTraverseST(BiTree T);
    void PostOrderTraverse(BiTree T);
    void PostOrderTraverseRec(BiTree T);
    void PostOrderTraverseRec2(BiTree T);
    void LevelOrderTraverse(BiTree T);
    void CreateBitTree(BiTree &T);
    void Copy(BiTree T,BiTree &NewT);
    int Depth(BiTree T);
    int NodeCount(BiTree T);
    int Node0Count(BiTree T);
    int Node1Count(BiTree T);
    int Node2Count(BiTree T);
    void DestoryBitTree(BiTree &T);
    
};
#endif /* BinaryTree_hpp */
