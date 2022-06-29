#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H
class MATRIX
{
private:
    int N = 10; //定义方阵的最大阶数为10
    typedef struct
    {
        int row, col;       //结构体
        float **matrix;     //二维指针，目的是动态分配内存
    } Matrix;

public:
    int main()
    {
        int num = 0;
        while (1)
        {
            cout << "*************************************\n";
            cout << "*              菜单                 *\n";
            cout << "*          1.矩阵相加               *\n";
            cout << "*          2.矩阵相减               *\n";
            cout << "*          3.矩阵相乘               *\n";
            cout << "*          4.矩阵数乘               *\n";
            cout << "*          5.矩阵求逆               *\n";
            cout << "*          6.退出                   *\n";
            cout << "*************************************\n";
            cout << "请输入您的选择：";
            cin >> num;
            // 相加、相减、相乘都是需要先输入两个矩阵
            if (1 == num || 2 == num || 3 == num)
            {
                cout << "请输入矩阵1" << endl;
                Matrix m1 = CreateMatrix();
                cout << "请输入矩阵2" << endl;
                Matrix m2 = CreateMatrix();
                switch (num)
                {
                // 加运算
                case 1:
                {
                    // 两个矩阵的行列要相同才能进行相加
                    if (m1.col != m2.col || m1.row != m2.row)
                    {
                        cout << "行列不同" << endl;
                    }
                    else
                    {
                        cout<<"第一个矩阵为：\n";
                        printMatrix(m1);
                        cout<<"第二个矩阵为：\n";
                        printMatrix(m2);
                        printMatrix(add(m1, m2));
                    }
                    break;
                }
                // 加运算
                case 2:
                {
                    // 两个矩阵的行列要相同才能进行相减
                    if (m1.col != m2.col || m1.row != m2.row)
                    {
                        cout << "行列不同" << endl;
                    }
                    else
                    {
                        cout<<"第一个矩阵为：\n";
                        printMatrix(m1);
                        cout<<"第二个矩阵为：\n";
                        printMatrix(m2);
                        printMatrix(sub(m1, m2));
                    }
                    break;
                }
                // 相乘运算
                case 3:
                {
                    // 第一个矩阵的列数要等于第二个矩阵的行数
                    if (m1.col != m2.row)
                    {
                        cout << "参数错误,不符合矩阵相乘的规定！\n矩阵相乘要求：第一个矩阵的列数要等于第二个矩阵的行数！" << endl;
                    }
                    else
                    {
                        cout<<"第一个矩阵为：\n";
                        printMatrix(m1);
                        cout<<"第二个矩阵为：\n";
                        printMatrix(m2);
                        printMatrix(Mul(m1, m2));
                    }
                    break;
                }
                default:
                    break;
                }
            }
            // 矩阵的数乘
            else if (4 == num)
            {
                int number = 1;
                cout << "请输入矩阵" << endl;
                Matrix m = CreateMatrix();
                cout << "请输入数值" << endl;
                cin >> number;
                cout << "矩阵为：" << endl;
                printMatrix(m);
                cout << "数值为：" << endl;
                cout << number << endl;
                printMatrix(numMul(m, number));
            }
            // 矩阵的求逆
            else if (5 == num)
            {
                float *buffer, *p;      //定义数组首地址指针变量
                int row, num;           //定义矩阵的行数和矩阵元素个数
                int i, j;
                float determ;           //定义矩阵的行列式
                float a[N][N], b[N][N];
                int n;
                cout << "请输入矩阵的行数: ";
                cin >> row;
                num = 2 * row * row;
                buffer = (float *)calloc(num, sizeof(float)); //分配内存单元
                p = buffer;
                if (NULL != p)
                {
                    for (i = 0; i < row; i++)
                    {
                        cout << "请依次输入第" << i + 1 << "行的元素: ";
                        for (j = 0; j < row; j++)
                        {
                            cin >> *p++;
                        }
                    }
                }
                else
                {
                    cout << "无法分配内存!\n";
                }
                cout << "原始矩阵:\n";
                print_M(buffer, row);               //打印该矩阵
                cout<<"1、求矩阵的逆首先我们要做的是求矩阵的行列式"<<endl;
                determ = MatDet(buffer, row);       //求整个矩阵的行列式
                p = buffer + row * row;
                if (determ != 0)
                {
                    // 求逆矩阵
                    for (i = 0; i < row; i++) 
                    {
                        for (j = 0; j < row; j++)
                        {
                            // A-1=A*/|A|
                            // *(p + j * row + i)巧妙的将其反转过来
                            *(p + j * row + i) = Creat_M(buffer, i, j, row) / determ;
                        }
                    }
                    cout << "矩阵的逆矩阵为:" << endl;
                    print_M(p, row); //打印该矩阵
                }
                else
                {
                    cout << "行列式是0，没有逆矩阵！\n";
                }
                free(buffer); //释放内存空间
                getchar();
            }
            else if (6 == num)
            {
                exit(0);
            }
        };
        return 0;
    }

