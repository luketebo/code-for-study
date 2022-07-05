// 作业1:求两个n阶矩阵的乘积算法
// 第一个矩阵的列数（column）和第二个矩阵的行数（row）

#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
typedef int Element;
/**
 * @brief 
 * 1. 怎么获取矩阵的行和列 使用sizeof()函数
 * 2. 
 * @param a 
 * @param b 
 */
void multiplication_for_matrix(Element a[][],Element b[][]){
    // int row_a = sizeof(a) / sizeof(a[0]);
    // int col_a = sizeof(a[0]) / sizeof(a[0][0]);
    // int row_b = sizeof(b) / sizeof(b[0]);
    // int col_b = sizeof(b[0]) / sizeof(b[0][0]);
}
int main(){
    Element a[MAXSIZE][MAXSIZE];
    Element b[MAXSIZE][MAXSIZE];
    Element c[MAXSIZE][MAXSIZE];
    for(int i = 0; i < MAXSIZE; i++){
        for(int j = 0; j < MAXSIZE; j++){
            a[i][j] = 0;
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d",&a[i][j]);
        }
    }

   for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d",&b[i][j]);
        }
    }
    // 计算
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            // 精妙绝伦
            for(int k; k < 3; k++){
                c[i][j] = a[i][k] * b[k][j];
            }
        }
    }



    // printf("the row: %d the col: %d \n",sizeof(a) / sizeof(a[0]), sizeof(a[0]) / sizeof(a[0][0]));


    return 0;
}