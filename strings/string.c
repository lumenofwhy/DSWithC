#include "string.h"
#include <stdio.h>

int IndexSimpleMatch(String S, String T, int pos)
{
    if (pos >= S.currLength)
    {
        return -1;
    }

    if (T.currLength >= (S.currLength - pos))
    {
        return -1;
    }

    // 在S串中寻找字串T
    // 在S串中起始的下标
    int i = pos;
    // 在T串中起始的下标
    int j = 0;

    while (i <= S.currLength - 1 && j <= T.currLength - 1)
    {
        if (S.data[i] == T.data[j])
        {
            i++;
            j++;
        } else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j >= T.currLength)
    {
        return i - T.currLength;
    } else
    {
        return -1;
    }
}

int IndexKMP(String S, String T, int pos)
{}

void PrintString(String S)
{
    printf("String: %s\n", S.data);
    printf("CurLen: %d\n", S.currLength);
    printf("MaxLen: %d\n", S.maxLength);
    printf("-------\n");
}
