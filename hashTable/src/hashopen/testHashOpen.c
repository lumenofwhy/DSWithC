#include <stdio.h>
#include "hashOpen.h"

int main()
{
    //测试hashOpen
    HashTable ht;
    InitHashTable(ht);
    int arr[16] = {3, 5, 7, 1, 2, 9, 28, 25, 6, 11, 10, 15, 17, 23, 34, 19};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        Insert(ht, arr[i]);
    }
    Show(ht);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d  :  %d \n", arr[i], Search(ht, arr[i]));
    }
    printf("\n");
    printf("%d\n", Search(ht, 100));

    return 0;
}
