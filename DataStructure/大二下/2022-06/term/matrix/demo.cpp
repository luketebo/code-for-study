#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
#define  N  10                //定义方阵的最大阶数为10
typedef struct
{
    
    int row,col;        //结构体
    float **matrix;     //二维指针，目的是动态分配内存
} Matrix;

typedef struct
{
    char *name;
    char *number;
} Student;

Matrix CreateMatrix();                               //用户输入矩阵
Matrix InitMatrix(int row,int col);                  //初始化一个行为row列为col矩阵
Matrix add(Matrix m1, Matrix m2);                    //加运算 
Matrix sub(Matrix m1, Matrix m2);                    //减运算
int calRowCol(Matrix M1,Matrix M2,int row,int col);  //单独计算一行*一列，row为M1的行 col为m2的列
Matrix Mul(Matrix m1, Matrix m2);                    //乘运算
Matrix numMul(Matrix m, int num);                    //数乘运算
float MatDet(float *p, int n);                    //求矩阵的行列式
float Creat_M(float *p, int m, int n, int k);    //求矩阵元素A(m, n)的代数余之式
void print(float *p, int n);                    //输出矩阵n*n
Matrix printMatrix(Matrix m);                        //输出矩阵


int main()
{
    int num = 0;
    while(1)
    {
        cout<<"*************************************\n";
        cout<<"*              菜单                 *\n";
        cout<<"*          1.矩阵相加               *\n";
        cout<<"*          2.矩阵相减               *\n";
        cout<<"*          3.矩阵相乘               *\n";
        cout<<"*          4.矩阵数乘               *\n";
        cout<<"*          5.矩阵求逆               *\n";        
        cout<<"*          6.退出                   *\n";
        cout<<"*************************************\n";
        cout<<"请输入您的选择：";
        cin>>num;
        if(1 == num|| 2 == num || 3 == num)
        {
            cout<<"请输入矩阵1"<<endl;
            Matrix m1 = CreateMatrix();
            cout<<"请输入矩阵2"<<endl;
            Matrix m2 = CreateMatrix();
            cout<<"两矩阵为"<<endl;
            printMatrix(m1);
            cout<<endl;
            printMatrix(m2);
            switch(num)
            {
                case 1:
                {
                    if(m1.col!=m2.col || m1.row!=m2.row)
                    {
                        cout<<"行列不同"<<endl;
                    }
                    else{
                        cout<<"结果为："<<endl;
                        printMatrix(add(m1,m2));
                    }
                    break;
                }
                case 2:
                {

                    if(m1.col!=m2.col || m1.row!=m2.row)
                    {
                        cout<<"参数错误"<<endl;
                    }
                    else{
                        cout<<"结果为："<<endl;
                        printMatrix(sub(m1,m2));
                    }
                    break;

                }
                case 3:
                {
                    if(m1.col!=m2.row)
                    {
                        cout<<"参数错误"<<endl;
                    }
                    else{
                        cout<<"结果为："<<endl;
                        printMatrix(Mul(m1,m2));
                    }
                    break;
                }
                default:
                    break;
            }
        }
        else if(4 == num)
        {
            int number = 1;
            cout<<"请输入矩阵"<<endl;
            Matrix m = CreateMatrix();
            cout<<"请输入数值"<<endl;
            cin>>number;
            cout<<"矩阵为："<<endl;
            printMatrix(m);
            cout<<"数值为："<<endl;
            cout<<number<<endl;
            printMatrix(numMul(m,number));
        }
        else if(5 == num)
        {
            float *buffer, *p;            //定义数组首地址指针变量
            int row, num;                //定义矩阵的行数和矩阵元素个数
            int i, j;
            float determ;                //定义矩阵的行列式
            float a[N][N], b[N][N];
            int n;
            cout << "请输入矩阵的行数: ";
            cin >> row;
            num = 2 * row * row;
            buffer = (float *)calloc(num, sizeof(float));        //分配内存单元
            p = buffer;
            if (NULL != p)
            {
                for (i = 0; i < row; i++)
                {
                    cout << "请依次输入第" << i+1 << "行的元素: ";
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
            print(buffer, row);                //打印该矩阵
            determ = MatDet(buffer, row);    //求整个矩阵的行列式
            p = buffer + row * row;
            if (determ != 0)
            {
                cout << "矩阵的行列式为:" << determ << endl;
                for (i = 0; i < row; i++)    //求逆矩阵
                {
                    for (j = 0; j < row; j++)
                    {
                        *(p+j*row+i) = Creat_M(buffer, i, j, row)/determ;
                    }
                }
                cout << "矩阵的逆矩阵为:" << endl;
                print(p, row);                //打印该矩阵
            }
            else
            {
                cout << "行列式是0，没有逆矩阵！\n";
            }
            free(buffer);        //释放内存空间
            getchar();
        }
        else if(6 == num)
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
    int row,col;
    cout << "输入行数与列数：" << endl;
    cin >> row >> col;
    float **enterMatrix ;
    enterMatrix=(float**) malloc(row*sizeof(float*)) ;
    for(int i=0; i<row; i++)
        enterMatrix[i] = (float *)malloc(col * sizeof(float));
    cout<<"输入你的矩阵："<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
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
Matrix InitMatrix(int row,int col)    
{
    Matrix m;
    float **matrix ;
    matrix=(float**) malloc(row*sizeof(float*)) ;
    for(int i=0; i<row; i++)
        matrix[i] = (float *)malloc(col * sizeof(float));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
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
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
        {
            m1.matrix[i][j] = m1.matrix[i][j] +m2.matrix[i][j];
        }
    }
    return m1;
}

//-----------------------------------------------
//功能: 减运算
//入口参数: 两个矩阵的名字
//返回值: 结果矩阵
//----------------------------------------------
Matrix sub(Matrix m1, Matrix m2)      
{
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
        {
            m1.matrix[i][j] = m1.matrix[i][j] -m2.matrix[i][j];
        }
    }
    return m1;
}

//-----------------------------------------------
//功能: 单独计算一行*一列, row为M1的行,col为m2的列
//入口参数: 两个矩阵的名字, M1的行,m2的列
//返回值: 整型结果
//----------------------------------------------
int calRowCol(Matrix M1,Matrix M2,int row,int col)  
{
    int result = 0;
    int same = M1.col;
    for(int j=0; j<same; j++)
    {
        result+=M1.matrix[row][j]*M2.matrix[j][col];
    }

    return result;
}

//-----------------------------------------------
//功能: 乘运算
//入口参数: 两个矩阵的名字
//返回值: 结果矩阵
//----------------------------------------------
Matrix Mul(Matrix m1, Matrix m2)       
{
    Matrix result = InitMatrix(m1.row,m2.col);
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m2.col; j++)
        {
            result.matrix[i][j] = calRowCol(m1,m2,i,j);
        }
    }
    return result;
}

