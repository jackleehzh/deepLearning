//
//  math.c
//  DataStructure
//
//  Created by 李印臣 on 2019/3/19.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "maths.h"

int powers0(int a, int n){
    if(n == 0) return 1;
    if(n == 1) return a;
    if(n % 2 == 0){
        return powers(a, n / 2) * powers(a, n / 2);
    }else{
        return 2 * powers(a, n / 2) * powers(a, n / 2);
    }
}

int powers1(int a, int n){
    int result = 1;
    int i;
    for(i = 0; i < n; i++){
        result = result * a;
    }
    return result;
}

int powers(int a, int n){
    int result = 1;
    int tmp = a;
    int i;
    
    if(n == 0) return 1;
    if(n == 1) return a;
    
    while(n > 1){
        if(n % 2 == 0){
            tmp = tmp * tmp;
            n = n / 2;
        }else{
            result = result * tmp;
            n = n - 1;
        }
    }
    result = result * tmp;
    return result;
}
