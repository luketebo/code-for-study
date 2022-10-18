#include "iostream"
#include "vector"
using namespace std;
typedef struct
{
	int *elem;
	int length;
 } Sqlist;

void MaxSum(int n, Sqlist l) {
	int d[n],rec[n];
	d[n-1] = l.elem[n];
	rec[n-1] = n-1;
	for (int i = n - 2; i >= 0; i--) {
		if (d[i + 1] > 0) {
			d[i] = l.elem[i] + d[i + 1];
			rec[i] = rec[i + 1];
		}
		else {
			d[i] = l.elem[i];
			rec[i] = i;
		}
	}
	int sum = d[0], s = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > sum) {
			sum = d[i];
			s = i;
		}
	}
	cout << "����ֶκ�Ϊ��" << sum <<endl<< "���Ž�Ϊ��" << s+1 << "," << rec[s]+1;
}

int main() {
	int n,i;
	cout << "������˳���ĳ��ȣ�";
	cin >> n;
	
	Sqlist l; 
	l.elem=new int[100];
 	if(!l.elem) exit(0);
 	l.length=0;
 	
	cout << "�������������������ݣ�";
	for (i = 0; i < n; i++){
		cin >> l.elem[i];
		l.length++;
	}
	MaxSum(l.length, l);
}
