#include "bitTree.h"
#include <malloc.h>
#include <stdio.h>

int main()
{
    TreeNode* Tree = (TreeNode*)malloc(sizeof(TreeNode)); // 给指针初始化分配内存
    CreatBitTree(Tree);                                   // 初始化之后就为一个拥有实际值的链表
    ShowCreatBitTree(Tree);

    printf("\n先序遍历：\n");
    PreOrderRec(Tree);
    putchar('\n');
    PreOrder(Tree);

    printf("\n中序遍历：\n");
    InOrderRec(Tree);
    putchar('\n');
    InOrder(Tree);

    printf("\n后序遍历：\n");
    PostOrderRec(Tree);
    putchar('\n');
    PostOrder(Tree);

    putchar('\n');
    CreatInThread(Tree);

    return 0;
}
