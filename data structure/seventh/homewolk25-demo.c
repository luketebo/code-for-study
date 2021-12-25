
#include<stdio.h>
#include<stdlib.h>
#define HASHSIZE 7  //哈希函数的除数 跟数据的个数相关（取素数）
#define NULLKEY -32768//进行数组的初始化
#define OK 1
#define ERROR 0
typedef int  Statue;//返回值的数据类型
typedef struct hashtable
{
    int *elem;//哈希表的数据域（类似于一维数组）
    int count;//哈希表的数据元素点的个数
}HashTable;//哈希表的结构体
void test();//测试函数
void insert_hashtable(HashTable* *hashtable,int data);//在哈希表中插入数据元素（创建过程）
Statue search_hashtable(HashTable* hashtable,int data);//数据元素的查找 返回状态值
void Display_hashtable(HashTable* hashtable);//遍历哈希表的数据
void Init(HashTable* *hashtable);//对哈希表进行初始化
int Hash_fun(int data);//哈希表函数
void main()
{
    test();//测试函数

}
int Hash_fun(int data)//哈希表函数
{
    return (data%HASHSIZE);//利用hash函数计算元素所在的位置

}

void Init(HashTable* *hashtable)//对哈希表进行初始化
{
    int m=HASHSIZE;
    int i;
    (*hashtable)->elem=(int *)malloc(sizeof(int )*m);//动态赋值存储空间
    (*hashtable)->count=m;//哈希表中数据元素的个数
    for(i=0;i<m;i++)
    {
        (*hashtable)->elem[i]=NULLKEY;//对哈希表的数据域进行初始化

    }
}
void insert_hashtable(HashTable**hashtable,int data)
{
    int hashaddress;//元素的插入位置
    hashaddress=Hash_fun(data);
      while((*hashtable)->elem[hashaddress]!=NULLKEY)
      {
          hashaddress=(++hashaddress)%HASHSIZE;
    }
         (*hashtable)->elem[hashaddress]=data;//对元素进行插入
}
Statue search_hashtable(HashTable*hashtable,int data)
{
    int hashaddress=Hash_fun(data);
  while(hashtable->elem[hashaddress]!=data)
  {
      hashaddress=(++hashaddress)%HASHSIZE;
        if(hashtable->elem[hashaddress]==NULLKEY||hashaddress==Hash_fun(data))
            return -1;//表明查找失败
            //hashaddress==Hash_fun(data)说明查找元素的位置处在数据的中间
            //表明已经结束回到哈希函数计算的位置 说明要查询的数据没有找到 查询失败
            //hashtable->elem[hashaddress]==NULLKEY 表明查找的元素的位置处在数据域的两端
             //此时条件表明查找的范围已经超出了数据域的范围  查找失败
}
  return hashaddress;//返回数据所在的位置
}
void Display_hashtable(HashTable*hashtable)
{
    //对哈希表的元素进行遍历
    int i;
    for(i=0;i<hashtable->count;i++)
    {
        printf("%d\t",hashtable->elem[i]);
    }
}
void test()//测试函数
{
    HashTable*hashtable;
    int i;
    int data;//待查询的数据
    hashtable=(HashTable*)malloc(sizeof(HashTable));//创建哈希表指针变量  并附存储空间
     Init(&hashtable);//对法哈希表进行初始化
     int hash_array[HASHSIZE];
     printf("请输入哈希表的元素:\n");
       for(i=0;i<HASHSIZE;i++)
        scanf("%d",&hash_array[i]);
         //哈希表元素的插入
         for(i=0;i<HASHSIZE;i++)
         insert_hashtable(&hashtable,hash_array[i]);
         printf("哈希表遍历结果为:\n");
          Display_hashtable(hashtable);
          printf("\n");//换行
           printf("请输入要查询的数据:\n");
             scanf("%d",&data);
             int result=search_hashtable(hashtable,data);
             if(result==-1)
             {
                 printf("查询失败！\n");
             }
             else
             {
                 printf("带查询数据%d在哈希表的位置为%d",data,result);
             }
}


