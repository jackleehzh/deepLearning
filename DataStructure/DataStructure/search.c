//
//  search.c
//  DataStructure
//
//  Created by 李印臣 on 2019/3/24.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "search.h"

int binSearch(int a[], int x, int lo, int hi){
    int m;
    
    if(hi < 0 || lo > hi) return -1;
    m = (lo + hi) >> 1;
    
    if(a[m] == x) {
        return m;
    }else if(a[m] > x){
        return binSearch(a, x, lo, m - 1);
    }else{
        return binSearch(a, x, m + 1, hi);
    }
}
