//
//  stackSort.c
//  
//
//  Created by 李印臣 on 2019/3/9.
//

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

//栈排序
//主要思想：从一个无序数据栈中弹出一个元素，如果该元素小于（因为输出时是数组顺序输出）另一个栈的栈顶元素，则把该栈的栈顶数据弹出，直到该元素不再小于栈顶元素。然后，把该元素压栈。
int sort(char str[], SAStack *s, SAStack *s2){
    char *tmp = NULL;
    ElemType e = 0;
    tmp = str;
    int i;
    while(1){
        while(*tmp != ' ' && *tmp != '\n'){
            e = (e << 3) + (e << 1);
            e += *tmp - 48;
            tmp++;
        }
        //如果是空或小于等于栈顶1，栈2为空或大于栈2（小于栈2，则出栈2，入栈1），则入栈1；
        //如果大于栈顶1，则出栈1，入栈2，然后入栈1
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
    //因为scanf很耗时，减少使用可以加快速度
    fgets(str, 6006, stdin);
    
    for (i = n - 1 ; i >= 0; i--) {
        elements[i] = 0;
    }
    
    Init(&s);
//注意：调试时出现段错误，因为栈2没有使用修改后的初始化函数。
    Init2(&s2);
    s.stack = elements;
    s2.stack = elements;
    
    sort(str, &s, &s2);
    for (i = n - 1 ; i >= 0; i--) {
        printf("%d\n", elements[i]);
    }
    return 0;
}
