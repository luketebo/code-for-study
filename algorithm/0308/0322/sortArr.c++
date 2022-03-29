#include <iostream>
using namespace std;
void merge(int* arr, int low, int mid, int height)
{
    int i, j, k;
    int tempA[100], tempB[100];
    int numL = mid - low + 1;
    int numR = height - mid;
    for(int i = 0; i < 100; i++){
        tempA[i] = 0;
        tempB[i] = 0;
    }
    for (int i = 0; i < numL; i++)
    {
        tempA[i] = arr[low - 1 + i];
    }
    tempA[i] = 114514;
    for (int i = 0; i < numR; i++)
    {
        tempB[i] = arr[mid + 1];
    }
    tempB[i] = 114514;
    
    i = 0;
    j = 0;
    for (k = low; k <= height; k++)
    {
        if (tempA[i] <= tempB[j])
        {
            arr[k - 1] = tempA[i];
            i++;
        }
        else
        {
            arr[k - 1] = tempB[j];
            j++;
        }
    }
}
void MergeSor(int* arr, int low, int height)
{
    if (low >= height)
        return ;
    int mid = low + (height - low) / 2;
    MergeSor(arr, low, mid);
    MergeSor(arr, mid + 1, height);
    merge(arr, low, mid, height);
}
int main()
{

    int i = 0;
    int arr[8] = {3, 5, 6, 8, 1, 2, 4, 0};
    MergeSor(arr, 1, 8);
    while (i < 8)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}