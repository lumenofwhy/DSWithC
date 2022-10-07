#pragma once

// 自定义类型
typedef int ElemType;

//枚举，Link为0，Thread为1
typedef enum PointerTag
{
    Link,
    Thread
} PointerTag;

// 二叉树子节点
typedef struct _TreeNode
{
    ElemType data;
    struct _TreeNode* lchild; // 左孩子指针
    struct _TreeNode* rchild; // 右孩子指针
    PointerTag ltag;          // 标志域.当该域为0时,LChild是指向左子结点的指针.当为1时,则是指向后继结点的指针.
    PointerTag rtag;          // 标志域.当该域为0时,RChild是指向右子结点的指针.当为1时,则是指向后继结点的指针.
} TreeNode;

// 创建一个自定义二叉树以展示遍历顺序
void CreatBitTree(TreeNode*);
// 以树状形式打印二叉树
void ShowCreatBitTree(TreeNode*);
// 递归先序遍历
void PreOrderRec(TreeNode*);
// 递归中序遍历
void InOrderRec(TreeNode*);
// 递归后序遍历
void PostOrderRec(TreeNode*);
// 非递归先序遍历
void PreOrder(TreeNode*);
// 非递归中序遍历
void InOrder(TreeNode*);
// 非递归后序遍历
void PostOrder(TreeNode*);
// 中序二叉树线索化
void CreatInThread(TreeNode* T);