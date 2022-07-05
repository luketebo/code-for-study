#include <iostream>
using namespace std;
/**
 * @brief 
 * 
 * @param a 
 * @param begin 
 * @param end 
 * 
 * 每次选取数组中的第一个元素，然后让之后的元素进行全排列
 */
void Arrange_Full(char a[], int begin, int end) 
{
    int i, j;
    if (begin == end)
    {
        for (i = 0; i <= end; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        for (j = begin; j <= end; j++)
        {
            swap(a[j], a[begin]);
            Arrange_Full(a, begin + 1, end);
            swap(a[j], a[begin]);
        }
    }
}
void arrange_full(char a[], int begin, int end)
{
    int i, j;
    if (begin == end)
    {
        for (i = 0; i <= end; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        for (j = begin; j <= end; j++ )
        {
            swap(a[j], a[begin]);
            arrange_full(a, begin + 1, end);
            swap(a[j], a[begin]);
        }
    }
}
void Arrange_full(char a[], int begin, int end)
{
    int i, j;
    if (begin == end)
    {
        for (i = 0; i <= end; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        for (j = begin; j <= end; j++)
        {
            swap(a[j], a[begin]);
            Arrange_full(a, begin + 1, end);
            swap(a[j], a[begin]);
        }
    }
}
int main()
{

    return 0;
}