#include <iostream>
using namespace std;
void matrixMultiply(int **a, int **b, int **c, int ra, int ca, int rb, int cb)
{
    if (ca != rb)
    {
        cout << "error" << endl;
        return;
    }
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; i < cb; j++)
        {
            int sum = a[i][0] * b[0][j];
            for (int k = 1; k < ca; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}
void MatrixChain(int **p, int **m, int **s, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            m[i][j] = INT_MAX;
            for (int k = 1; k < j; k++)
            {
                int q = m[i][k] + m[k][j] + p[i][j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
// int RecurMatrixChain(int **p, int **m, int **s, int i, int j)
// {
//     if (i == j)
//     {
//         return 0;
//     }
//     if (m[i][j] == INT_MAX)
//     {
//         return INT_MAX;
//     }
//     int q = RecurMatrixChain(p, m, s, i, s[i][j]) + RecurMatrixChain(p, m, s, s[i][j], j) + p[i][j];
//     return q;
// }
int recurMatrixChain(int i, int j){
    if(i == j){
        return 0;
    }
    // int u = recurMatrixChain(i, i) + recurMatrixChain(i + 1, j) + p[i - 1]*p[i]*p[j];
    return 0;
} 
void Traceback(int **s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i << " ";
    }
    else
    {
        Traceback(s, i, s[i][j]);
        Traceback(s, s[i][j], j);
    }
    cout << "Multiply A" << i << ", " << s[i][j];
    cout << "and A" << (s[i][j] + 1) << ", " << j << endl;
}