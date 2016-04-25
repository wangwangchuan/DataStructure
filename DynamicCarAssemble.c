//
//  DynamicCarAssemble.c
//  DataStructure
//
//  Created by Daniel on 16/1/12.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#include "DynamicCarAssemble.h"
int**  Fastest_Way(int ab[3][6],int tt[3][5],int n)
{
    int e1=2,e2=4,x1=3,x2=2,f,l;
    
    int **lt,i,j;
    lt = (int**)malloc(3*sizeof(int*));
    for(i=0;i<3;++i)
    {
        lt[i] = (int*)malloc(6*sizeof(int));
        for(j=0;j<6;++j)
        {
            lt[i][j]=0;
        }
    }
    int *f1 = (int *)malloc(sizeof(int) *n);
    int *f2 = (int *)malloc(sizeof(int) *n);
    f1[1] = e1+ab[1][1];
    f2[1] = e2+ab[2][1];
    for (j=2; j<n; j++) {
        if (f1[j-1] +ab[1][j] <= f2[j-1] + tt[2][j-1] +ab[1][j]) {
            f1[j] = f1[j-1] + ab[1][j];
            lt[1][j] = 1;
        }
        else
        {
            f1[j] = f2[j-1] +tt[2][j-1] + ab[1][j];
            lt[1][j] = 2;
        }
        if (f2[j-1]+ab[2][j] <= f1[j-1] +tt[1][j-1] + ab[2][j]) {
            f2[j] = f2[j-1]+ab[2][j];
            lt[2][j] = 2;
        }
        else
        {
            f2[j] = f1[j-1]+tt[1][j-1] + ab[2][j];
            lt[2][j] = 1;
        }
    }
    if (f1[n] + x1 <= f2[n] +x2) {
        f = f1[n] +x1;
        l = 1;
    }
    else
    {
        f = f2[n] + x2;
        l = 2;
    }
    return lt;
}

void Print_Stations (int **l,int lf,int n)
{
    int i = lf;
    printf("line->%d,station->%d\n",i,n);
    for (int j=n-1; j>=1; j--) {
        i = l[i][j];
        printf("line->%d,station->%d\n",i,j);
    }
}
