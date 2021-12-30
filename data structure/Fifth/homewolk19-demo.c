/*****
 * 作业：19 计算二叉树的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值)
 * 宽度本来是指什么？那就用层次遍历
 */
#include <stdio.h>
#include <stdlib.h>

//定义结点
typedef struct BiTNode
{
    char data;               //数据
    struct BiTNode *lchild;  //左孩子
    struct BiTNode *rchild;  //右孩子
}BiTNode, *BiTree;

//先序创建二叉树
BiTree CreateBiTree()
{
    char ch;
    BiTree T;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}
// 队列其实和数组差不到那里去
int Width(BiTree bt)//求二叉树bt的最大宽度
{
	if (bt==NULL) 
		return (0);  //空二叉树宽度为0
	else 
	{ 
	  BiTree Q[100],p;//Q是队列，元素为二叉树结点指针，容量足够大
      int front=1,rear=1,last=1;
      //front队头指针,rear队尾指针,last同层最右结点在队列中的位置
      int temp=0,maxw=0;       //temp记局部宽度, maxw记最大宽度
      Q[rear]=bt;           //根结点入队列
      while(front<=last)
	  {
		  p=Q[front++]; 
		  temp++; //同层元素数加1
          if (p->lchild!=NULL)  Q[++rear]=p->lchild;   //左子女入队
		  if (p->rchild!=NULL)  Q[++rear]=p->rchild;   //右子女入队
		  if (front>last)      //一层结束， 
		  { 
			    last=rear;
				if(temp>maxw) maxw=temp;//last指向下层最右元素, 更新当前最大宽度
				temp=0;
		  }   
	  }
     return (maxw);
}

}
int main()
{
	BiTree T;
	printf("先序创建二叉树，以#虚设结点\n");
	T=CreateBiTree();
	int n;
	n=Width(T);
	printf("最大宽度为：%d\n",n);
}

