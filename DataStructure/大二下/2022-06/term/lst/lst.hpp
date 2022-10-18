#include "iostream"
#include "vector"
using namespace std;

#ifndef SQLISTC_H
#define SQLISTC_H
class SQLISTC
{
private:
	typedef struct
	{
		int *elem;
		int length;
	} Sqlist;

public:
	void MaxSum(int n, Sqlist l)
	{
		cout<<"首先声明一个d[n]数组用来存储第i个数据加到第rec[i]个数据的和,rec[n]用来记录第i个元素加到第几个元素能得到最大值"<<endl<<endl;
		int d[n], rec[n];
		cout<<"初始化d[n-1]就等于最后一个元素的值,rec[n-1]就等于n-1,因为最后一个元素不能再往后加了"<<endl<<endl;
		d[n - 1] = l.elem[n-1];
		rec[n - 1] = n - 1;
		cout<<"从后往前遍历："<<endl<<endl;
		for (int i = n - 2; i >= 0; i--)
		{
			if (d[i + 1] > 0)
			{
				cout<<"当d["<<i+1<<"]的值大于零时, d["<<i<<"]的值就等于当前数据值加上d["<<i+1<<"]"<<endl;
				cout<<"同时rec["<<i<<"]的值就等于rec["<<i+1<<"]的值"<<endl<<endl;
				d[i] = l.elem[i] + d[i + 1];
				rec[i] = rec[i + 1];
			}
			else
			{
				cout<<"当d["<<i+1<<"]的值小于零时, d["<<i<<"]的值就等于当前数据值"<<endl;
				cout<<"同时rec["<<i<<"]的值就等于"<<i<<"的值"<<endl<<endl;
				d[i] = l.elem[i];
				rec[i] = i;
			}
		}
		int sum = d[0], s = 0;
		cout<<"因为d[i]存储的是从第i个元素开始的最大字段和,所以要求整个序列的最大字段和,只需要遍历d[n]得到最大值就行"<<endl<<endl;
		for (int i = 0; i < n; i++)
		{
			if (d[i] > sum)
			{
				sum = d[i];
				s = i;
			}
		}
		cout << "最大字段和为：" << sum << endl
			 << "最优解为：" << s + 1 << "," << rec[s] + 1;
	}

	int main()
	{
		int n, i;
		cout << "请输入顺序表的长度：";
		cin >> n;

		Sqlist l;
		l.elem = new int[100];
		if (!l.elem)
			exit(0);
		l.length = 0;

		cout << "请依次输入该数组的数据：";
		for (i = 0; i < n; i++)
		{
			cin >> l.elem[i];
			l.length++;
		}
		MaxSum(l.length, l);
		return 0;
	}
};
#endif // SQLISTC_H