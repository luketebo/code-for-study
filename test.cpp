#include <iostream>
#include <fstream>
#include "math.h"
#include <string>
#include "stdio.h"
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cassert>
#include <map>
#include <list>
#include <iomanip>

using std::cout;
using std::endl;
using std::ostringstream;
using std::vector;
using namespace std;

#define N 34 //客户与仓库总数目，客户实际只有33个。改
class Customer
{
public:
    // static int count; //jobs numbered from "0"
    int CustomerNo; //客户编号(包括depot)0表示depot;
    double C_Cap;   //需求量

public:
    Customer()
    {
        CustomerNo = -1;
        C_Cap = 0;
    }
};

class Vehicle
{
public:
    int VehicleNo;     //车辆号码；
    double V_Cap;      ////载重能力；
    double route_time; ///路径时间；

public:
    Vehicle()
    {
        VehicleNo = -1;
        V_Cap = 0;
        route_time = -1;
    }
};

class Coordinate
{
public:
    double x, y;

public:
    Coordinate()
    {
        x;
        y;
    }
};

void distance(Coordinate *CDN, double **d)
{ /////这是一个距离公式
    double a, b, c;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            a = CDN[i].x - CDN[j].x; /////两点之间横坐标相减
            b = CDN[i].y - CDN[j].y; /////两点之间纵坐标相减
            a = pow(a, 2);           //////////平方
            b = pow(b, 2);           //////////平方
            c = a + b;               //////////求和
            d[i][j] = sqrt(c);       ///开方
        }
    }
}
double cost(Customer *CS, Vehicle *VH, int **Route, int *Array, int Vehicle_number, double **DistanceMatrix, int *Sequence)
{
    int i, j, k, p, temp, count;
    int customer1, customer2;
    double sum, max, temp1, distance;
    // for (i = 0; i < N; i++)
    //	Sequence[i] = 0;

    for (i = 0; i < Vehicle_number; i++) /////初始化
    {
        VH[i].route_time = 0; //行驶距离初始值为0
    }
    for (i = 0; i < Vehicle_number; i++) /////计算路径累计时间
    {
        sum = 0;
        for (j = 0; j < Array[i] - 1; j++)
        {

            customer1 = Route[i][j];
            customer2 = Route[i][j + 1];
            distance = DistanceMatrix[customer1][customer2];

            sum = sum + distance;

            // sum=sum+DistanceMatrix[Route[i][j]][Route[i][j+1]];
        }
        VH[i].route_time = sum;
    }
    sum = 0;
    for (i = 0; i < Vehicle_number; i++) /////计算所有路径时间之和
    {
        sum = sum + VH[i].route_time;
    }

    return (sum);
}
void GenerateInitialSequence(Customer *CS, Vehicle *VH, int **Route, int *Array, int Vehicle_number, int Customer_number, double **DistanceMatrix, int *Sequence)
{ ////////例子：路径形式 0-1-2-3 路径中点的数目（包括0）有4个
    int i, j, k, temp, customer, customer1;
    double min;
    int *Order;       //顾客数
    double *Delivery; //每辆车的运载量
    Order = new int[Customer_number];
    Delivery = new double[Vehicle_number];

    //初始化（给数组赋值）-1代表没有含义
    for (i = 0; i < Vehicle_number; i++) //////每条路径的出发点为0（配送中心），含有的客户数目为1   for循环：做同样的操作
    {
        Array[i] = 1;    ///////第i辆车的客户数目是1
        Route[i][0] = 0; ////第i辆车的第0个位置是仓库0
        Delivery[i] = 0; ///第i辆车的运输量是0
    }

    for (i = 0; i < Customer_number; i++) //把44个客户放进去
    {
        Order[i] = i + 1; ///////客户数组  order[4]=5
    }

    /////////////////最近邻点法选择客户点在路径中的位置/////////////////////////////////////////////////////////////////////
    /*for (i = 0; i < Vehicle_number; i++)//依次给每条路径安排与0点最近的一个点
    {
        min = 20000; temp = 0;
        for (j = 0; j < Customer_number; j++)//j执行44次
        {
            //////将离0点最近的m个点分配给m辆车
            customer = Order[j];////当前客户 顾客数组 1 
            if (customer == -1)
                continue;//跳出当次j循环，还要开始下次的j循环
            customer1 = Route[i][Array[i] - 1];///出发点ggggggg    customer1 = Route[0][1 - 1]; 第i辆车的第0个位置是仓库0
            if (min > DistanceMatrix[customer1][customer])//gggggggggg  DistanceMatrix[0][Order[0]]  距离矩阵
            {
                min = DistanceMatrix[customer1][customer];//将0到当前客户的距离赋给min     ggggggggggg
                temp = customer;//离0最近的客户ggggggggggggg
            }
        }

        Route[i][Array[i]] = temp;//Route[i][Array[i]] = temp  新的客户在当前客户的后面
        Delivery[i] = CS[temp].C_Cap;//将上一个客户的运载量加上
        Array[i] = Array[i] + 1;   //更新当前客户
        Order[temp - 1] = -1;///////下次再取到这个客户时就等于-1代表用过啦
    }*/
    ///////////////////////////////////////////////////执行上述程序后，每条路径都有2个点了。0-X
    for (i = 0; i < Vehicle_number; i++)
    {
        cout << "第" << i << "条路径中访问的个数是" << Array[i] << endl;
        ;
        for (j = 0; j < Array[i]; j++)
            cout << setw(4) << Route[i][j];
        cout << endl; // endl换行
    }
    cout << endl;

    for (k = 0; k < Customer_number; k++)
    {
        for (i = 0; i < Vehicle_number; i++) /////每条路径选择最短的点加入
        {
            temp = 0;
            for (j = 0; j < Customer_number; j++)
            {
                if (Order[j] == -1)
                    temp = temp + 1; //计数用，累计ORDER数组里面值为-1的个数
            }
            if (temp == Customer_number)
                break; /////终止FOR循环
            ///////上述用于判断order数组里面的客户是否已经用完了。

            min = 20000;
            temp = 0;
            for (j = 0; j < Customer_number; j++) //////将所有的客户点装载到车辆中
            {
                customer = Order[j]; // 1
                if (customer == -1)
                    continue;
                if (Delivery[i] + CS[customer].C_Cap > VH[i].V_Cap)
                    continue;
                /////////////////////////////////////////这里可能跟输出距离有关
                customer1 = Route[i][Array[i] - 1]; /////把第i条路径的最后一个客户赋给customer1；customer1为当前点，customer为候选点hgggggggg

                if (min > DistanceMatrix[customer1][customer]) // ggggggg
                {
                    min = DistanceMatrix[customer1][customer];
                    temp = customer;
                }
            }
            if (temp == 0) ///////没有合适的客户
                continue;
            else
            {
                Delivery[i] = Delivery[i] + CS[temp].C_Cap;
                Route[i][Array[i]] = temp; /////把temp放在第i条路径的最后一个客户的后面。
                Array[i] = Array[i] + 1;   /////计数又增加1
                Order[temp - 1] = -1;      ///
                i = i - 1;                 /////第i条路径还可以继续加入客户，所以减1，和增1抵消
            }
        }
    }

    /*
    array[]
    Route[]
    Order[]
    Delivery[]

    */

    // ---------------------- 分割线 ---------------------- //

    for (i = 0; i < Vehicle_number; i++)
    {
        cout << "第" << i << "条路径中访问的个数是" << Array[i] << endl;
        ;
        for (j = 0; j < Array[i]; j++)
            cout << setw(4) << Route[i][j];
        cout << endl;
    }
    cout << endl;

    cout << "计算各路径车辆实际载货量：";
    cout << endl;
    for (i = 0; i < Vehicle_number; i++)
    {
        // Delivery[i] = Delivery[i ]+ CS[customer ].C_Cap;
        cout << "第" << i << "条路径总载货量是" << Delivery[i] << endl;
        ;
    }
    cout << endl;
    /////////////////贪婪法选择客户点在路径中的位置/////////////////////////////////////////////////
    //////想一想，会不会有漏掉的客户呢？
    delete[] Order;
    delete[] Delivery;
}

