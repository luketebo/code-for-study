#include "arrange/arrange_full.hpp"
#include "merge/merge.hpp"
#include "lst/lst.hpp"
#include "longest/longest.hpp"
#include "matrix/matrix.hpp"
#include <iostream>
using namespace std;
int main()
{
    int choose = 0;
    cout << "Hello, data structure!" << endl;
    while(true){
        cout << "***********************************************************"<< endl;
        cout << "1. 全排列\t 2. 归并\t         3. 最优二叉搜索树" << endl;
        cout << "4. 最大字段和\t 5. 最大公共子序列长度\t 6. 抢劫问题" << endl;
        cout << "6. 矩阵运算\t 7. 退出" << endl; 
        cout << "Please input the number of the data structure you want to use: " << endl;
        cin >> choose;
        switch(choose){
            case 1:
                ARRANGE a;
                a.main();
                break;
            case 2:
                MERGE m;
                m.main();
                break;
            case 3:

                break;
            case 4:
                SQLIST l;
                l.main();
                break;
            case 5:
                SQLISTC lc;
                lc.main();
                break;
            case 6:
            {
                MATRIX matrix;
                matrix.main();
                break;
            }
            case 7:

                return 0;
        }
    }
    return 0;
}