#include "iostream"
#include "vector"
using namespace std;

typedef struct {
	char *elem;
	int length;
}Sqlist;

void LCSLength(Sqlist x,Sqlist y)
{
	int i, j;
	int m = x.length;
	int n = y.length;
	if (m == 0 || n == 0) {
		cout<<"0"<<endl;
		exit(0);
	}
	int c[50][50];
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			c[i][j] = 0;
		}
	}
	for(i=1;i<=m;i++)
		for (j = 1; j <= n; j++) {
			if (x.elem[i-1] == y.elem[j-1]) {
				c[i][j] = c[i - 1][j - 1] + 1; 
			}
			else {
				c[i][j] = max(c[i - 1][j],c[i][j-1]);
			}
		}
	cout <<"最长子序列长度是："<< c[m][n] << endl;
}


int main() {
	Sqlist x, y;
	int m, n, i;
	x.elem = new char[100];
	if (!x.elem) exit(0);
	x.length = 0;
	y.elem = new char[100];
	if (!y.elem) exit(0);
	y.length = 0;
	cout << "请输入第一个序列的长度：";
	cin >> n;
	cout << "请输入第二个序列的长度：";
	cin >> m;
	cout << "请依次输入第一个序列的内容：";
	for (i = 0; i < n; i++) {
		cin >> x.elem[i];
		x.length++;
	}
	cout << "请一次输入第二个序列的内容：";
	for (i = 0; i < m; i++) {
		cin >> y.elem[i];
		y.length++;
	}
	LCSLength( x, y);
}
