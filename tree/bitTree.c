#include "bitTree.h"
#include <malloc.h>
#include <stdio.h>

// 二叉树线索化
static void InTread(TreeNode*, TreeNode*);

void CreatBitTree(TreeNode* T)
{
    // 创建一个二叉树实例
    //              1
    //        2           3
    //     4     5     6      7
    //   8  N  N  9   N  N  10  11
    T->data = 1;
    T->lchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->lchild->data = 2;
    T->lchild->lchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->lchild->lchild->data = 4;
    T->lchild->lchild->lchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->lchild->lchild->lchild->data = 8;
    T->lchild->lchild->lchild->lchild = NULL;
    T->lchild->lchild->lchild->rchild = NULL;
    T->lchild->lchild->rchild = NULL;
    T->lchild->rchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->lchild->rchild->data = 5;
    T->lchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->lchild->rchild->rchild->data = 9;
    T->lchild->rchild->rchild->lchild = NULL;
    T->lchild->rchild->rchild->rchild = NULL;

    T->rchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->rchild->data = 3;
    T->rchild->lchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->rchild->lchild->data = 6;
    T->rchild->lchild->lchild = NULL;
    T->rchild->lchild->rchild = NULL;
    T->rchild->rchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->rchild->rchild->data = 7;
    T->rchild->rchild->lchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->rchild->rchild->lchild->data = 10;
    T->rchild->rchild->lchild->lchild = NULL;
    T->rchild->rchild->lchild->rchild = NULL;
    T->rchild->rchild->rchild = (TreeNode*)malloc(sizeof(TreeNode));
    T->rchild->rchild->rchild->data = 11;
    T->rchild->rchild->rchild->lchild = NULL;
    T->rchild->rchild->rchild->rchild = NULL;

    return;
}

void ShowCreatBitTree(TreeNode* T)
{
    printf("\t\t\t    %-3d\n", T->data);                          // 1
    printf("\t     ---------------|----------------\n");          // 1
    printf("             %-3d ", T->lchild->data);                // 2
    printf("                           %-3d\n", T->rchild->data); // 3
    printf("    ---------|-------");                              // 2
    printf("                -------|--------\n");                 // 3
    printf("    %-3d ", T->lchild->lchild->data);                 // 4
    printf("            %-3d ", T->lchild->rchild->data);         // 5
    printf("             %-3d ", T->rchild->lchild->data);        // 6
    printf("           %-3d \n", T->rchild->rchild->data);        // 7
    printf("----|-----");                                         // 4
    printf("       ---|----");                                    // 5
    printf("        ----|---- ");                                 // 6
    printf("     ----|---- \n");                                  // 7
    printf("%-3d ", T->lchild->lchild->lchild->data);             // 8
    printf("\t N ");                                              // N
    printf("\t N ");                                              // N
    printf("\t%-3d ", T->lchild->rchild->rchild->data);           // 9
    printf("\t N ");                                              // N
    printf("\t N ");                                              // N
    printf("\t%-3d", T->rchild->rchild->lchild->data);            // 10
    printf("\t%-3d\n", T->rchild->rchild->rchild->data);          // 11

    printf("\n-----------------------\n");
    return;
}

void PreOrderRec(TreeNode* T)
{
    // 递归前序遍历
    if (T != NULL)
    {
        printf("%d ", T->data);
        PreOrderRec(T->lchild);
        PreOrderRec(T->rchild);
    }
    return;
}

void InOrderRec(TreeNode* T)
{
    // 递归中序遍历
    if (T != NULL)
    {
        InOrderRec(T->lchild);
        printf("%d ", T->data);
        InOrderRec(T->rchild);
    }
    return;
}

void PostOrderRec(TreeNode* T)
{
    // 递归后遍历
    if (T != NULL)
    {
        PostOrderRec(T->lchild);
        PostOrderRec(T->rchild);
        printf("%d ", T->data);
    }
    return;
}

void PreOrder(TreeNode* T)
{
    TreeNode* p = T;
    TreeNode* stack[30];

    int num = 0;

    while (NULL != p || num > 0)
    {
        while (NULL != p)
        {
            printf("%d ", p->data);
            stack[num++] = p;
            p = p->lchild;
        }
        num--;
        p = stack[num];
        p = p->rchild;
    }
    printf("\n");

    return;
}

void InOrder(TreeNode* T)
{
    TreeNode* p = T;
    TreeNode* stack[30];

    int num = 0;

    while (NULL != p || num > 0)
    {
        while (NULL != p)
        {
            stack[num++] = p;
            p = p->lchild;
        }
        num--;
        p = stack[num];
        printf("%d ", p->data);
        p = p->rchild;
    }
    printf("\n");

    return;
}

void PostOrder(TreeNode* T)
{
    TreeNode* p = T;
    TreeNode* stack[30];
    TreeNode* have_visited = NULL;
    int num = 0;

    while (NULL != p || num > 0)
    {
        while (NULL != p)
        {
            stack[num++] = p;
            p = p->lchild;
        }
        p = stack[num - 1];
        if (NULL == p->rchild || have_visited == p->rchild)
        {
            printf("%d ", p->data);
            num--;
            have_visited = p;
            p = NULL;
        } else
        {
            p = p->rchild;
        }
    }

    return;
}

// TODO： 修改代码
void CreatInThread(TreeNode* T)
{
    TreeNode* pre = NULL;
    if (T != NULL)
    {
        // 非空二叉树线索化
        InTread(T, pre);    // 线索化二叉树
        pre->rchild = NULL; // 处理遍历的最后一个节点
        pre->rtag = 1;
    }
}

static void InTread(TreeNode* T, TreeNode* pre)
{
    // T为当前节点，pre是刚访问的节点
    if (T != NULL)
    {
        // 递归当前节点的左子树，进行线索化
        InTread(T->lchild, pre);
        // 如果当前节点没有左孩子，左标志位设为1，左指针域指向上一节点pre
        // 左子树为空，建立前驱线索
        if (T->lchild == NULL)
        {
            T->lchild = pre;
            T->ltag = 1;
        }

        // 如果pre没有右孩子，右标志位设为1，右指针指域指向当前节点
        // 右子树为空，建立前驱节点的后继线索
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = T;
            pre->rtag = 1;
        }
        // 线索化左子树后，让pre指向当前节点
        pre = T;
        // 递归右子树进行线索化
        InTread(T->rchild, pre);
    }
}
