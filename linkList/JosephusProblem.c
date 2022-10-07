#include <malloc.h>
#include <stdio.h>

const int N = 20;

typedef struct node
{
    int id;
    struct node* next; // 后继指针
    struct node* pre;  // 前驱指针
} Node, *pNode;

pNode RingConstuct(int n)
{
    pNode head, p, q;
    head = (pNode)malloc(sizeof(Node));
    head->id = 1;
    p = head;
    for (int i = 2; i <= n; i++)
    {
        // 循环n-1，将剩余的n-1个元素赋值，入队列
        q = (Node*)malloc(sizeof(Node));
        q->id = i;
        p->next = q;
        q->pre = p;
        p = p->next;
    }
    p->next = head;
    head->pre = p;

    return head;
}

int boundMachine(int order)
{
    // 传入报数的次数序号，返回此次报数的上限
    int bound_list[4] = {3, 5, 7, 13};
    return bound_list[(order - 1) % 4];
}

pNode count(pNode first, int bound)
{
    // 返回当前趟的起始节点，bound参数由boundMachine提供
    pNode q;
    q = first;
    for (int i = 0; i <= bound; i++)
    {
        q = q->next;
    }

    return q;
}

pNode removeNdoe(pNode currentNode)
{
    // 将节点重环中删除，并返回被删除节点的下一节点
    pNode first = currentNode->next;
    currentNode->pre->next = currentNode->next;
    first->pre = currentNode->pre;
    printf("%d ", currentNode->id);
    free(currentNode);

    return first;
}

int main()
{
    pNode first;
    pNode to_remove; // 要移除的节点
    first = RingConstuct(N);
    for (int i = 1; i < N; i++)
    {
        // 循环n-1次，删除n-1个节点
        to_remove = count(first, boundMachine(i));
        first = removeNdoe(to_remove);
    }
    printf("\n最终节点为：%d", first->id);

    return 0;
}
