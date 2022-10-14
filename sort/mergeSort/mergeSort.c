#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mergeSort.h"

//一次归并
// gap:归并段的长度
static void Merge(int* arr, int len, int gap) // O(n)
{
    int low1 = 0;               //第一个归并段的起始下标;
    int high1 = low1 + gap - 1; //第一个归并段的结束下标;
    int low2 = high1 + 1;       //第二个归并段的起始下标;
    int high2 = low2 + gap < len ? low2 + gap - 1 : len - 1;
    int* brr = (int*)malloc(len * sizeof(int)); //存放归并好的数据;
    int i = 0;                                  // brr的下标;
    assert(brr != NULL);
    // 1.有两个归并段
    while (low2 < len)
    {
        //两个归并段都还有数据,需要比
        while (low1 <= high1 && low2 <= high2)
        {
            if (arr[low1] <= arr[low2])
            {
                brr[i++] = arr[low1++];
            } else
            {
                brr[i++] = arr[low2++];
            }
        }
        //一个归并段的数据已经完成了,另一个还有数据
        while (low1 <= high1)
        {
            brr[i++] = arr[low1++];
        }
        while (low2 <= high2)
        {
            brr[i++] = arr[low2++];
        }
        //下两个归并段
        low1 = high2 + 1;
        high1 = low1 + gap - 1;
        low2 = high1 + 1;
        high2 = low2 + gap < len ? low2 + gap - 1 : len - 1;
    }
    // 2.只有一个归并段
    while (low1 < len)
    {
        brr[i++] = arr[low1++];
    }
    // 3.将归并好的数据拷贝到arr中
    for (i = 0; i < len; i++)
    {
        arr[i] = brr[i];
    }

    free(brr); //不要忘记
}

//归并排序
void MergeSort(int* arr, int len) // O(nlogn),O(n),稳定
{
    for (int i = 1; i < len; i *= 2) // O(log n )
    {
        Merge(arr, len, i);
    }
}
