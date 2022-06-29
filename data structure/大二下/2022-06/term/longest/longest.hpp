#include "iostream"
#include "vector"
using namespace std;

#ifndef SQLIST_H
#define SQLIST_H
class SQLIST
{
private:
	typedef struct
	{
		char *elem;
		int length;
	} Sqlist;

public:
	void LCSLength(Sqlist x, Sqlist y)
	{
int i, j;
		int m = x.length;
		int n = y.length;
		if (m == 0 || n == 0)
		{
			cout << "0" << endl<< "输入的序列长度为0"<<endl;
			exit(0);
		}
		cout<<endl<<"首先初始化一个二维数组c[m][n]来存储第一个序列的前i个元素与第二个序列的前j个元素之间最长公共子序列的长度"<<endl;
		cout<<endl<<"m是第一个序列的长度,n是第二个序列的长度,i代表行数,j代表列数<<endl";
		int c[50][50];
		for (i = 0; i < 50; i++)
		{
			for (j = 0; j < 50; j++)
			{
				c[i][j] = 0;
			}
		}
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
			{
				if (x.elem[i - 1] == y.elem[j - 1])
				{
					cout<<"因为第一个序列中的第"<< i<< "个元素“"<< x.elem[i-1]<< "”与y中的第"<< j<< "个元素“"<< y.elem[j-1]<< "”相等"<< endl;
					cout<<"所以让c["<<i<<"]["<<j<<"]的值相对于c["<<i-1<<"]["<<j-1<<"]的值加一"<<endl<<endl;
					c[i][j] = c[i - 1][j - 1] + 1;
				}
				else
				{
					cout<<"因为第一个序列中的第"<< i<< "个元素“"<< x.elem[i-1]<< "”与y中的第"<< j<< "个元素“"<< y.elem[j-1]<< "”不相等"<< endl;
					cout<<"所以让c["<<i<<"]["<<j<<"]的值取c["<<i-1<<"]["<<j<<"]和c["<<i<<"]["<<j-1<<"]中更大的那个"<<endl<<endl;
					c[i][j] = max(c[i - 1][j], c[i][j - 1]);
				}
			}
		cout<<"c[i][j]:"<<endl;
		for(i=1;i<=m;i++){
			cout<<"       ";
			for(j=1;j<=n;j++){
				cout<<c[i][j]<<" ";
			}
			cout<<endl;
		}
			
		cout<<endl<<"因为c["<<m<<"]["<<n<<"]代表第一个序列中的前"<<m<<"个元素和第二个序列中的前"<<n<<"个元素的最大字段和"<<endl;
		cout << "所以长子序列长度是：" << c[m][n] << endl;
	}

	int main()
	{
		Sqlist x, y;
		int m, n, i;
		x.elem = new char[100];
		if (!x.elem)
			exit(0);
		x.length = 0;
		y.elem = new char[100];
		if (!y.elem)
			exit(0);
		y.length = 0;
		cout << "请输入第一个序列的长度：";
		cin >> n;
		cout << "请输入第二个序列的长度：";
		cin >> m;
		cout << "请依次输入第一个序列的内容：";
		for (i = 0; i < n; i++)
		{
			cin >> x.elem[i];
			x.length++;
		}
		cout << "请依次输入第二个序列的内容：";
		for (i = 0; i < m; i++)
		{
			cin >> y.elem[i];
			y.length++;
		}
		LCSLength(x, y);
		return 0;
	}
};
#endif // !SQLIST_H
