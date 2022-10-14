#include <stdio.h>
#include "listqueue.h"
#include "radixSort.h"

//获取最大数字的位数
static int
Getfigure(int* arr, int len)
{
    int max = arr[0]; //最大值
    for (int i = 1; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    // 987->3
    int count = 0;
    while (max != 0)
    {
        count++;
        max /= 10;
    }
    return count;
}

//获取十进制整数右数第figure位的数字,figure从0开始
//例如(123,0)-->3;(123,1)-->2;(123,2)-->1;(123,3)-->0
static int GetNum(int n, int figure)
{
    for (int i = 0; i < figure; i++)
    {
        n /= 10;
    }
    return n % 10;
}

//获取十进制整数右数第figure位的数字
// GetNum()
//基数排序(桶排序)
void RadixSort(int* arr, int len) // O(d*n),O(n),稳定
{
    //需要10个链式队列,存放进队的数字
    LinkQueue queArr[10]; //定义了10个队头;
    for (int i = 0; i < 10; i++)
    {
        InitQueue(&queArr[i]);
    }
    //得到最大数字的位数,确定进队和出队的次数
    int count = Getfigure(arr, len);
    int index;                      //队列的下标
    for (int i = 0; i < count; i++) //两个含义:1.次数;2.处理每个数字从右往左的第i个数字
    {
        for (int j = 0; j < len; j++) //遍历数组并入队
        {
            index = GetNum(arr[j], i); // index保存arr[j]应该进入对的队列下标
            //获取十进制整数右数第i位的数字
            Push(&queArr[index], arr[j]); //将数字存放的对应的队列;
        }

        //出队
        int j = 0;
        for (int k = 0; k < 10; k++)
        {
            while (!IsEmpty(&queArr[k]))
            {
                DeQueue(&queArr[k], &arr[j++]);
            }
        }
        //销毁
        for (int i = 0; i < 10; i++)
        {
            Destroy(&queArr[i]);
        }
    }
}