    //-----------------------------------------------
    //功能:用户输入矩阵
    //入口参数: 无
    //返回值: 结果矩阵
    //----------------------------------------------
    Matrix CreateMatrix()
    {
        Matrix m;
        int row, col;
        cout << "输入行数与列数：" << endl;
        cin >> row >> col;
        float **enterMatrix;
        enterMatrix = (float **)malloc(row * sizeof(float *));
        for (int i = 0; i < row; i++)
            enterMatrix[i] = (float *)malloc(col * sizeof(float));
        cout << "输入你的矩阵：" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> enterMatrix[i][j];
            }
        }
        m.col = col;
        m.row = row;
        m.matrix = enterMatrix;
        return m;
    }

    //-----------------------------------------------
    //功能:初始化一个行为row列为col矩阵
    //入口参数: 行、列
    //返回值: 结果矩阵
    //----------------------------------------------
    Matrix InitMatrix(int row, int col)
    {
        Matrix m;
        float **matrix;
        matrix = (float **)malloc(row * sizeof(float *));
        for (int i = 0; i < row; i++)
            matrix[i] = (float *)malloc(col * sizeof(float));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
            }
        }
        m.col = col;
        m.row = row;
        m.matrix = matrix;
        return m;
    }

    //-----------------------------------------------
    //功能: 加运算
    //入口参数: 两个矩阵的名字
    //返回值: 结果矩阵
    //----------------------------------------------
    Matrix add(Matrix m1, Matrix m2)
    {
        cout << "矩阵相加运算解法如下:"<<endl;
        cout << "第一个矩阵与第二个矩阵对应的元素值依次相加" <<endl;
        for (int i = 0; i < m1.row; i++)
        {
            cout << "两个矩阵的第" << i+1 <<"行对应的元素相加的结果分别为"<<endl;
            for (int j = 0; j < m1.col; j++)
            {
                m1.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
                cout<<"\t"<<m1.matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"结果为："<<endl;
        return m1;
    }

    //-----------------------------------------------
    //功能: 减运算
    //入口参数: 两个矩阵的名字
    //返回值: 结果矩阵
    //----------------------------------------------
    Matrix sub(Matrix m1, Matrix m2)
    {
        cout << "矩阵相减运算解法如下:"<<endl;
        cout << "第一个矩阵与第二个矩阵对应的元素值依次相减" <<endl;
        for (int i = 0; i < m1.row; i++)
        {
            cout << "两个矩阵的第" << i+1 <<"行对应的元素相减的结果分别为"<<endl;
            for (int j = 0; j < m1.col; j++)
            {
                m1.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
                cout<<"\t"<<m1.matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl<<"结果为："<< endl;
        return m1;
    }

    //-----------------------------------------------
    //功能: （为矩阵相乘打基础）单独计算一行*一列, row为M1的行,col为m2的列
    //入口参数: 两个矩阵的名字, M1的行,m2的列
    //返回值: 整型结果
    //----------------------------------------------
    int calRowCol(Matrix M1, Matrix M2, int row, int col)
    {
        int result = 0;
        int same = M1.col;
        for (int j = 0; j < same; j++)
        {
            result += M1.matrix[row][j] * M2.matrix[j][col];
        }
        cout<<"\t"<<result;
        return result;
    }

    //-----------------------------------------------
    //功能: 乘运算
    //入口参数: 两个矩阵的名字
    //返回值: 结果矩阵
    //----------------------------------------------
    Matrix Mul(Matrix m1, Matrix m2)
    {
        // 初始化一个行为m1.row列为m2.col矩阵
        Matrix m_result = InitMatrix(m1.row, m2.col);
        cout << "矩阵相乘运算解法如下:"<<endl;
        for (int i = 0; i < m1.row; i++)
        {
            cout << "第一个矩阵的第"<<i+1<<"行乘第二个矩阵的每一列对应的元素，然后求和后按行排列为：" <<endl;
            for (int j = 0; j < m2.col; j++)
            { 
                m_result.matrix[i][j] = calRowCol(m1, m2, i, j);
            }
            cout<<endl;
        }
        cout<<"结果为："<<endl;
        return m_result;
    }

    //-----------------------------------------------
    //功能: 数乘运算
    //入口参数: 矩阵名字，要乘的数
    //返回值: 结果矩阵
    //----------------------------------------------
    Matrix numMul(Matrix m, int num)
    {
        cout << "数乘运算解法如下:"<<endl;
        cout << "矩阵的每个值依次乘这个数值" <<endl;
        for (int i = 0; i < m.row; i++)
        {
            cout <<"数据"<< num <<"与第" << i+1 <<"行的数相乘结果分别为"<<endl;
            for (int j = 0; j < m.col; j++)
            {
                m.matrix[i][j] = m.matrix[i][j] * num;
                cout<<"\t"<<m.matrix[i][j];
            }
            cout<<endl;
        }
        cout<<"结果为："<<endl;
        return m;
    }

    //-----------------------------------------------
    //功能: 输出矩阵
    //入口参数: 矩阵名字
    //返回值: 结果矩阵
    //----------------------------------------------
    void printMatrix(Matrix m)
    {
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.col; j++)
            {
                cout << m.matrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    //-----------------------------------------------
    //功能: 求矩阵(n*n)的行列式
    //入口参数: 矩阵的首地址，矩阵的行数
    //返回值: 矩阵的行列式值
    //----------------------------------------------
    float MatDet(float *p, int n){
        int r, c, m;
        int lop = 0;
        float result = 0;
        float result2 = 0;
        float mid = 1;
        if (n != 1)
        {
            lop = (n == 2) ? 1 : n;     //控制求和循环次数,若为2阶，则循环1次，否则为n次
            cout<<"顺序求和, 主对角线元素相乘之和依次是："<<endl;
            for (m = 0; m < lop; m++){ 
                mid = 1;                //顺序求和, 主对角线元素相乘之和
                for (r = 0, c = m; r < n; r++, c++){
                    mid = mid * (*(p + r * n + c % n));
                }
                cout<<"\t"<<mid;
                result += mid;
            }
            cout<<endl;
            cout<<"主对角线元素相乘之和是"<<result<<endl;
            cout<<"逆序相减, 减去次对角线元素乘积依次是："<<endl;
            for (m = 0; m < lop; m++){
                mid = 1;                //逆序相减, 减去次对角线元素乘积
                for (r = 0, c = n - 1 - m + n; r < n; r++, c--){
                    mid = mid * (*(p + r * n + c % n));
                }
                cout<<"\t"<<mid;
                result2 += mid;
            }
            cout<<endl;
            cout<<"主对角线元素相乘之和是"<<result2<<endl;
            cout<<"因此，矩阵的行列式为："<<result<<"-"<<result2<<"="<<result-result2<<endl;
            result=result-result2;
        }
        else
            result = *p;
        return result;
    }
    //----------------------------------------------------------------------------
    //功能: 求k*k矩阵中元素A(m, n)的代数余之式
    //入口参数: k*k矩阵的首地址，矩阵元素A的下标m,n,矩阵行数row
    //返回值: k*k矩阵中元素A(m, n)的代数余之式
    //----------------------------------------------------------------------------
    float Creat_M(float *p, int m, int n, int row){
        int len;
        int i, j;
        float mid_result = 0;
        int sign = 1;
        float *p_creat, *p_mid;
        len = (row - 1) * (row - 1);                   // k阶矩阵的代数余之式为k-1阶矩阵
        p_creat = (float *)calloc(len, sizeof(float)); //分配内存单元
        p_mid = p_creat;
        for (i = 0; i < row; i++){
            for (j = 0; j < row; j++){
                //将除第i行和第j列外的所有元素存储到以p_mid为首地址的内存单元
                if (i != m && j != n) {
                    *p_mid++ = *(p + i * row + j);
                }
            }
        }
        cout<<"去除元素A("<<m<<","<<n<<")得到的新矩阵为："<<endl;
        print_M(p_creat,row-1);
        sign = (m + n) % 2 == 0 ? 1 : -1; //代数余之式前面的正、负号
        mid_result = (float)sign * MatDet(p_creat, row - 1);
        free(p_creat);
        cout<<"现已经求出矩阵的行列式和矩阵的伴随矩阵。"<<endl;
        cout<<"开始根据公式A^(-1)=A*/|A|计算矩阵的逆："<<endl;
        return mid_result;
    }
    //-----------------------------------------------------
    //功能: 打印n*n矩阵
    //入口参数: n*n矩阵的首地址,矩阵的行数n
    //返回值: 无返回值
    //-----------------------------------------------------
    void print_M(float *p, int n)
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            cout << setw(4);
            for (j = 0; j < n; j++)
            {
                cout << setiosflags(ios::right) << *p++ << setw(10);
            }
            cout << endl;
        }
    }
};
#endif // MATRIX_H