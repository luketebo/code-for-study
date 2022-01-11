// 作业1:求两个n阶矩阵的乘积算法
#include <iostream>
using namespace std;

int main ()
{
	int m,n,a,b,i,j,k;
	//nb的创建二维数组的放法
	int a1[10][10];
	int b1[10][10];
	int c1[10][10];
	while(1){
	cout<<"输入第一个矩阵的行数与列数(<10):";
	cin>>m>>n;
	cout <<"输入第二个矩阵的行数与列数(<10):";
	cin>>a>>b;
	if(a>10||b>10||m>10||n>10) {
		cout<<"行数出现错误"<<endl;
		cout<<"请重新输入:"<<endl;
	}else break;
	}
    if(n != a)
	{
		cout<<"维数不同无法相乘"<<endl;
		exit(-1);
	}
/*
	//动态内存分配
	a1 = new int *[m]; 
    for (i=0; i<m; i++)
		if ((a1[i] = new int [n])==NULL)
			exit (0);
	
	b1 = new int * [a]; 
	for (i = 0;i<a;i++)
		if ((b1[i] = new int [b])==NULL)
			exit (0);
	
	c1 = new int * [m];
	for (i=0; i<m; i++)
		if ((c1[i] = new int [b])==NULL)
			exit (0);
*/
	//创建矩阵a1
	cout<<"输入第一个矩阵的元素:";
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			cin>>a1[i][j];
	}
	//创建矩阵b1
		cout<<"输入第二个矩阵的元素:";
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++) 
			cin>>b1[i][j];
	}
	//将c1矩阵所有元素赋值为0
    for (i=0; i<m; i++)
		for (j=0; j<b; j++)
			c1[i][j] = 0;
	//计算c1
	for (i=0; i<m; i++)
		for(j=0; j<b; j++)
			for (k=0; k<n; k++)
				c1[i][j] += a1[i][k]*b1[k][j];

	//输出c1
	cout<<"输出结果为"<<endl;
	for (i=0; i<m; i++)
	{
		k = 0;
		for (j=0; j<b; j++)
		{
			cout<<c1[i][j];
			k = k+1;
			if (k==b)
				cout<<endl;
			else cout<<"\t";
		}
	}
/*
	//释放内存空间
	for (i=0; i<m; i++)
		delete[]a1[i];
	delete []a1;
	for (i=0; i<a; i++)
		delete[]b1[i];
	delete []b1;
	for (i = 0;i<m;i++)
		delete[]c1[i];
	delete []c1;
*/
	return 0;
}


