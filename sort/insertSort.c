#include <stdio.h>

void InsertSort(int* arr, int len)
{
    // O(n²)
    // 正序查找位置
    int tmp;
    int i;
    int j;
    for (i = 1; i < len; i++)
    {
        // 从第二个数开始处理
        tmp = arr[i];
        for (j = 0; j < i; j++)
        {
            // 找到合适的位置
            if (arr[j] > tmp)
            {
                break;
            }
        }
        // 把后面的数据往后移动
        for (int k = i - 1; k >= j; k--)
        {
            arr[k + 1] = arr[k];
        }
        arr[j] = tmp;
    }
}

void InsertSort2(int* arr, int len)
{
    // O(n²)，最好的情况：O(n)
    // 空间复杂度：O(1)
    int j;
    int tmp;
    for (int i = 1; i < len; i++)
    {
        // 从第二个数开始处理
        tmp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            // 找到合适的位置
            if (arr[j] > tmp) // 后移arr[j]
            {
                arr[j + 1] = arr[j];
            } else
            {
                break;
            }
        }
        arr[j + 1] = tmp;
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
    InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
    Show(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
