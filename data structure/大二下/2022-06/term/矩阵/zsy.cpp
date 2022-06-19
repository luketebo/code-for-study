#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
#define  N  10                //���巽���������Ϊ10
typedef struct
{
    
    int row,col;        //�ṹ��
    float **matrix;     //��άָ�룬Ŀ���Ƕ�̬�����ڴ�
} Matrix;

typedef struct
{
    char *name;
    char *number;
} Student;

Matrix CreateMatrix();                               //�û��������
Matrix InitMatrix(int row,int col);                  //��ʼ��һ����Ϊrow��Ϊcol����
Matrix add(Matrix m1, Matrix m2);                    //������ 
Matrix sub(Matrix m1, Matrix m2);                    //������
int calRowCol(Matrix M1,Matrix M2,int row,int col);  //��������һ��*һ�У�rowΪM1���� colΪm2����
Matrix Mul(Matrix m1, Matrix m2);                    //������
Matrix numMul(Matrix m, int num);                    //��������
float MatDet(float *p, int n);                    //����������ʽ
float Creat_M(float *p, int m, int n, int k);    //�����Ԫ��A(m, n)�Ĵ�����֮ʽ
void print(float *p, int n);                    //�������n*n
Matrix printMatrix(Matrix m);                        //�������


int main()
{
    int num = 0;
    while(1)
    {
        cout<<"*************************************\n";
        cout<<"*              �˵�                 *\n";
        cout<<"*          1.�������               *\n";
        cout<<"*          2.�������               *\n";
        cout<<"*          3.�������               *\n";
        cout<<"*          4.��������               *\n";
        cout<<"*          5.��������               *\n";        
        cout<<"*          6.�˳�                   *\n";
        cout<<"*************************************\n";
        cout<<"����������ѡ��";
        cin>>num;
        if(1 == num|| 2 == num || 3 == num)
        {
            cout<<"���������1"<<endl;
            Matrix m1 = CreateMatrix();
            cout<<"���������2"<<endl;
            Matrix m2 = CreateMatrix();
            cout<<"������Ϊ"<<endl;
            printMatrix(m1);
            cout<<endl;
            printMatrix(m2);
            switch(num)
            {
                case 1:
                {
                    if(m1.col!=m2.col || m1.row!=m2.row)
                    {
                        cout<<"���в�ͬ"<<endl;
                    }
                    else{
                        cout<<"���Ϊ��"<<endl;
                        printMatrix(add(m1,m2));
                    }
                    break;
                }
                case 2:
                {

                    if(m1.col!=m2.col || m1.row!=m2.row)
                    {
                        cout<<"��������"<<endl;
                    }
                    else{
                        cout<<"���Ϊ��"<<endl;
                        printMatrix(sub(m1,m2));
                    }
                    break;

                }
                case 3:
                {
                    if(m1.col!=m2.row)
                    {
                        cout<<"��������"<<endl;
                    }
                    else{
                        cout<<"���Ϊ��"<<endl;
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
            cout<<"���������"<<endl;
            Matrix m = CreateMatrix();
            cout<<"��������ֵ"<<endl;
            cin>>number;
            cout<<"����Ϊ��"<<endl;
            printMatrix(m);
            cout<<"��ֵΪ��"<<endl;
            cout<<number<<endl;
            printMatrix(numMul(m,number));
        }
        else if(5 == num)
        {
            float *buffer, *p;            //���������׵�ַָ�����
            int row, num;                //�������������;���Ԫ�ظ���
            int i, j;
            float determ;                //������������ʽ
            float a[N][N], b[N][N];
            int n;
            cout << "��������������: ";
            cin >> row;
            num = 2 * row * row;
            buffer = (float *)calloc(num, sizeof(float));        //�����ڴ浥Ԫ
            p = buffer;
            if (NULL != p)
            {
                for (i = 0; i < row; i++)
                {
                    cout << "�����������" << i+1 << "�е�Ԫ��: ";
                    for (j = 0; j < row; j++)
                    {
                        cin >> *p++;
                    }
                }
            }
            else
            {
                cout << "�޷������ڴ�!\n";
            }
            cout << "ԭʼ����:\n";
            print(buffer, row);                //��ӡ�þ���
            determ = MatDet(buffer, row);    //���������������ʽ
            p = buffer + row * row;
            if (determ != 0)
            {
                cout << "���������ʽΪ:" << determ << endl;
                for (i = 0; i < row; i++)    //�������
                {
                    for (j = 0; j < row; j++)
                    {
                        *(p+j*row+i) = Creat_M(buffer, i, j, row)/determ;
                    }
                }
                cout << "����������Ϊ:" << endl;
                print(p, row);                //��ӡ�þ���
            }
            else
            {
                cout << "����ʽ��0��û�������\n";
            }
            free(buffer);        //�ͷ��ڴ�ռ�
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
//����:�û��������
//��ڲ���: ��
//����ֵ: �������
//----------------------------------------------
Matrix CreateMatrix()      
{
    Matrix m;
    int row,col;
    cout << "����������������" << endl;
    cin >> row >> col;
    float **enterMatrix ;
    enterMatrix=(float**) malloc(row*sizeof(float*)) ;
    for(int i=0; i<row; i++)
        enterMatrix[i] = (float *)malloc(col * sizeof(float));
    cout<<"������ľ���"<<endl;
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
//����:��ʼ��һ����Ϊrow��Ϊcol����
//��ڲ���: �С���
//����ֵ: �������
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
//����: ������
//��ڲ���: �������������
//����ֵ: �������
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
//����: ������
//��ڲ���: �������������
//����ֵ: �������
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
//����: ��������һ��*һ��, rowΪM1����,colΪm2����
//��ڲ���: �������������, M1����,m2����
//����ֵ: ���ͽ��
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
//����: ������
//��ڲ���: �������������
//����ֵ: �������
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
//����: ��������
//��ڲ���: �������֣�Ҫ�˵���
//����ֵ: �������
//----------------------------------------------
Matrix numMul(Matrix m, int num) 
{
    cout<<"��ֵ:"<<num<<endl;
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
//����: �������
//��ڲ���: ��������
//����ֵ: �������
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
//����: �����(n*n)������ʽ
//��ڲ���: ������׵�ַ�����������
//����ֵ: ���������ʽֵ
//----------------------------------------------
float MatDet(float *p, int n)
{
    int r, c, m;
    int lop = 0;
    float result = 0;
    float mid = 1;
    if (n != 1)
    {
        lop = (n == 2) ? 1 : n;             //�������ѭ������,��Ϊ2�ף���ѭ��1�Σ�����Ϊn��
        for (m = 0; m < lop; m++)
        {
            mid = 1;                        //˳�����, ���Խ���Ԫ�����֮��
            for (r = 0, c = m; r < n; r++, c++)
            {
                mid = mid * (*(p+r*n+c%n));
            }
            result += mid;
        }
        for (m = 0; m < lop; m++)
        {
            mid = 1;                        //�������, ��ȥ�ζԽ���Ԫ�س˻�
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
//����: ��k*k������Ԫ��A(m, n)�Ĵ�����֮ʽ
//��ڲ���: k*k������׵�ַ������Ԫ��A���±�m,n,��������k
//����ֵ: k*k������Ԫ��A(m, n)�Ĵ�����֮ʽ
//----------------------------------------------------------------------------
float Creat_M(float *p, int m, int n, int k)
{
    int len;
    int i, j;
    float mid_result = 0;
    int sign = 1;
    float *p_creat, *p_mid;
    len = (k-1)*(k-1);            //k�׾���Ĵ�����֮ʽΪk-1�׾���
    p_creat = (float*)calloc(len, sizeof(float)); //�����ڴ浥Ԫ
    p_mid = p_creat;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (i != m && j != n) //������i�к͵�j���������Ԫ�ش洢����p_midΪ�׵�ַ���ڴ浥Ԫ
            {
                *p_mid++ = *(p+i*k+j);
            }
        }
    }
    sign = (m+n)%2 == 0 ? 1 : -1;    //������֮ʽǰ�����������
    mid_result = (float)sign*MatDet(p_creat, k-1);
    free(p_creat);
    return mid_result;
}

//-----------------------------------------------------
//����: ��ӡn*n����
//��ڲ���: n*n������׵�ַ,���������n
//����ֵ: �޷���ֵ
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