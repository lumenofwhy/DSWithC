#include <stdio.h>
#include "bubbleSort.h"

void BubbleSort(int* arr, int len) // O(n^2),O(1),稳定
{
    int tmp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j + 1 < len - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
