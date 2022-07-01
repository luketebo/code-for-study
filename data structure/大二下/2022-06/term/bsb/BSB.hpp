#include <iostream>

using namespace std;

#ifndef BSB_H
#define BSB_H
class BSB
{
private:
    const int MaxVal = 9999;

    int n = 99;

    double p[99 + 1] = {-1, 0.15, 0.1, 0.05, 0.1, 0.2};
    double q[99 + 1] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};

    int root[99 + 1][99 + 1];
    double w[99 + 2][99 + 2];
    double e[99 + 2][99 + 2];

public:
    void scanfTree()
    {
        cout << "输入节点数(小于99): ";
        cin >> n;
        cout << "请输入节点的概率：" << endl;
        for (int i = 1; i < n; i++)
            cin >> p[i];
        cout << "请输入空隙节点的概率：" << endl;
        for (int i = 0; i < n; i++)
            cin >> q[i];
    }

    void optimalBST(double *p, double *q, int n)
    {
        cout << "开始计算最优二叉树..." << endl;
        for (int i = 1; i <= n + 1; ++i)
        {
            w[i][i - 1] = q[i - 1];
            e[i][i - 1] = q[i - 1];
        }

        cout << "初始化 w 和 e 数组: " << endl;
        cout << "w: " << endl;
        for (int i = 1; i <= n + 1; ++i)
        {
            for (int j = 1; j <= n + 1; ++j)
                cout << w[i][j] << "\t";
            cout << endl;
        }
        
        cout << endl << "e: " << endl;
        for (int i = 1; i <= n + 1; ++i)
        {
            for (int j = 1; j <= n + 1; ++j)
                cout << e[i][j] << "\t";
            cout << endl;
        }

        cout << "开始填表: " << endl;
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 1; i <= n - len + 1; ++i)
            {
                int j = i + len - 1;
                e[i][j] = MaxVal;
                w[i][j] = w[i][j - 1] + p[j] + q[j];

                for (int k = i; k <= j; ++k)
                {
                    double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                    if (temp < e[i][j])
                    {
                        e[i][j] = temp;
                        root[i][j] = k;
                    }
                }
                cout << "w["<< i << "][" << j << "]: " << w[i][j] << endl;
                cout << "e["<< i << "][" << j << "]: " << e[i][j] << endl << endl;
            }
        }
    }

    void printRoot()
    {
        cout << "最优二叉树的根节点为: ";
        cout << "各子树的根：" << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << root[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printOptimalBST(int i, int j, int r)
    {
        cout << "最优二叉树的结果为: " << endl;
        int rootChild = root[i][j];
        if (rootChild == root[1][n])
        {

            cout << "k" << rootChild << "是根" << endl;
            printOptimalBST(i, rootChild - 1, rootChild);
            printOptimalBST(rootChild + 1, j, rootChild);
            return;
        }

        if (j < i - 1)
        {
            return;
        }
        else if (j == i - 1)
        {
            if (j < r)
                cout << "d" << j << "是"
                     << "k" << r << "的左孩子" << endl;
            else
                cout << "d" << j << "是"
                     << "k" << r << "的右孩子" << endl;
            return;
        }
        else
        {
            if (rootChild < r)
            {
                cout << "k" << rootChild << "是"
                     << "k" << r << "的左孩子" << endl;
            }
            else
                cout << "k" << rootChild << "是"
                     << "k" << r << "的右孩子" << endl;
        }

        printOptimalBST(i, rootChild - 1, rootChild);
        printOptimalBST(rootChild + 1, j, rootChild);
    }

    int main()
    {
        scanfTree();
        optimalBST(p, q, n);
        printRoot();
        cout << "最优二叉树结构：" << endl;
        printOptimalBST(1, n, -1);
        return 0;
    }
};
#endif