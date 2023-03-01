/**
 * @file bubble_Sort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 冒泡排序 数组
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
void Bubble_Sort(int arr[],int count){

    for(int i = 0;i < count; i++){
        for(int j = i; j < count ; j++){
                int temp = 0;
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }
}
int main(){
    int arr[MAXSIZE];
    int count;
    printf("input the length: \n");
    scanf("%d", &count);
    getchar();
    char ch = getchar();
    printf("input the array: \n");
    for(int i = 0; i < count ; i++){
        scanf("%d",&arr[i]);

    }
    printf("---------打印------------\n");
    for(int i = 0; i < count ; i++ ){
        printf("%d ", arr[i]);
    }
    printf("\n");
    Bubble_Sort(arr,count);
    printf("---------打印------------\n");
    for(int i = 0; i < count ; i++ ){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}