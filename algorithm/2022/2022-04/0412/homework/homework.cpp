/**
 * @file homework.cpp
 * @author Luke Tebo (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-19
 *
 * @copyright Copyright (c) 2022
 *
 * 动态规划 矩阵连乘问题
 * 输入：矩阵数n, 各矩阵行数和列数P(p0,p1,...,pn)   最优计算次数
 * 输出：矩阵连乘最优值和最优解
 */
#include <iostream>
#include <vector>
using namespace std;
// 矩阵的乘法
void matrixMultiply(vector<vector<int>> &matrix_01, vector<vector<int>> &matrix_02, vector<vector<int>> &result)
{
    int row_01 = matrix_01.size();
    int col_01 = matrix_01[0].size();
    int row_02 = matrix_02.size();
    int col_02 = matrix_02[0].size();
    if (col_01 != row_02)
    {
        cout << "矩阵乘法错误，矩阵1的列数与矩阵2的行数不相等" << endl;
        return;
    }
    for (int i = 0; i < row_01; i++)
    {
        for (int j = 0; j < col_02; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col_01; k++)
            {
                result[i][j] += matrix_01[i][k] * matrix_02[k][j];
            }
        }
    }
}
// 最优值
void MatrixChain(vector<int> p, int n, vector<vector<int>> &matrix_01, vector<vector<int>> &matrix_02)
{
    for (int i = 1; i < n; i++)
    {
        matrix_01[i][i] = 0;
    }
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            matrix_01[i][j] = matrix_01[i][j - 1] + p[j - 1] * p[j] * p[j + 1];
            matrix_02[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                int q = matrix_01[i][k] + matrix_01[k + 1][j] + p[i - 1] * p[k] * p[j + 1];
                if (q < matrix_01[i][j])
                {
                    matrix_01[i][j] = q;
                    matrix_02[i][j] = k;
                }
            }
        }
    }
}
// 最优解
void Traceback(int i, int j, vector<vector<int>> &matrix)
{
    if (i == j)
    {
        return;
    }
    Traceback(i, matrix[i][j], matrix);
    Traceback(matrix[i][j] + 1, j, matrix);
    cout << "Multiply A" << i << " , " << matrix[i][j] << endl;
    cout << "and A" << matrix[i][j] + 1 << " , " << j << endl;
}
void print_matrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "----n----" << endl;
    cin >> n;
    vector<int> p(n);
    cout << "----pn----" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "----matrix_01----" << endl;
    vector<vector<int>> matrix_01(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix_01[i][j];
        }
    }
    print_matrix(matrix_01);
    cout << "----matrix_02----" << endl;
    vector<vector<int>> matrix_02(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix_02[i][j];
        }
    }
    print_matrix(matrix_02);
    MatrixChain(p, n, matrix_01, matrix_02);
    cout << "The optimal value is " << matrix_01[1][n - 1] << endl;
    print_matrix(matrix_01);
    print_matrix(matrix_02);
    Traceback(1, n - 1, matrix_02);
    return 0;
}
