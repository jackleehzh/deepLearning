//
//  main.c
//  DataStructure
//
//  Created by 李印臣 on 2019/3/19.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include <stdio.h>

#include "sort.h"
#include "maths.h"

void printSort(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d%c", a[i], i == n - 1?'\n':' ');
    }
}

int main(int argc, const char * argv[]) {
    
    int a[] = {4, 5, 2, 1, 3};
    int n = 13;
    //bubbleSort(a, n);
    //reverse(a, 0, 4);
    //reverseSort(a, 0, 4);
    //printSort(a, n);
    while(n > -1){
        printf("%d\n", powers(2, n));
        n--;
    }

    return 0;
}
