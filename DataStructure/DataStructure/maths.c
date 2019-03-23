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
        return powers(a, n >> 1) * powers(a, n >> 1);
    }else{
        return 2 * powers(a, n >> 1) * powers(a, n >> 1);
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

int powers2(int a, int n){
    int result = 1;
    int tmp = a;
    
    if(n == 0) return 1;
    if(n == 1) return a;
    
    while(n > 1){
        if(n & 1){
            result = result * tmp;
        }
        n = n >> 1;
        tmp = tmp * tmp;
    }
    result = result * tmp;
    return result;
}

int powers(int a, int n){
    int tmp;
    if(n == 0) return 1;
    if(n == 1) return a;
    
    tmp = powers(a, n >> 1);
    return (n & 1)? 2 * tmp * tmp : tmp * tmp;
}

int multi(int a, int b){
    int result = 0;
    int tmp;
    
    if(a < b)swap(&a, &b);
    tmp = a;
    
    if(b == 0) return 0;
    if(b == 1) return a;
    
    while(b > 1){
        if(b & 1){
            result = result + tmp;
        }
        b = b >> 1;
        tmp = tmp + tmp;
    }
    result = result + tmp;
    return result;
}

int divsion(int a, int b){
    int result = 0;
    int n = 1, m;
    int tmp = b;
    
    if(b > a) return 0;
    
    while(a > tmp){
        tmp = tmp << 1;
        n = n << 1;
    }
    result = tmp >> 1;
    m = n >> 1;
    
    while(a > result){
        if(a < result + tmp){
            while(a < result + tmp){
                tmp = tmp >> 1;
                n = n >> 1;
            }
            result = result + tmp;
            m = m + n;
        }
    }
    
    return m;

}

int sub(int a, int b){
    return a + ~b + 1;
}
