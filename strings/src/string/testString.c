#include "string.h"
#include <stdio.h>

int main()
{
    String s = {"12345", 5, 10};
    String t = {"45", 2, 10};

    PrintString(s);
    PrintString(t);

    printf("%d ", IndexSimpleMatch(s, t, 2));

    return 0;
}
