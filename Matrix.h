//
//  Matrix.h
//  DataStructure
//
//  Created by Daniel on 16/1/14.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

#include <stdio.h>
typedef struct{
    int **M;
    int m;
    int n;
}Matrix;
Matrix initialMatrix(Matrix C,int m,int n);
void destoryMatrix(Matrix C);
Matrix Matrix_multiply(Matrix,Matrix);
int** Matrix_Chain_Order(int p[]);
//递归算法
int Recursive_Matrix_Chain(int p[],int i,int j);
//备忘录版本
Memoized_Matrix_Chain(int p[]);
#endif /* Matrix_h */
