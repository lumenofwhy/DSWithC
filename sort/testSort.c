#include <stdio.h>
#include "bubbleSort.h"
#include "heapSort.h"
#include "insertSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectSort.h"
#include "shellSort.h"

void Show(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(void)
{
    int arr[] = {4, 6, 8, 9, 2, 34, 56, 7, 12, 66, 99, 36, 87};

    printf("------------ Before ------------\n");

    Show(arr, sizeof(arr) / sizeof(arr[0]));
    RadixSort(arr, sizeof(arr) / sizeof(arr[0]));

    printf("------------ After -------------\n");

    Show(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}
