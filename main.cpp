//
//  main.c
//  DataStructure
//
//  Created by Daniel on 15/9/23.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include <iostream>
//#include "Matrix.h"
#include "BinaryTree.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree Tree;
    BiTree T;
    Tree.CreateBitTree(T);
    //Tree.InOrderTraverse(T);
    //Tree.InOrderTraverseST(T);
    //Tree.PreOrderTraverseRec(T);
    //Tree.PostOrderTraverseRec(T);
    //Tree.PostOrderTraverseRec2(T);
    //Tree.Copy(T, NewT);
    Tree.LevelOrderTraverse(T);
    int depth = Tree.Depth(T);
    int nodeCount = Tree.NodeCount(T);
    int node0Count = Tree.Node0Count(T);
    int node1Count = Tree.Node1Count(T);
    int node2Count = Tree.Node2Count(T);
    cout<<"\n"<<depth<<"\n"<<nodeCount<<"\n"<<node0Count<<"\n"<<node1Count<<"\n"<<node2Count;
    
//    int i,j;
//    Matrix A;
//    Matrix B;
//    int arrayA[2][3]={{1,0,2},{-1,3,1}};
//    int arrayB[3][2]={{3,1},{2,1},{1,0}};
    //创建**pp表示的二维数组的方法两种：
    //1.创建指针数组，进行赋值**p；
    //int *arrayP[3] = {arrayA[0],arrayA[1]};
    //A.M = arrayP;
    //2.动态申请，将数组行地址赋值于*(p+i);
//    A.M = (int **)malloc(2 * sizeof(int *));
//    for ( i = 0; i<2; i++) {
//        A.M[i] = arrayA[i];
//    }
    //    A.m = 2;
    //    A.n = 3;
//    A=initialMatrix(A, 2, 3);
//
//    B=initialMatrix(B, 3, 2);
//    for (i =0; i<A.m; i++) {
//        for (j=0; j<A.n; j++) {
//            A.M[i][j] = arrayA[i][j];
//        }
//    }
//    for (i =0; i<B.m; i++) {
//        for (j=0; j<B.n; j++) {
//            B.M[i][j] = arrayB[i][j];
//        }
//    }
//    Matrix C=Matrix_multiply(A, B);
//    for (i=0; i<C.m; i++) {
//        for (j=0; j<C.n; j++) {
//            printf("%d--",C.M[i][j]);
//        }
//        printf("\n");
//    }
//    destoryMatrix(A);
//    destoryMatrix(B);
//    destoryMatrix(C);
    
    return 0;
}



