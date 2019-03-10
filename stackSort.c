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

int InitElement(char str[], SAStack *s){
    char *tmp = NULL, *str2 = NULL, *strEnd = NULL;
    ElemType e = 0;
    str2 = tmp = str;
    while(1){
        while(*tmp != ' ' && *tmp != '\n')
            tmp++;
        strEnd = tmp;
        tmp = str2;
        while(tmp != strEnd){
            e = (e << 3) + (e << 1);
            e += *tmp - 48;
            tmp++;
        }
        Push(s, e);
        if(*tmp == '\n')break;
        e = 0;
        tmp++;
        str2 = tmp;
    }
    return s->top;
}

void sort(SAStack *s, SAStack *s2){
    ElemType tmp;
    while (!IsEmpty(*s)) {
        tmp = Pop(s);
        if(!IsEmpty(*s2)){
            while(tmp < GetTop(*s2)){
                Push(s, Pop(s2));
            }
        }
        Push(s2, tmp);
    }
}

int main(int argc, char *argv[]){
    int i, n;
    char str[6006];
    SAStack s;
    SAStack s2;
    ElemType elements[STACK_LEN];
    ElemType elements2[STACK_LEN];
    
    scanf("%d", &n);
    getchar();
    memset(str, 0, 6006);
    fgets(str, 6006, stdin);
    
    Init(&s);
    Init(&s2);
    s.stack = elements;
    s2.stack = elements2;
    InitElement(str, &s);

    sort(&s, &s2);
    for (i = 0; i < n; i++) {
        printf("%d\n", elements2[i]);
    }
    return 0;
}
