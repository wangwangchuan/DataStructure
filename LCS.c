//
//  LCS.c
//  DataStructure
//
//  Created by Daniel on 16/1/22.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#include "LCS.h"
#define lengthX 5
#define lengthY 5
int * LCS_LENGTH(int *X,int *Y)
{
    int m = lengthX;
    int n = lengthY;
    int i,j;
    int c[lengthX][lengthY] = {0};
    char b[lengthX][lengthY] = {'a'};
    for (i=0; i<=m; i++) {
        c[i][0] = 0;
    }
    for (j=0; j<=n; j++) {
        c[0][j] = 0;
    }
    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i-1][j-1] +1;
                b[i][j] = "↖︎";
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = "↑";
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = "←";
            }
        }
    }
    return c; //and b;
}

void Print_LCS(int **b,int *X,int i,int j)
{
    if (i==0 || j==0) {
        return ;
    }
    if (b[i][j] == "↖︎") {
        Print_LCS(b, X, i-1, j-1);
        printf("%d",X[i]);
    }
    else if (b[i][j] =="↑")
    {
        Print_LCS(b, X, i-1, j);
    }
    else
    {
        Print_LCS(b, X, i, j-1);
    }
}