void main()
{
    int i, j, m, customer;

    double sumCost;

    string CoordinateRoute, CustomerRoute, VehicleRoute, ResultRoute;

    int *Sequence = new int[N]; //第一种定义数组的模式；
    // int Sequence[N];//第二种定义数组的模式；

    int *Array;         //定义数组
    Array = new int[N]; //第三种定义数组大小的模式；

    int **Route = new int *[N]; //定义数组大小；二维数组一般采取这种。
    for (i = 0; i < N; i++)
        Route[i] = new int[N];

    // int* Sequence = new int[10];
    // int** Route = new int* [5];
    // for (i = 0; i < 5; i++)
    //	Route[i] = new int[10];

    double **DistanceMatrix = new double *[N]; //定义数组大小
    for (i = 0; i < N; i++)
        DistanceMatrix[i] = new double[N];

    /// <summary>
    /// ///////////给数组赋值
    /// </summary>
    /*for (i = 0; i < 5; i++)
    {
        Sequence[i] =6* i +1;
    }

    for (i = 0; i < 5; i++)
    {
        cout<<Sequence[i]<< setw(4);
    }*/

    for (i = 0; i < N; i++) /////////初始化距离矩阵
    {
        for (j = 0; j < N; j++)
            DistanceMatrix[i][j] = -1;
    }

    for (i = 0; i < N; i++) ////////初始化最优解
    {
        Array[i] = -1;
        for (j = 0; j < N; j++)
            Route[i][j] = -1;
    }

    for (i = 0; i < 2; i++) ////////初始化最优解
    {
        Array[i] = -1;
        for (j = 0; j < 3; j++)
            Route[i][j] = i + j;
    }

    Customer *CS; //定义类
    Vehicle *VH;
    Coordinate *CDN;

    CS = new Customer[N];
    VH = new Vehicle[N];
    CDN = new Coordinate[N];

    clock_t start, stop; ///计时
    double duringtime;   //////计时

    printf("输入不大于%d的车辆数目:", N - 1);
    scanf_s("%d", &m);
    printf("车辆数目为：%d\n", m);

    start = clock(); /////开始计时

    /// <summary>
    /// /读取数据
    /// </summary>
    CoordinateRoute = "E:\\ConsoleApplication1\\data1_45_6\\coordinate_45.xls";
    CustomerRoute = "E:\\ConsoleApplication1\\data1_45_6\\customer_45.xls";
    VehicleRoute = "E:\\ConsoleApplication1\\data1_45_6\\vehicle_45.xls";
    ResultRoute = "E:\\ConsoleApplication1\\data1_45_6\\result_45.xls";

    ifstream inCoordinateFile(CoordinateRoute.c_str());
    ifstream inCustomerFile(CustomerRoute.c_str());
    ifstream inVehicleFile(VehicleRoute.c_str());
    ofstream outFile(ResultRoute.c_str());

    printf("输出各点的坐标：\n");
    char X[6], Y[6];
    inCoordinateFile >> X >> Y;
    cout << setiosflags(ios::left) << setw(6) << X << setw(6) << Y << endl;
    for (int k = 0; k < N; k++)
    {
        inCoordinateFile >> CDN[k].x >> CDN[k].y;
        cout << setiosflags(ios::left) << setw(6) << CDN[k].x << setw(6) << CDN[k].y << endl;
    }

    printf("输出客户点的相关数据：\n");
    char customerName[20], capName[20];
    inCustomerFile >> customerName >> capName;
    cout << setw(13) << customerName << setw(13) << capName << setw(13) << endl;
    for (i = 0; i < N; i++)
    {
        inCustomerFile >> CS[i].CustomerNo >> CS[i].C_Cap;
        cout << setiosflags(ios::left) << setw(13) << CS[i].CustomerNo << setw(13) << CS[i].C_Cap << setw(13)
             << endl;
    }

    printf("输出车辆的相关数据：\n");
    char vehicleName[20], capacityName[20];
    inVehicleFile >> vehicleName >> capacityName;
    cout << setiosflags(ios::left) << setw(13) << vehicleName << setw(13) << capacityName << endl;
    for (i = 0; i < m; i++)
    {
        inVehicleFile >> VH[i].VehicleNo >> VH[i].V_Cap;
        cout << setiosflags(ios::left) << setw(13) << VH[i].VehicleNo << setw(13) << VH[i].V_Cap << endl;
    }

    distance(CDN, DistanceMatrix);

    GenerateInitialSequence(CS, VH, Route, Array, m, N - 1, DistanceMatrix, Sequence); ////////生成初始解

    sumCost = cost(CS, VH, Route, Array, m, DistanceMatrix, Sequence);

    printf("输出初始解：\n");
    printf("sumCost=%9f\n", sumCost);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < Array[i]; j++)
        {
            customer = Route[i][j];
            printf("%6d", customer);
        }
        printf("\n");
    }

    stop = clock();                                     //////结束计时
    duringtime = (stop - start) * 1.0 / CLOCKS_PER_SEC; ////////程序运行时间，换算单位秒
    cout << "总耗时：" << duringtime << "s" << endl;
    // printf("\n\n总耗时：%dms!\n\n",(dwEnd-dwStart));
    //*************写数据**************************
    outFile << "Object"
            << "\t" << endl;
    outFile << sumCost << '\t';
    outFile << "RunTime"
            << "\t" << endl;
    outFile << duringtime << '\t';
    outFile << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < Array[i]; j++)
            outFile << Route[i][j] << '\t';
        outFile << endl;
    }
    //*************写数据**************************

    delete[] CDN;
    delete[] CS;
    delete[] VH;
    delete[] Array;
    delete[] Sequence;
    for (i = 0; i < N; i++)
        delete Route[i];
    delete[] Route;
    for (i = 0; i < N; i++)
        delete DistanceMatrix[i];
    delete[] DistanceMatrix;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
