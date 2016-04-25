//
//  BST.c
//  DataStructure
//
//  Created by Daniel on 16/1/25.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#include "BST.h"
void Optimal_BST(int *p,int *q,int n)
{
    int i,j,l,r,t;
    int e[n+2][n+1];
    int w[n+2][n+1];
    int root[n+2][n+1];
    for (i=1; i<=n+1; i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for (l=1; l<=n; l++) {
        for (i=1; i<=n-l+1; i++) {
            j = i+l-1;
            e[i][j] = INT16_MAX;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (r=i; r<=j; r++) {
                t = e[i][r-1] +e[r+1][j] + w[i][j];
                if (t<e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    //return e and root;
}