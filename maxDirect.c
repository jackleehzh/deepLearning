//
//  maxDirect.c
//  
//
//  Created by 李印臣 on 2019/3/10.
//

#include <stdio.h>
#include <string.h>

#define STACK_LEN 32768
#define true 1
#define false 0

typedef unsigned short ElemType;
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
    unsigned short area[32769] = {};//i
    unsigned short area2[32769] = {};//i
    long long max = 0;//area
    int i = 0, cnt = 0, N = 0;
    int a = 0, b = 0;
    char str[300002] = {};
    char *tmp = NULL;
    
    SAStack s;
    Init(&s);
    s.stack = area2;
    
    scanf("%d", &N);
    getchar();
    tmp = str;
    fgets(tmp, 300002, stdin);
    
    while(cnt < N){
        while(*tmp > 47){
            a = (a << 3) + (a << 1);
            a += *tmp - 48;
            tmp++;
        }
        cnt++;
        //记下直方图的起点
        if(IsEmpty(s) || GetTop(s) < a){
            area[a] = cnt;
        }
        
        //计算当前的最大面积
        //栈中是一个倒序排列。若有该高度，则找到它，并更新它的起点；计算所有高度大于它的面积。
        i = a;
        while(!IsEmpty(s) && GetTop(s) >= a){//不能去掉等号，因为要把以前存的相等的值弹出来
            i = Pop(&s);
            if(i == a){
                //b = (cnt - area[i] + 1) * i; //不需要这步计算
            }else{
                b = (cnt - area[i]) * i;
            }
            
            if(b > max){
                max = b;
            }
        }
        //修改直方图的起点
        area[a] = area[i];
        //把该长度压栈
        Push(&s, a);
        
        a = 0;
        tmp++;
    }
    
    //计算剩下的直方图面积
    while (!IsEmpty(s)) {
        i = Pop(&s);
        b = (N - area[i] + 1) * i;
        if(b > max){
            max = b;
        }
    }
    
    printf("%lld\n", max);
    
    return 0;
}
