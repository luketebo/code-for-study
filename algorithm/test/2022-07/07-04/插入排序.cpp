#include <iostream>
using namespace std;
/**
 * @brief 
 * 
 * @param arr 
 * @param count 
 * 
 * 每次选取当前数组中的第一个，然后与之前的数组，进行排血
 */
void Insert_sort(int arr[], int count) 
{
    for (int i = 1; i < count; i++) {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--) 
        {
            int b = 0;
            b = arr[i];
            arr[j] = temp;
            arr[j + 1] = b;
        } 
    }
}
void insert_sort(int arr[], int count) 
{
    for (int i = 1; i < count; i++ ) 
    {
        int temp = arr[i]; // 每一次选取数组中的元素，然后之后进行排血
        for (int j = i - 1; j >= 0; j--) 
        {
            int b = 0;
            b = arr[i];
            arr[j] = temp;
            arr[j + 1] = b;
        }
    }
}
void test(int arr[], int count)
{
    for (int i = 1; i < count; i++) 
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            int b = 0;
            b = arr[i];
            arr[j] = temp;
            arr[j + 1] = b;
        }
    }
}
int main() 
{

    return 0;
}