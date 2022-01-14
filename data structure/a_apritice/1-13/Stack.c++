/**
 * @file Stack.c++
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * c++使用起来要爽一点
 * 栈的操作：
 * 入栈，出栈，栈空，
 */
#include <bits/stdc++.h> // 万能头文件
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
//顺序栈
typedef struct {
    int top,bottom;
    ElemType *v;
    int size;
}Stack;
// 链栈
typedef struct {
    char *base;
    char *top;
    int stacksize;
}SqStack;