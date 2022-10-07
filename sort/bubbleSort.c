#include <stdio.h>

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
    BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    Show(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}