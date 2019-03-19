//
//  Sort.c
//  DataStructure
//
//  Created by 李印臣 on 2019/3/19.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "sort.h"

void bubbleSort(int  a[], int n){
    int i, j, tmp;
    
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    
    for(i = 0; i < n; i++){
        printf("%d%c", a[i], i == n - 1?'\n':' ');
    }
}
