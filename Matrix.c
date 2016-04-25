//
//  Matrix.c
//  DataStructure
//
//  Created by Daniel on 16/1/14.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#include "Matrix.h"
#include "stdlib.h"
Matrix initialMatrix(Matrix C,int m,int n)
{
    int i;
    C.M = (int **)malloc(m * sizeof(int *));
    for ( i = 0; i<m; i++) {
        C.M[i] = (int *)malloc(n * sizeof(int));
    }
    C.m = m;
    C.n = n;
    return C;
}

void destoryMatrix(Matrix C)
{
    for (int i = 0; i<C.m; i++) {
        free(C.M[i]);
    }
    free(C.M);
}

Matrix Matrix_multiply(Matrix A,Matrix B)
{
    int i,j,k;
    Matrix C;
    C=initialMatrix(C, A.m, B.n);
    if (A.n != B.m) {
        printf("Error Matrix");
        return C;
    }
    else
    {
        for (i=0;i<A.m; i++) {
            for (j=0; j<B.n; j++) {
                C.M[i][j] = 0;
                for (k=0; k<A.n; k++) {
                    C.M[i][j] = C.M[i][j] + A.M[i][k] * B.M[k][j];
                }
            }
        }
        return C;
    }
}
//动态规划－－矩阵链乘积
#define length 10
int** Matrix_Chain_Order(int p[])
{
    int i,j,k,l,n;
    int q;
    n=length-1;
    int m[n][n];
    int s[n][n];
    for (i=1; i<n; i++) {
        m[i][i] = 0;
    }
    for (l=2; l<n; l++) {   //l is the chain length
        for (i=1; i<n-l+1; i++) {
            j=i+l-1;
            m[i][j] = INT16_MAX;
            for (k=i;k<=j-1; k++) {
                q=m[i][k] +m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q<m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m; //and s
}

//递归算法
int Recursive_Matrix_Chain(int p[],int i,int j)
{
    int q;
    if (i==j)
        return 0;
    int m[10][10];
    m[i][j] = INT16_MAX;
    for (int k=i; k<=j-1; k++) {
        q= Recursive_Matrix_Chain(p, i, k) +
        Recursive_Matrix_Chain(p, k+1, j) +
        p[i-1]*p[k]*p[j];
        if (q < m[i][j]) {
            m[i][j] = q;
        }
    }
    return m[i][j];
}
int LookUp_Chain(int p[],int i,int j);
//备忘录版本
int Memoized_Matrix_Chain(int p[])
{
    int n = length-1;
    int m[n][n];
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            m[i][j] = INT16_MAX;
        }
    }
    return LookUp_Chain(p,1,n);
}

int LookUp_Chain(int p[],int i,int j)
{
    int m[10][10];
    int q;
    if (m[i][j] < INT16_MAX) {
        return m[i][j];
    }
    if (i==j) {
        m[i][j] = 0;
    }
    else
    {
        for (int k = i;k<=j-1; k++) {
            q= LookUp_Chain(p,i,k)+
            LookUp_Chain(p, k+1, j)+
            p[i-1]*p[k]*p[j];
            if (q<m[i][j]) {
                m[i][j] = q;
            }
        }
    }
    return m[i][j];
}

void Print_Optimal_pARNS(int **s,int i,int j)
{
    if (i==j) {
        printf("%c",'A');
    }
    else
    {
        Print_Optimal_pARNS(s,i,s[i][j]);
        Print_Optimal_pARNS(s, s[i][j]+1, j);
        printf("%c",')');
        
    }
}
