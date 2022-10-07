#include <stdio.h>
#include "hashLinkList.h"

int main()
{
    HashTable ht;
    InitHashTable(ht);
    int arr[16] = {3, 5, 7, 1, 2, 9, 28, 25, 6, 11, 10, 15, 17, 23, 34, 19};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        Insert(ht, arr[i]);
    }
    Show(ht);

    Node* p;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        p = Search(ht, arr[i]);
        p == NULL ? printf("%d没有找到\n", arr[i]) : printf("%d找到了\n", arr[i]);
    }
    printf("\n");

    p = Search(ht, 100);
    p == NULL ? printf("%d没有找到\n", 100) : printf("%d找到了\n", 100);

    return 0;
}
