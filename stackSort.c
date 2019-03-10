//
//  stackSort.c
//  
//
//  Created by 李印臣 on 2019/3/10.
//

/*
问题描述
给定一个序列 A，请你将它升序排序。

输入格式
第一行一个正整数 n，表示序列长度。
第二行 n 个用空格隔开的非负整数，描述这个序列。

输出格式
n 行，每行一个非负整数，表示排序后的序列。

样例输入

样例输出

数据范围
保证 n<=1000，保证序列中的数不超过 32767
*/

#include <stdio.h>
#include <string.h>

#define STACK_LEN 1000
#define true 1
#define false 0

typedef int ElemType;
typedef int bool;

typedef struct Stack{
    ElemType *stack;
    int bottom;
    int top;
} SAStack;

ElemType GetTop(SAStack s){
    return s.stack[s.top];
}

bool IsEmpty(SAStack s){
    return s.top == s.bottom;
}

int Init(SAStack *s){
    s->top = -1;
    s->bottom = -1;
    s->stack = NULL;
    return s->top;
}

ElemType Pop(SAStack *s){
    ElemType e = GetTop(*s);
    s->top--;
    return e;
}

int Push(SAStack *s, ElemType e){
    s->top++;
    s->stack[s->top] = e;
    return s->top;
}

int Init2(SAStack *s){
    s->top = STACK_LEN;
    s->bottom = STACK_LEN;
    s->stack = NULL;
    return s->top;
}

ElemType Pop2(SAStack *s){
    ElemType e = GetTop(*s);
    s->top++;
    return e;
}

int Push2(SAStack *s, ElemType e){
    s->top--;
    s->stack[s->top] = e;
    return s->top;
}

int sort(char str[], SAStack *s, SAStack *s2){
    char *tmp = NULL;
    ElemType e = 0;
    tmp = str;
    int i;
    while(1){
        while(*tmp > 47){
            e = (e << 3) + (e << 1);
            e += *tmp - 48;
            tmp++;
        }

        if(!IsEmpty(*s) && e <= GetTop(*s)){
            while(!IsEmpty(*s2) && e < GetTop(*s2)){
                Push(s, Pop2(s2));
            }
        }else{
            while(!IsEmpty(*s) && e > GetTop(*s)){
                Push2(s2, Pop(s));
            }
        }
        Push(s, e);
        if(*tmp == '\n'){
            while(!IsEmpty(*s2)){
                Push(s, Pop2(s2));
            }
            break;
        }
        
        e = 0;
        tmp++;
    }
    return s->top;
}


int main(int argc, char *argv[]){
    int i, n;
    char str[6006];
    SAStack s;
    SAStack s2;
    ElemType elements[STACK_LEN];
    
    scanf("%d", &n);
    getchar();
    memset(str, 0, 6006);
    fgets(str, 6006, stdin);
    
    for (i = n - 1 ; i >= 0; i--) {
        elements[i] = 0;
    }
    
    Init(&s);
    Init2(&s2);
    s.stack = elements;
    s2.stack = elements;
    
    sort(str, &s, &s2);
    for (i = n - 1 ; i >= 0; i--) {
        printf("%d\n", elements[i]);
    }
    return 0;
}
