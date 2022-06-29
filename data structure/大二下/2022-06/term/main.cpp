#include "arrange/arrange_full.hpp"
#include "merge/merge.hpp"
#include "lst/lst.hpp"
#include "longest/longest.hpp"
#include "matrix/matrix.hpp"
#include "BSB.hpp"
#include "LOOT.hpp"
#include <iostream>
using namespace std;
int main()
{
    int choose = 0;
    cout << endl;
    cout << "                        Hello, data structure!                 " << endl;
    while(true){
        cout << endl;
        cout << "***************************************************************"<< endl;
        cout << "* 1. 全排列\t 2. 归并排序\t         3. 最优二叉搜索树    *" << endl;
        cout << "* 4. 最大字段和\t 5. 最大公共子序列长度\t 6. 抢劫问题          *" << endl;
        cout << "* 7. 矩阵运算\t 8. 退出                                      *" << endl; 
        cout << "* Please input the number of the data structure you want to use: " << endl;
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
            {
                BSB b;
                b.main();
                break;
            }
            case 4:
                SQLISTC l;
                l.main();
                break;
            case 5:
                SQLIST lc;
                lc.main();
                break;
            case 6:
            {
                loot l;
                l.main();
                break;
            }
            case 7:
            {
                MATRIX matrix;
                matrix.main();
                break;
            }
            case 8:
                return 0;

        }
    }
    return 0;
}