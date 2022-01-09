/**
 * 散列表的插入和删除 p232 3 (6) 第七章
 * 分别写出在散列表中插入和删除关键字为k的一个记录的算法，设散列函数为H,解决冲突的方法为链地址法
 * 散列表也叫哈希表
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define maxsize 100
typedef struct ListNode{
    int element;
    struct ListNode* next;
}ListNode;
typedef ListNode* List;
typedef struct {
    int tableSize;
    List* theList;
}HashTable;
int IsPrime(int n){
    int i;
    if(n <= 1) return 0;
    for(i = 2;i <= sqrt(n);i++){
        if(n%i == 0)
        return 0;
    }
    return 1;
}
int NextPrime(int n){
    int i = n - 1;
    if(n <= 2){
        printf("Error");
    }else {
        while(!IsPrime(i))
        --i;
    }
    return i;
}
int Hash(int key,int p){
    return key % p;
}
HashTable* Initialize(int tableSize){
    //创建表
    HashTable* H = (HashTable*)malloc(sizeof(HashTable));
    H->tableSize = NextPrime(tableSize);
    H->theList = (List*)malloc(H->tableSize * sizeof(List));
    // 初始化表中头结点
    int i;
    for(i=0;i<H->tableSize;i++){
        H->theList[i] = (ListNode*)malloc(sizeof(ListNode));
        H->theList[i]->next = NULL;
    }
    return H;
}
ListNode* Find(int key,HashTable* H){
    ListNode* p;
    ListNode* L;
    L = H->theList[Hash(key,H->tableSize)];
    p = L->next;

    while(p != NULL && p->element != key);
        p = p->next;
    return p;
}
void Insert(int key,HashTable* H){
    ListNode* p;
    ListNode* L;
    ListNode* newcell;

    p = Find(key,H);
    if(p == NULL){
        newcell = (ListNode*)malloc(sizeof(ListNode)); 
        L = H->theList[Hash(key,H->tableSize)];
        newcell->element = L->next;
        newcell->next = L->next;
        L->next = newcell;
    }
}

void Delete(int key,HashTable* H){
    ListNode* p;
    ListNode* L;
    ListNode* pre;

    p = Find(key,H);

    if(p != NULL){
        L = H->theList[Hash(key,H->tableSize)];
        pre = L;
        while(pre->next != p)
        pre = pre->next;
        pre->next = p->next;
        free(p);
    }
}
int main(){
    HashTable* H;
    int r[maxsize] = {1,9,12,11,25,35,17,29};
    int i,n = 8;
    int m = 2 * n;
    H = Initialize(m);

    for(i = 0;i< n;i++){
        Insert(r[i],H);
    }
    ListNode* p;
    p = Find(25,H);
    printf("%d",p->element);

    Delete(25,H);
    p = Find(11,H);

    return 0;
}

