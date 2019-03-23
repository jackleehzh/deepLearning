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

void reverse0(int a[], int lo, int hi){
    if(lo < hi){
        swap(&a[lo], &a[hi]);
        reverse(a, lo + 1, hi - 1);
    }
}

void reverse(int a[], int lo, int hi){
    int i;
    //for(i = m; i <=(n - m) / 2; i++){
    // or
    for(i = lo; i < hi - i + lo; i++){
        swap(&a[i], &a[hi - i + lo]);
    }
}

void reverseSort(int a[], int lo, int hi){
    int i, mid;
    for(i = lo; i < hi - i + lo; i++){
        if(a[i] > a[hi - i + lo])
            swap(&a[i], &a[hi - i + lo]);
    }
    
    mid = (hi + lo) / 2;
    if(lo < mid){
        reverseSort(a, lo, mid);
    }
    if(mid + 1 < hi){
        reverseSort(a, mid + 1, hi);
    }
}
