#include<stdio.h>
#include<stdlib.h>
typedef struct linklist {
	int data;
	struct linklist *next;
}list,*plist;

void list_create(plist *pphead, plist *pptail, int key)
{
	plist pnew = (plist)calloc(1, sizeof(list));
	pnew->data = key;
	if (NULL == *pphead)
	{
		*pphead = pnew;
		*pptail = pnew;
	}
	else {
		(*pptail)->next = pnew;
		*pptail = pnew;
	}
}

void splitlist(plist *pphead,plist *pphead1,plist *pphead2)
{
	int count = 0;
	plist ptail1, ptail2;
	plist pnew;
	while (*pphead)
	{
		count++;
		pnew = *pphead;
		if (count % 2 )
		{
			if (NULL == *pphead1)
			{
				*pphead1 = pnew;
				ptail1 = pnew;
			}
			else {
				ptail1->next = pnew;
				ptail1 = pnew;;
			}
		}
		else {
			if (NULL == *pphead2)
			{
				*pphead2 = pnew;
				ptail2 = pnew;
			}
			else {
				ptail2->next = pnew;
				ptail2 = pnew;;
			}
		}
		*pphead = (*pphead)->next;
	}
	ptail1->next = NULL;
	ptail2->next = NULL;
}

void list_print(plist p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	plist phead = NULL , ptail = NULL;
	int key;
	plist phead1 = NULL, phead2 = NULL;
	while (scanf("%d", &key) != EOF)
	{
		list_create(&phead, &ptail, key);
	}
	printf("List：");
	list_print(phead);
	splitlist(&phead, &phead1, &phead2);
	printf("current List：");
	list_print(phead);
	printf("List1：");
	list_print(phead1);
	printf("List2：");
	list_print(phead2);
	system("pause");
}
