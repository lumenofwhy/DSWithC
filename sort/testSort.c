#include <stdio.h>
#include "bubbleSort/bubbleSort.h"
#include "heapSort/heapSort.h"
#include "insertSort/insertSort.h"
#include "mergeSort/mergeSort.h"
#include "quickSort/quickSort.h"
#include "radixSort/radixSort.h"
#include "selectSort/selectSort.h"
#include "shellSort/shellSort.h"


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
    printf("------------ Before ------------\n");
    Show(arr, sizeof(arr) / sizeof(arr[0]));
    RadixSort(arr, sizeof(arr) / sizeof(arr[0]));
    printf("------------ After -------------\n");
    Show(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
