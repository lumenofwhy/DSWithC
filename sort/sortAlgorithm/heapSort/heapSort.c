#include <stdio.h>
#include "heapSort.h"
//堆排序:
//父--->子:i--->2*i+1,2*i+2;
//子--->父:i---->(i-1)/2

//一次堆调整
void HeapAdjust(int* arr, int start, int end) // O(logn)
{
    int tmp = arr[start];
    for (int i = 2 * start + 1; i <= end; i = 2 * i + 1)
    {
        if (i < end && arr[i] < arr[i + 1]) //有右孩子,并且左孩子的值小于右孩子
        {
            i++;
        } // i一定是左右孩子的最大值

        if (arr[i] > tmp)
        {
            arr[start] = arr[i];
            start = i;
        } else
        {
            break;
        }
    }
    arr[start] = tmp;
}

void HeapSort(int* arr, int len) // O(nlogn),O(1),不稳定
{
    //第一次建立大根堆,从后往前,多次调整
    int i;
    for (i = (len - 1 - 1) / 2; i >= 0; i--) //从最后一棵子树开始,O(nlogn)
    {
        HeapAdjust(arr, i, len - 1);
    }
    //每次将根和待排序的最后一个交换,然后再调整
    int tmp;
    for (i = 0; i < len - 1; i++) // O(nlogn)
    {
        tmp = arr[0];
        arr[0] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;

        HeapAdjust(arr, 0, len - 1 - i - 1);
    }
}
