//
//  tools.c
//  DataStructure
//
//  Created by 李印臣 on 2019/3/19.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "tools.h"
void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int fibonacci0(int n){
    return (n < 2) ? n : fibonacci0(n - 1) + fibonacci0(n -2);
}

int fibonacci1(int n){
    int i, a = 1, b = 1, result = 0;
    for(i = 2; i < n; i++){
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int fibonacci2(int n){
    int a, b, c;
    if(n < 3) return 1;
    if(n & 1){
        a = fibonacci2((n + 1) / 2);
        b = fibonacci2((n - 1) / 2);
        c = a * a + b * b;
    }else{
        a = fibonacci2(n / 2 + 1);
        b = fibonacci2(n / 2 - 1);
        c = a * a - b * b;
    }
    return (n < 2) ? n : c;
}

int fibonacci3(int n, int *prev){
    int prevPrev = 0;
    if(n == 0){
        *prev = 1;
        return 0;
    }
    *prev = fibonacci3(n - 1, &prevPrev);
    return *prev + prevPrev;
}

int fibonacci4(int n){
    int a = 0, b = 1;
    while(n--){
        b = a + b;
        a = b - a;
    }
    return a;
}

//int fibonaccixxx(int n, int *mid){
//    int c, midPrev, midPrev2, midPrev3, midPrev4;
//    if(n < 3){
//        *mid = 1;
//        return 1;
//    }
//    if(n & 1){
//        *mid = fibonaccixxx((n + 1) / 2, &midPrev);
//        midPrev2 = midPrev;
//        printf("*1**%d %d\n", *mid, midPrev2);
//        c = *mid  * *mid  + midPrev2 * midPrev2;
//    }else{
//        *mid = fibonaccixxx(n / 2 + 1, &midPrev3);
//        midPrev4 = *mid - midPrev3;
//        //printf("*2**%d %d\n", *mid, midPrev);
//        c = *mid  * *mid - midPrev4 * midPrev4;
//        printf("*2**%d %d %d\n", *mid, midPrev4, c);
//    }
//    return (n < 2) ? n : c;
//}
//
//int fibonacci(int n){
//    int c = 7, i = 0, result;
//    int arr[8][2] = {{1, 1},
//                    {2, 1},
//                    {3, 2},
//                    {4, 3},
//                    {5, 5},
//                    {6, 8},
//                    {7, 13},
//                    {8, 21}};
//    if(n < 7)return arr[n - 1][1];
//    
//    while(n > 4 * arr[c][0] - 6){
//        for(i = 1; i < 5; i++){
//            result = 2 * arr[(c + 5) % 8][0] + 1 + i;
//            arr[(c + i) % 8][0] = result;
//            if(i == 1){
//                result = pow(arr[(c + 7) % 8][1], 2) - pow(arr[(c + 5) % 8][1], 2);
//            }else if(i == 2){
//                result = pow(arr[(c + 7) % 8][1], 2)  + pow(arr[(c + 6) % 8][1], 2) ;
//            }else if(i ==3){
//                result = pow(arr[c % 8][1], 2) - pow(arr[(c + 6) % 8][1], 2);
//            }else{
//                result = pow(arr[c % 8][1] , 2) + pow(arr[(c + 7) % 8][1], 2);
//            }
//
//            arr[(c + i) % 8][1] = result;
//        }
//        c = (c + 4) % 8;
//    }
//    
//    for(i = 0; i < 8; i++){
//        //printf("%d%c", arr[i][1], i == 7?'\n': ' ');
//    }
//
//    if(n & 1){
//        for(i = 0; i < 8; i++){
//            if(4 * arr[(c + i) % 8][0] + 3 == n){
//                return pow(pow(arr[(c + i + 2) % 8][1], 2) - pow(arr[(c + i) % 8][1], 2), 2) + pow(pow(arr[(c + i + 1) % 8][1], 2) + pow(arr[(c + i) % 8][1], 2), 2);
//            }else if(4 * arr[(c + i) % 8][0] + 5 == n){
//                return pow(pow(arr[(c + i + 2) % 8][1], 2) - pow(arr[(c + i) % 8][1], 2), 2) + pow(pow(arr[(c + i + 2) % 8][1], 2) + pow(arr[(c + i + 1) % 8][1], 2), 2);
//            }
//        }
//    }else{
//        for(i = 0; i < 8; i++){
//            if(4 * arr[(c + i) % 8][0] + 4 == n){
//                //printf("ff");
//                return pow(pow(arr[(c + i + 2) % 8][1], 2) + pow(arr[(c + i + 1) % 8][1], 2), 2) - pow(pow(arr[(c + i + 1) % 8][1], 2) + pow(arr[(c + i) % 8][1], 2), 2);
//            }else if(4 * arr[(c + i) % 8][0] + 6 == n){
//                return pow(pow(arr[(c + i + 3) % 8][1], 2) - pow(arr[(c + i + 1) % 8][1], 2), 2) - pow(pow(arr[(c + i + 2) % 8][1], 2) - pow(arr[(c + i) % 8][1], 2), 2);
//            }
//        }
//    }
//    return 1;
//}