//-----------------------------------------------
//功能: 数乘运算
//入口参数: 矩阵名字，要乘的数
//返回值: 结果矩阵
//----------------------------------------------
Matrix numMul(Matrix m, int num) 
{
    cout<<"数值:"<<num<<endl;
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
        {
            m.matrix[i][j] = m.matrix[i][j]*num;
        }
    }
    return m;
}

//-----------------------------------------------
//功能: 输出矩阵
//入口参数: 矩阵名字
//返回值: 结果矩阵
//----------------------------------------------
Matrix printMatrix(Matrix m)        
{
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
        {
            cout << m.matrix[i][j] << "  ";
        }
        cout<<endl;
    }
}

//-----------------------------------------------
//功能: 求矩阵(n*n)的行列式
//入口参数: 矩阵的首地址，矩阵的行数
//返回值: 矩阵的行列式值
//----------------------------------------------
float MatDet(float *p, int n)
{
    int r, c, m;
    int lop = 0;
    float result = 0;
    float mid = 1;
    if (n != 1)
    {
        lop = (n == 2) ? 1 : n;             //控制求和循环次数,若为2阶，则循环1次，否则为n次
        for (m = 0; m < lop; m++)
        {
            mid = 1;                        //顺序求和, 主对角线元素相乘之和
            for (r = 0, c = m; r < n; r++, c++)
            {
                mid = mid * (*(p+r*n+c%n));
            }
            result += mid;
        }
        for (m = 0; m < lop; m++)
        {
            mid = 1;                        //逆序相减, 减去次对角线元素乘积
            for (r = 0, c = n-1-m+n; r < n; r++, c--)
            {
                mid = mid * (*(p+r*n+c%n));
            }
            result -= mid;
        }
    }
    else
        result = *p;
    return result;
}
//----------------------------------------------------------------------------
//功能: 求k*k矩阵中元素A(m, n)的代数余之式
//入口参数: k*k矩阵的首地址，矩阵元素A的下标m,n,矩阵行数k
//返回值: k*k矩阵中元素A(m, n)的代数余之式
//----------------------------------------------------------------------------
float Creat_M(float *p, int m, int n, int k)
{
    int len;
    int i, j;
    float mid_result = 0;
    int sign = 1;
    float *p_creat, *p_mid;
    len = (k-1)*(k-1);            //k阶矩阵的代数余之式为k-1阶矩阵
    p_creat = (float*)calloc(len, sizeof(float)); //分配内存单元
    p_mid = p_creat;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (i != m && j != n) //将除第i行和第j列外的所有元素存储到以p_mid为首地址的内存单元
            {
                *p_mid++ = *(p+i*k+j);
            }
        }
    }
    sign = (m+n)%2 == 0 ? 1 : -1;    //代数余之式前面的正、负号
    mid_result = (float)sign*MatDet(p_creat, k-1);
    free(p_creat);
    return mid_result;
}

//-----------------------------------------------------
//功能: 打印n*n矩阵
//入口参数: n*n矩阵的首地址,矩阵的行数n
//返回值: 无返回值
//-----------------------------------------------------
void print(float *p, int n)
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