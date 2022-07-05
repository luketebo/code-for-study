#include "iostream"
using namespace std;
/**
 * @brief 
 * 
 */
void Bubble_sort(int arr[], int count)
{
    for (int i = 0; i < count; i++) 
    {
        for (int j = i; j < count; j++ ) 
        {
            int temp = 0;
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void bubble_sort(int arr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count; j++)
        {
            int temp = 0;
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void bubble_sort(int arr[], int count) 
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count; j++) 
        {
            int temp = 0;
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() 
{

    return 0;
}
