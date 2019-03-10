//
//  redDirect.c
//  
//
//  Created by 李印臣 on 2019/3/10.
//

#include <stdio.h>
#include <string.h>

#define STACK_LEN 1500
#define true 1
#define false 0

typedef short ElemType;
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

int main(int argc, char *argv[]){
    short arr[1500][1500] = {};
    char str[1502] = {};
    int max = 0;
    short ss[1500] = {};
    short indexs[1500] = {};
    char *tmp = NULL;
    int i = 0, j = 0, k = 0, n = 0, m = 0, a = 0, b = 0, count = 0;
    SAStack s;
    
    Init(&s);
    s.stack = ss;
    
    scanf("%d %d", &n, &m);
    getchar();
    
    for (i = 0; i < n; i++) {
        fgets(str, 1502, stdin);
        tmp = str;
        j = 0;
        count = 0;
        
        while (*tmp != '\n') {
            if (*tmp == '.') {
                arr[i][j] = ++count;
            }else{
                count = 0;
            }
            j++;
            tmp++;
        }
    }
    
    for (j = m - 1; j >= 0; j--) {
        for (i = 0; i < n; i++) {
            a = arr[i][j];
            k = a;
            if(IsEmpty(s) || GetTop(s) < a){
                indexs[a] = i;
            }else{
                while(!IsEmpty(s) && GetTop(s) >= a){
                    k = Pop(&s);
                    if(k == a){
                        b = (i - indexs[k] + 1) * k;
                    }else{
                        b = (i - indexs[k]) * k;
                    }
                    
                    if(b > max){
                        max = b;
                    }
                }
            }
            
            indexs[a] = indexs[k];
            Push(&s, a);
        }
        
        while (!IsEmpty(s)){
            k = Pop(&s);
            b = (i - indexs[k]) * k;
            if(b > max){
                max = b;
            }
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}

