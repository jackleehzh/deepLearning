//
//  Sort.c
//  DataStructure
//
//  Created by 李印臣 on 2019/3/19.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "sort.h"
#define bool int
#define true 1
#define false 0

void bubbleSort(int  a[], int n){
    int i, j;
    
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(&a[i], &a[j]);
            }
        }
    }
}

void bubbleSort1(int  a[], int n){
    int i;
    bool sorted = false;
    
    while(!sorted){
        sorted = true;
        for(i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                swap(&a[i], &a[i + 1]);
                sorted = false;
            }
        }
        n--;
    }
}
