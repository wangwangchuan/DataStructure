//
//  DynamicCarAssemble.h
//  DataStructure
//
//  Created by Daniel on 16/1/12.
//  Copyright © 2016年 Daniel. All rights reserved.
//

#ifndef DynamicCarAssemble_h
#define DynamicCarAssemble_h

#include <stdio.h>
//动态规划之装配线调度
int** Fastest_Way(int ab[3][6],int tt[3][5],int n);

void Print_Stations(int **l,int lf,int n);
#endif /* DynamicCarAssemble_h */
