#include <stdio.h>

void SelectSort(int* arr, int len) // O(n^2),O(1),不稳定
{
    int minIndex; //最小值的下标;
    int tmp;
    for (int i = 0; i < len - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < len; j++) //找最小值
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        //最小值和待排序的第一个值交换
        if (minIndex != i)
        {
            tmp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = tmp;
        }
    }
}

void Show(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main()
{
    int arr[] = {4, 6, 8, 9, 2, 34, 56, 7, 12, 66, 99, 36, 87};
    Show(arr, sizeof(arr) / sizeof(arr[0]));
    SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
    Show(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}