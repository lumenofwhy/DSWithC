#include <stdio.h>
#include "selectSort.h"

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
